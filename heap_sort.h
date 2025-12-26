#ifndef HEAP_SORT_H
#define HEAP_SORT_H

void heap_sort(void* arr,
               size_t num,
               size_t size,
               int(*compar)(const void* a, const void* b)
               );

#endif // HEAP_SORT_H


