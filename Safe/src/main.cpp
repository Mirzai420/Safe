#include <Arduino.h>

typedef enum {
    schloss1,
    schloss2,
    schloss3,
    safe_open,
    safe_locked
} Zustand_t;

typedef enum {
    key1,
    key2,
    key3,
    input_refused,
    door_open,
    close_door
} Event_t;

Zustand_t zustand = safe_locked;

void setup() 
{
    
}

void loop() 
{
    
}

void zustand_safe(Event_t event) 
{
    
    switch (zustand) {
        case safe_locked:
            if (event == key1) {
                zustand = schloss1;
                Serial.println("Transition to schloss1");
            }
            break;
        case schloss1:
            if (event == key2) {
                zustand = schloss2;
                Serial.println("Transition to schloss2");
            }
            break;
        case schloss2:
            if (event == key3) {
                zustand = safe_open;
                Serial.println("Safe is open");
            }
            break;
        case safe_open:
            if (event == close_door) {
                zustand = safe_locked;
                Serial.println("Safe is locked");
            }
            break;
        default:
            break;
    }
}


