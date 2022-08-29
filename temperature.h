#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <OneWire.h>

/* Code de retour de la fonction getTemperature() */
enum DS18B20_RCODES {
  READ_OK,  // Lecture ok
  NO_SENSOR_FOUND,  // Pas de capteur
  INVALID_ADDRESS,  // Adresse reçue invalide
  INVALID_SENSOR  // Capteur invalide (pas un DS18B20)
};


byte getTemperature(float *temperature, byte reset_search,  OneWire &ds);


#endif
