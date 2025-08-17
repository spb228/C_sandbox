#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char make[32];
    char model[32];  
    uint16_t year;
} car_t;

car_t* car_new_alloc(); // new memory allocater
void car_ctor(car_t*, char*, char*, uint16_t year); // car ctor
void car_dtor(car_t*); // car destroyer
void car_turn_on(car_t*);
void car_turn_off(car_t*);