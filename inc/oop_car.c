#include "oop_car.h"

// TODO Implement car turn on/off and engine

car_t* car_new_alloc()
{
    return (car_t*)(malloc(sizeof(car_t))); 
}

void car_ctor(car_t* car, char* make, char* model, uint16_t year)
{
    printf("Constructing car object...\n");

    strncpy(car->make, make, sizeof(car->make - 1));
    car->make[sizeof(car->make) - 1] = '\0';

    strncpy(car->model, model, sizeof(car->model - 1));
    car->model[sizeof(car->model) - 1] = '\0';

    car->year = year;
}

void car_dtor(car_t* car)
{
    printf("Destructing car object...\n");
    free(car);
}

