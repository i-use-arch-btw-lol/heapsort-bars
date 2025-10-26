#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
int swap(double arr[], size_t i1, size_t i2);
int heapify(double arr[], size_t len, int sleep);
int heapsort(double arr[], size_t len, int sleep); //heapsort
void draw_array(double arr[], int len, int sleep);
#endif
