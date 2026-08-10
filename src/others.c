#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "sort.h"

//欧几里得算法
int Euclid(int n, int m)
{
    int r = 0;
    while (m > 0) { 
        r = n % m;
        n = m;
        m = r;
    }
    return n;
}

//汉诺塔
void Move(char source, char target)
{
    printf("Move disk from %c to %c\n", source, target);
}

void Hanoi(int n, char source, char target, char auxiliary)
{
    if (n <= 0) {
        return;
    }
    if (n == 1) {
        Move(source, target);
    } else {
        Hanoi(n - 1, source, auxiliary, target);
        Move(source, target);
        Hanoi(n - 1, auxiliary, target, source);
    }
}

//幂
int power(int a, int n)
{
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 1;
    }
    int half = power(a, n / 2);
    return (n % 2 == 0) ? half * half : half * half * a;
}

//最小距离
double distance(int *x, int *y, int i, int j)
{
        int dx = x[i] - x[j]; 
        int dy = y[i] - y[j];
        return sqrt((double)dx * dx + (double)dy * dy);
}

double min_distance_below_three_points(int *x, int *y, int left, int right)
{
    double min_distance = FLT_MAX;
    for (int i = left; i < right; i++) {
        for (int j = i + 1; j <= right; j++) {
            if (min_distance > distance(x, y, i, j)) {
                min_distance = distance(x, y, i, j);
            }
        }
    }
    return min_distance;
}

void sort_by_x(int *x, int *y, int left, int right)
{
    if (left > right) {
        return;
    }
    for (int i = left + 1; i <= right; i++) {
        int key_x = x[i];
        int key_y = y[i];
        int j = i - 1;
        while (j >= left && x[j] > key_x) {
            x[j + 1] = x[j];
            y[j + 1] = y[j];
            j--;
        }
        x[j + 1] = key_x;
        y[j + 1] = key_y;
    }
}

double strip_closest(int *x, int *y, int left, int mid, int right, double d)
{
    int n = right - left + 1;
    int *strip = (int*)malloc(n * sizeof(int));
    int count = 0;
    int mid_x = x[mid];
    for (int i = left; i <= right; i++) {
        if (abs(x[i] - mid_x) < d) {
            strip[count++] = i;
        }
    }
    if (count < 2) {
        free(strip);
        return d;
    }
    for (int i = 1; i < count; i++) {
        int key_idx = strip[i];
        int key_y = y[key_idx];
        int j = i - 1;
        while (j >= 0 && y[strip[j]] > key_y) {
            strip[j + 1] = strip[j];
            j--;
        }
        strip[j + 1] = key_idx;
    }
    double mid_d = d;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count && (y[strip[j]] - y[strip[i]]) < mid_d; j++) {
            if (mid_d > distance(x, y, strip[i], strip[j])) {
                mid_d = distance(x, y, strip[i], strip[j]);
            }
        }
    }
    free(strip);
    return mid_d;
}

double closet_util(int *x, int *y, int left, int right)
{
    int n = right - left + 1;
    if (n <= 3) {
        return min_distance_below_three_points(x, y, left, right);
    }
    int mid = left + n / 2;
    double d_left = closet_util(x, y, left, mid);
    double d_right = closet_util(x, y, mid + 1, right);
    double d = (d_left < d_right) ? d_left : d_right;
    double d_strip = strip_closest(x, y, left, mid, right, d);
    return (d < d_strip) ? d : d_strip;
}

double MinDistance(int *x, int *y, int left, int right)
{
    int n = right - left + 1;
    if (n < 2) {
        return FLT_MAX;
    }
    sort_by_x(x, y, left, right);
    return closet_util(x, y, left, right);
}


