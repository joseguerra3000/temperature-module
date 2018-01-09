/**
 * Sensores de Temperatura AD22103 y resistivo
 * 
 * Comparacion de temperaturas en un termoresistor
 * y AD22103 incorporados al TemperatureModuleJGC y 
 * transmision al PC por puerto serie.
 *
 * Circuito:
 *  - +5v Modulo(Pin 6) ------------- +5v Arduino
 *  - +3v3 Modulo(Pin 4) ------------ +3v3 Arduino
 *  - Gnd Modulo(Pin 5) ------------- Gnd Arduino
 *  - RT output Modulo(Pin 1)-------- A1 Arduino
 *  - AD22103 output Modulo(Pin 2) -- A2 Arduino
 **/
#include <TemperatureModuleJGC.h>
const double Vcc_termo = 5;
const double Beta_termistor = 3977;

TemperatureMod Sensor;  

void setup() {
  Serial.begin(9600);          
  Sensor.attach_RT( A1, Vcc_termo, Beta_termistor );  // Pin 2 de Modulo conectado a A0 Arduino
  Sensor.attach_AD22103( A2 );
}

void loop() {

  Serial.print("RT: ");
  double tempRT = (double)Sensor.read_RT() - 273.15;
  Serial.print( tempRT );
  
  Serial.print( "| AD22103: " );
  double tempAD22103 = Sensor.read_AD22103();
  Serial.print( tempAD22103 );
  
  Serial.print( "| Diferencia: " );
  Serial.println( abs(tempAD22103 - tempRT) );
  
  
  
  delay(500);
  
}
