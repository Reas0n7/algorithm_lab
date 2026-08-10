#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//[min, max]
int* rand_array(int n, int min, int max)
{
    if (max <= min || n <= 0) {
        return NULL;
    }
    int *a = malloc(n * sizeof(int));
    if (a == NULL) {
        perror("malloc failed");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        a[i] = rand() % (max - min + 1)  + min;
    }
    return a;
}

void print_array(int *array, int n)
{
    if (!array) {
        printf("the array is empty!");
        return;
    }
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ",array[i]);
    }
    printf("]\n");
}

bool is_sort(int *array, int n)
{
    for (int i = 0; i < n - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

//冒泡排序          
void bubble_sort(int *array, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j + 1] < array[j]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
    return;
}

//选择排序
void selection_sort(int *array, int n)
{
    for (int i = 0; i < n; i++) {
        int min = array[i];
        for (int j = i + 1; j < n; j++) {
            if (min > array[j]) {
                int tmp = min;
                min = array[j];
                array[j] = tmp;
            }
        }
        array[i] = min;
    }
    return;
}

//插入排序
void insertion_sort(int *array, int n)
{
     for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
     }
     return;
}

//归并排序
void merge(int *array, int left, int mid, int right)
{
    int nl = mid - left + 1;
    int nr = right - mid;
    int *L = (int*)malloc(nl * sizeof(int));
    if (L == NULL) {
        perror("malloc failed");
        return;
    }
    int *R = (int*)malloc(nr * sizeof(int));
    if (R == NULL) {
        perror("malloc failed");
        return;
    }
    for (int i = 0; i < nl; i++) {
        L[i] = array[left + i];
    }
    for (int i = 0; i < nr; i++) {
        R[i] = array[mid + i + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < nl && j < nr) {
        if (L[i] <= R[j]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }
    while (i < nl) {
        array[k++] = L[i++];
    }
    while (j < nr) {
        array[k++] = R[j++];
    }
    free(L);
    free(R);
}

void merge_sort(int *array, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

//快速排序
int partition(int *array, int left, int right)
{
    int pivot = array[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (array[j] < pivot) {
            i++;
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    int tmp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = tmp;
    return i + 1;
}

void quick_sort(int *array, int left, int right)
{
    if (right > left) {
        int pivot = partition(array, left, right);
        quick_sort(array, left, pivot - 1);
        quick_sort(array, pivot + 1, right);
    }
}

