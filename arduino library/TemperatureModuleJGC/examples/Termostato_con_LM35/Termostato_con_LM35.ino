/**
 * Sensor de Temperatura LM35
 * 
 * Adquisicion de temperatura utilizando el sensor LM35
 * incorporado al TemperatureModuleJGC y transmision al PC 
 * por puerto serie.
 *
 * Circuito:
 *  - +5v Modulo(Pin 6) ------------- +5v Arduino
 *  - +3v3 Modulo(Pin 4) ------------ +3v3 Arduino
 *  - Gnd Modulo(Pin 5) ------------- Gnd Arduino
 *  - LM35 output Modulo(Pin 3)--- A2 Arduino
 **/
#include <TemperatureModuleJGC.h>

TemperatureMod Sensor;  

void setup() {
  Serial.begin(9600);          
  Sensor.attach_LM35( A2 );  // Pin 2 de Modulo conectado a A0 Arduino
}


void loop() {

  Serial.print("Temperatura LM35: ");
  Serial.println( (double)Sensor.read_LM35() );
  
  delay(500);
  
}
