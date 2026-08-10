#ifndef OTHERS_H
#define OTHERS_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

int Euclid(int n, int m);
void Move(char source, char target);
void Hanoi(int n, char source, char target, char auxiliary);
int power(int a, int n);
double distance (int *x, int *y, int i, int j) ;
double min_distance_below_three_points(int *x, int *y, int left, int right);
void sort_by_x(int *x, int *y, int left, int right);
double strip_closest(int *x, int *y, int left, int mid, int right, double d);
double closeet_util(int *x, int *y, int left, int right);
double MinDistance(int *x, int *y, int left, int right);

#ifdef __cplusplus
}
#endif

#endif