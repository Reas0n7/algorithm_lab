#include <stdio.h>

//普通查找
int normal_search (int *array, int n, int x) {
    int i = 0;
    for (i = 0; i < n; i++) {
        if (array[i] == x) {
            return i;
        }
    }
    return -1;
}

//二分查找
int binary_search (int *array, int n, int x) {
    int left = 0;
    int right = n - 1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (array[mid] > x) {
            right = mid - 1;
        } else if (array[mid] < x) {
            left = mid + 1;
        } else {
            return mid + 1;
        }
    }
    return -1;
}