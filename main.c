#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include "sort.h"
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void shuffle(double arr[], size_t len){
    for (size_t i = len - 1; i > 0; i--) {
        size_t j = rand() % (i + 1);
        swap(arr, i, j);
    }
}
int main(int argc, char *argv[]){
    long size = (argc > 1)?strtol(argv[1], NULL, 10):100;
    if (size <= 0 || size > 1000000) {
        printf("invalid size! :(");
        exit(1);
    }
    int arr_size = (int)size;
    double* arr = malloc(arr_size*sizeof(double));
    if(arr == NULL){
        printf("malloc failed");
        exit(1);
    }
    long sleep = (argc > 2)?strtol(argv[2], NULL, 10):9999;
    if(sleep <= 0 || sleep > 100000) {
        printf("Invalid sleep time! :(");
        free(arr);
        exit(1);
    }
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    srand(time(NULL));
    //init arr
    for(int i = 0; i < arr_size; i++){
        arr[i] = i+1;
    }
    while(1){
        shuffle(arr, arr_size);
        heapsort(arr, arr_size, sleep);
        if(getch() == 'q'){
            break;
        }
    }
    endwin();
    free(arr);
    return 0;
}
