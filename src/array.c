#include <stdio.h>

void traverse_array(int* array, int n)
{
    if (!array) {
        printf("the array is empty!");
        return;
    }
    printf("tarversal result:\n");
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int insert_array(int* array, int n, int pos, int value, int capacity)
{
    if (n >= capacity) {
        printf("the array is full and cannot insert\n");
        return -1;
    }
    if (pos > n || pos < 0) {
        printf("invalid insertion position\n");
        return -1;
    }
    for (int i = n; i > pos; i--) {
        array[i] = array[i - 1];
    }
    array[pos] = value;
    return n + 1;
}

int delete_array(int* array, int n, int pos)
{
    if (pos < 0 || pos > n) {
        printf("the array is empty, deletion is not possible\n");
        return -1;
    }
    for (int i = pos; i < n; i++) {
        array[i] = array[i + 1];
    }
    return n - 1;
}

int search_array(int* array, int n, int target)
{
    for (int i = 0; i < n; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}







