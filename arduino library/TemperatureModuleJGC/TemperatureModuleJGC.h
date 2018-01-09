/**
  TemperatureSensorJGC.h - Biblioteca para controlar el Modulo de Temperatura JGC
  Desarrollado por Jose Guerra Carmenate, 26/12/2017.
  
**/


#ifndef TemperatureModuleJGC_h
#define TemperatureModuleJGC_h

#include "Arduino.h"

class Modulo_Temp_JGC{
  private:
    /*Parametros Termoresistor*/
    const static double R_lim = 27000.0; // Divisor resisitivo con RT (ohms)
    double vcc_RT;                       // Voltaje de alimentacion al RT(volts)
    
    double beta;     
    double temp_0_Kelvin;                // temperatura de referencia del resistor(Kelvin)
    double r_0;                          // resistencia a la temperatura temp_0_Kelvin
    bool   active_RT;
    int    Pin_RT;
    
    /*Parametros AD22103*/
    bool active_AD22103;
    int Pin_AD22103;
    
    /*Parametros LM35*/
    bool active_LM35;
    int  Pin_LM35;
    
  public:
    Modulo_Temp_JGC();///Constructor
    
    void attach_LM35( int Pin );
    void attach_AD22103( int Pin );
    void attach_RT( int Pin, double vcc, double beta );
    void attach_RT( int Pin, double vcc, double beta, double __temp_0, double __r_0 );

    double read_LM35();   //devuelve la temperatura (grado C) 
    double read_AD22103();//devuelve la temperatura (grado C)
    double read_RT();     //devuelve la temperatura (grado C)
    
};

#define TemperatureMod Modulo_Temp_JGC 
#endif
