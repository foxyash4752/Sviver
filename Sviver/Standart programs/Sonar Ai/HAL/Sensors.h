#ifndef SENSORS_H
#define SENSORS_H

#include "../Config/Config.h"

#ifdef PLATFORM_SVIVER
    #include "../Platform/Sviver/Sensors_silver.h"
#elif defined(PLATFORM_ARDUINO)
    #include "../Platform/Arduino/Sensors_arduino.h"
#endif

// Универсальный API
float sensor_get_distance(void);

#endif