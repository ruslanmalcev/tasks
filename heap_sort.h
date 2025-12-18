#include <stdbool.h>
#ifndef HEAP_SORT_H
#define HEAP_SORT_H

void swap_val(void* arr, size_t size, size_t first, size_t second);
void heapify(void* arr,
             size_t num,
             size_t size,
             size_t upper,
             int(*compar)(const void* a, const void* b)
             );
void heap_sort(void* arr,
               size_t num,
               size_t size,
               int(*compar)(const void* a, const void* b)
               );
bool is_sorted(const void* arr, size_t num_elements, size_t element_size, int (*compar)(const void* a, const void* b));

#endif // HEAP_SORT_H
