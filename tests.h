#include <assert.h>
#include <math.h>
#include "binary_search.h"

int int_compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int double_compare(const void* a, const void*b)
{
    const double epsilon = 1e-9;
    return fabs(*(double*)a - *(double*)b)<epsilon;
}

int char_compare(const void* a, const void* b)
{
   return *(char*)a - *(char*)b;
}

int string_compare(const void* a, const void* b)
{
    return strcmp((const char*)a, (const char*)b);
}

void tests_binary_search(){

    // search char
    char A[] = "ABCDEFGHKLMNOPQRST";
    int n = sizeof(A)/ sizeof(char);
    char key1 = 'A';
    int index = bin_search(&key1, A, n, sizeof(char), char_compare);
    assert(index == 0);

    // search int
    int B[] = { -2,  5,  6, 7, 11, 13, 15, 45, 57, 58, 67, 69, 71, 83};
    n = sizeof(B)/ sizeof(int);
    int key2 = -2;
    index = bin_search(&key2, B, n, sizeof(int), int_compare);
    assert(index == 0);

    // search double
    double C[] = {0.1, 0.4, 2.4, 3.2, 4.5, 6.6};
    double key3 = 6.6;
    index = bin_search(&key3, C, sizeof(C)/sizeof(double), sizeof(*C), double_compare);
    assert(index == 5);

    // search zero
    int Z[] = {};
    int key4 = 0;
    index = bin_search(&key4, Z, sizeof(Z)/sizeof(int), sizeof(int), int_compare);
    assert(index == -1);

    // search one element
    int One[] = {1};
    n = sizeof(One)/sizeof(int);
    int key5 = 1;
    index = bin_search(&key5, One, n, sizeof(int), int_compare);
    assert(index == 0);

    // search 100
    int arr[100];
    for(int i = 0; i< 100; i++){
        arr[i] = i;
    }
    n = sizeof(arr)/sizeof(int);
    for (int i = 0; i<100; i++){
        int key = i;
        index = bin_search(&key, arr, n, sizeof(int), int_compare);
        assert(index == i);
        key = 0;
    }

    // search strings
    char Persons[][11]= {"Andy", "Bobby", "Cindy", "Dmitry", "Elena", "Forest", "Jimmy", "Klaus", "Larry"};
    int size = sizeof(Persons[0]);
    int num = sizeof(Persons) / size;

    char key[] = "Bobby";
    index = bin_search(key, Persons, num, size, string_compare);
    assert(index == 1);

    printf("Test is completed!\n");

}

