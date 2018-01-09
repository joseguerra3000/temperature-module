#include "Arduino.h"
#include "TemperatureModuleJGC.h"


Modulo_Temp_JGC::Modulo_Temp_JGC(){///Constructor
  active_LM35 = false;
  active_AD22103 = false;
  active_RT = false;
}

void Modulo_Temp_JGC::attach_LM35( int Pin ){
  active_LM35 = true;
  Pin_LM35 = Pin;
}

void Modulo_Temp_JGC::attach_AD22103( int Pin ){
  active_AD22103 = true;
  Pin_AD22103 = Pin;
}
    
void Modulo_Temp_JGC::attach_RT( int Pin, double vcc, double _beta ){
  active_RT = true;
  Pin_RT = Pin;
  vcc_RT = vcc;
  beta = _beta;
  temp_0_Kelvin = 298.15;
  r_0  = 10000.0;
}
void Modulo_Temp_JGC::attach_RT( int Pin, double vcc, double _beta, double __temp_0_Kelvin, double __r_0 ){
  active_RT = true;
  Pin_RT = Pin;
  vcc_RT = vcc;
  beta = _beta;
  temp_0_Kelvin = __temp_0_Kelvin;
  r_0  = __r_0;
}

double Modulo_Temp_JGC::read_LM35(){
  if( !active_LM35 )
    return -100.0;
  return ( analogRead(Pin_LM35)*500 )*1.0/1024.0;
}
    
double Modulo_Temp_JGC::read_AD22103(){
  if( !active_AD22103 )
    return -100.0;
  return  (double)178.570*analogRead(Pin_AD22103)/1024.0 - 8.92857;
}

double Modulo_Temp_JGC::read_RT(){ ///  hay que estudiar como obtener la temperatura de la RT
  if( !active_RT )
    return -100.0;
  //return analogRead(Pin_RT);
  double v_out = (double)analogRead(Pin_RT)*vcc_RT/1024.0;
  double r_ntc = R_lim*( (double)vcc_RT/v_out - 1 );
  
  return 1.0/( ((double)log(r_ntc/r_0)/beta)+1.0/temp_0_Kelvin );
}


