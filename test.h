#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int int_up_compare(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}

int int_down_compare(const void* a, const void* b)
{
    return *(int*)a < *(int*)b;
}

int double_up_compare(const void* a, const void*b)
{
     return  *(double*)a > *(double*)b;
}

int char_up_compare(const void* a, const void* b)
{
    return *(char*)a > *(char*)b;
}

int string_compare(const void* a, const void* b)
{
    return  strcmp((const char*)a, (const char*)b);
}

void test_heap_sort(){

    // sort int
    int A[] = { 5, 2, 2,  -3, 2,  171, 93};
    heap_sort(A, sizeof(A)/sizeof(int), sizeof(int), int_up_compare);
    assert(is_sorted(A, sizeof(A)/sizeof(*A), sizeof(*A), int_up_compare));
    puts("ok");

    // sort double
    double D[] = {4.3, 5.8, 9.1, 1.4, -8.4};

    heap_sort(D, sizeof(D)/sizeof(double), sizeof(double), double_up_compare);
    assert(is_sorted(D, sizeof(D)/sizeof(*D), sizeof(*D), double_up_compare));
    puts("ok");

    // sort char
    char Sent[] = {'a', 'R', 'B', 's', 'T', 'o', 'I'};
    heap_sort(Sent, sizeof(Sent)/sizeof(char), sizeof(char), char_up_compare);
    assert(is_sorted(Sent, sizeof(Sent)/sizeof(*Sent), sizeof(*Sent), char_up_compare));
    puts("ok");

    // sort string
    char Persons[][11] = {"Jonson", "Stivenson", "Karlson", "Grivenson", "Karter", "Washington", "Raigan", "Obama"};
    heap_sort(Persons, sizeof(Persons)/sizeof(char), sizeof(char), string_compare);
    assert(is_sorted(Persons, sizeof(Persons)/sizeof(*Persons), sizeof(*Persons), string_compare));
    puts("ok");

}

void random_test(){
    printf("Test random sort:\n");
    srand(time(NULL));
    for (int test_num = 0; test_num < 12; test_num++) {
        int size = rand()%1000-0;
        int *arr = malloc(size * sizeof(int));
        if (arr == NULL) {
            printf("Test %d: length %d\n", test_num+1, size);
            continue;
        }
        for (int i = 0; i < size; i++) {
            arr[i] = rand()%100-100;
        }

        printf("Test %d: length %d\n", test_num + 1, size);
        heap_sort(arr, sizeof(arr)/sizeof(int), sizeof(int), int_up_compare);
        assert(is_sorted(arr, sizeof(arr)/sizeof(int), sizeof(int), int_up_compare));
        free(arr);
    }

    puts("Test is completed!");

}



