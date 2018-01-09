/**
 * Sensor de Temperatura AD22103
 * 
 * Adquisicion de temperatura utilizando el sensor AD22103
 * incorporado al TemperatureModuleJGC y transmision al PC 
 * por puerto serie.
 *
 * Circuito:
 *  - +5v Modulo(Pin 6) ------------- +5v Arduino
 *  - +3v3 Modulo(Pin 4) ------------ +3v3 Arduino
 *  - Gnd Modulo(Pin 5) ------------- Gnd Arduino
 *  - AD22103 output Modulo(Pin 2)--- A0 Arduino
 **/
#include <TemperatureModuleJGC.h>

TemperatureMod Sensor;  

void setup() {
  Serial.begin(9600);          
  Sensor.attach_AD22103( A0 );  // Pin 2 de Modulo conectado a A0 Arduino
}


void loop() {

  Serial.print("Temperatura AD22103: ");
  Serial.println( (double)Sensor.read_AD22103() );
  
  delay(500);
  
}
