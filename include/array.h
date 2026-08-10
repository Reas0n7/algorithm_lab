#ifndef ARRAY_H
#define ARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

void traverse_array(int* array, int n);
int insert_array(int* array, int n, int pos, int value, int capacity);
int delete_array(int* array, int n, int pos);
int search_array(int* array, int n, int target);

#ifdef __cplusplus
}
#endif

#endif