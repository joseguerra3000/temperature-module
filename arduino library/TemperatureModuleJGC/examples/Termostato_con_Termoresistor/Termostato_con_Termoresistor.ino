/**
 * Sensor de Temperatura resistivo
 * 
 * Adquisicion de temperatura utilizando un termoresistor
 * como sensor incorporado al TemperatureModuleJGC y 
 * transmision al PC por puerto serie.
 *
 * Circuito:
 *  - +5v Modulo(Pin 6) ------------- +5v Arduino
 *  - +3v3 Modulo(Pin 4) ------------ +3v3 Arduino
 *  - Gnd Modulo(Pin 5) ------------- Gnd Arduino
 *  - RT output Modulo(Pin 1)--- A1 Arduino
 **/
#include <TemperatureModuleJGC.h>
const int Vcc_termo = 5;
const double Beta_termistor = 3977;

TemperatureMod Sensor;  

void setup() {
  Serial.begin(9600);          
  Sensor.attach_RT( A1, Vcc_termo, Beta_termistor );  // Pin 2 de Modulo conectado a A0 Arduino
}

void loop() {

  Serial.print("Temperatura RT(C): ");
  double temp = (double)Sensor.read_RT();
  Serial.println( temp - 273,15 );
  
  delay(500);
  
}
