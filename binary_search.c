#include <string.h>
#include "binary_search.h"

int bin_search(const void* key,
               const void* arr,
               size_t num,
               size_t size,
               int(*compar)(const void* a, const void* b)
               ){
    size_t left = 0;
    size_t right = num;
    size_t center;

    int differ = 0;
    while((right - left) >1) {

        center = (left + right) / 2;
        differ = compar(key, arr + center*size);
        if(differ > 0)
            left = center;
        else if(differ < 0)
            right = center;
        else return center;

    }
    if (compar(key, arr + left*size)  == 0) return left;
    return -1;
}
