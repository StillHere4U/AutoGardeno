

#include <LowPower.h>
#include <SoftwareSerial.h>
#include <OneWire.h>

// Include defines
#include "defines.h"

// Include Tools
#include "sleeper.h"
#include "temperature.h"



// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED, OUTPUT);
 }


// the loop function runs over and over again forever
void loop() {
  /* Création de l'objet OneWire pour manipuler le bus 1-Wire */
  OneWire ds(BROCHE_ONEWIRE);
  /* Declaration des ports (Rx, Tx) du module bluetooth */
  SoftwareSerial bluetooth(RX_BLUE,TX_BLUE);
  Serial.begin(9600); 
  bluetooth.begin(9600);
  while(1) {
    // Read moisture
    float moisture = (float(analogRead(SOIL_PIN))/1023.0)*5;
    float temperature = 0;
  
    // Lit la température ambiante à ~1Hz 
    if (getTemperature(&temperature, true, ds) != READ_OK) {
        Serial.println(F("Erreur de lecture du capteur"));
    }
    
    // Print bluetooth
    
    bluetooth.print("Soil Moisture  : ");
    bluetooth.print(moisture);
    bluetooth.println(" V");
    bluetooth.print("Temperature   : ");
    bluetooth.print(temperature);
    bluetooth.println(" °C");  
  
    // Print serial COM3
    Serial.print("Soil Moisture   : ");
    Serial.print(moisture);
    Serial.println(" V");
    Serial.print("Temperature     : ");
    Serial.print(temperature);
    Serial.println(" °C");  
  
    // Delay for serial buffer
    delay(100);
    digitalWrite(LED,HIGH);
    //Sleep for a minute
    arduinoSleepSec(2); 
    digitalWrite(LED,LOW);

  }
}
