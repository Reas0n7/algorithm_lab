#ifndef SORT_H
#define SORT_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

int *rand_array (int n, int min, int max);
void print_array (int *array, int n);
bool is_sort(int *array, int n);
void bubble_sort(int* array, int n);
void selection_sort(int *array, int n);
void insertion_sort(int *array, int n);
void merge(int *array, int left, int mid, int right);
void merge_sort(int *array, int left, int right);
int partition(int *array, int left, int right);
void quick_sort(int *array, int left, int right);

#ifdef __cplusplus
}
#endif

#endif