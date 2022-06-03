#include <stdio.h>
#include <malloc.h>
#define S 5

int func_sum(int x) {
    return x + x;
}

int func_power(int x) {
    return x * x;
}

void map(int* array, int size_array, int (*fptr)(int), int* new_array_ptr) {

    for (int i = 0; i < size_array; i++) {
        new_array_ptr[i] = fptr(array[i]);
    }

}

void main (void) {

    int array[S] = {1, 2, 3, 4, 5};

    int size_array = S;

    int (*fptr)(int) = func_sum;

    int* new_array_ptr = (int*)malloc(size_array * sizeof(int));

    map(array, size_array, fptr, new_array_ptr);

    for (int i = 0; i < size_array; i++) {
        printf("%d ", *(new_array_ptr + i));
    }
    printf("\n");

    /*/fptr = func_power;

    new_array_ptr = map(array, size_array, fptr);

    for (int i = 0; i < size_array; i++) {
        printf("%d ", *(new_array_ptr + i));
    }    */

}