#include <string.h>
#include <stdlib.h>
#include "heap_sort.h"

void swap_val(void* arr, size_t size, size_t first, size_t second)
{
    void* temp_ptr = malloc(sizeof(size));
    if(!temp_ptr) exit(1);

    memcpy(temp_ptr, arr + first*size, size );
    memcpy(arr + first*size, arr + second*size, size);
    memcpy(arr + second*size, temp_ptr, size);

    free(temp_ptr);
}

//
// Heap sort
//
void heapify(void* arr,
             size_t num,
             size_t size,
             size_t upper,
             int(*compar)(const void* a, const void* b)
             )
{
    size_t left = 2 * upper + 1 ,
           right = 2 * upper + 2;
    size_t bigger = upper;
    if(left < num){
       if((compar(arr + left*size, arr + bigger*size)) > 0)
           bigger = left;
    }

    if(right < num){
        if((compar(arr + right*size, arr + bigger*size)) > 0)
            bigger = right;
    }
     if(bigger!= upper){
        swap_val(arr, size, upper, bigger);

        // recursion
        heapify(arr, num, size, bigger, compar);
    }
}

void heap_sort(void* arr,
               size_t num,
               size_t size,
               int(*compar)(const void* a, const void* b)
               )
{
    for(int i = num/2 - 1; i >= 0; --i)
        heapify(arr, num, size, i, compar);

    for(int i = num - 1; i >= 0; --i)
    {
        swap_val(arr, size, i, 0);
        heapify(arr, i, size, 0, compar);
    }
}
