#include "../inc/file.h"
#include "../inc/oop_car.h"

int main(void)
{
    printf("starting main...\n");

    car_t* swap_corolla;
    car_ctor(swap_corolla);
    car_dtor(swap_corolla);

    return 0;
}


/* Old Test Code */

// int* int_p = intPtr();
// printf("value of int is %d\n", *int_p);

// // free memory and remove dangling pointer
// free(int_p);
// int_p = NULL;

// int* intPtr(void)
// {
//     int* var_p = (int *)malloc(sizeof(int) * 100000000);

//     if (!var_p)
//     {
//         fprintf(stderr, "Fatal error: memory allocation failed.\n");
//         exit(EXIT_FAILURE);
//     }

//     *var_p = 10; 

//     return var_p; 
// }