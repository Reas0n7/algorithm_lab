/**
 * gcc -Wall -g -I include test/test.c src/sort.c src/search.c src/others.c src/linked_list.c -o test.exe
 * gcc -Wall -g -I include test/test.c src/stack.c -o test.exe
 * gcc -Wall -g -I include test/test.c src\*.c -o test.exe
 * .\test.exe
 * build
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"
#include "others.h"
#include "search.h"
#include "linked_list.h"
#include "stack.h"

/*
int main()
{
    srand((unsigned)time(NULL));
    int* a = rand_array(10, 1, 20);
    print_array(a, 10);
    int* b = rand_array(10, 1, 20);
    print_array(b, 10);
    printf("the min distance is: %lf", MinDistance(a, b, 0, 9));
    return 0;
}
*/


int main()
{
    Link_Stack *s = link_stack_create(); 
    link_stack_push(s, 9);
    link_stack_push(s, 6);
    link_stack_push(s, 5);
    link_stack_push(s, 4);
    link_stack_push(s, 3);
    link_stack_push(s, 2);
    link_stack_traverse(s);
    int out = 0;
    link_stack_pop(s, &out);
    printf("out: %d\n", out);
    link_stack_traverse(s);
    link_stack_destroy(s);
    s = NULL;
    link_stack_traverse(s);
    return 0;
}