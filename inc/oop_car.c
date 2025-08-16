#include "oop_car.h"

// TODO Implement car turn on/off and engine

car_t* car_new_alloc()
{
    return (car_t*)(malloc(sizeof(car_t))); 
}

void car_ctor(car_t* car)
{
    printf("Constructing car object...\n");
}

void car_dtor(car_t* car)
{
    printf("Destructing car object...\n");
    free(car);
}

