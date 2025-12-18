#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

int bin_search(const void* key, const void* arr, size_t num, size_t size, int (*compar)(const void* a, const void* b));

#endif
