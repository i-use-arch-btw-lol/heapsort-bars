#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <ncurses.h>
#include <unistd.h>

void draw_array(double arr[], int len, int sleep) {
    clear();  // clear screen
    
    int max_height = LINES - 2;  // terminal height
    int bar_width = COLS / len;   // terminal width
    
    // find max value for scaling
    double max_val = arr[0];
    for(int i = 0; i < len; i++) {
        if(arr[i] > max_val) max_val = arr[i];
    }
    
    // draw each bar
    for(int i = 0; i < len; i++) {
        int height = (arr[i] / max_val) * max_height;
        int x = i * bar_width;
        
        for(int h = 0; h < height; h++) {
            mvprintw(LINES - 1 - h, x, "#");
        }
    }
    
    refresh();  // update screen
    usleep(sleep);  // 50ms delay so you can see it
}


inline int swap(double arr[], size_t i1, size_t i2){
	double temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
	return 0;
}
static int sift_down(double arr[], size_t i, size_t len, size_t hsize, int sleep){
    while(2*i + 1 < hsize) {
        size_t left = 2*i+1;
        size_t right = 2*i+2;
        size_t largest = i;
        
        if(arr[left] > arr[largest]) {
            largest = left;
        }
        if(right < hsize && arr[right] > arr[largest]) { 
            largest = right;
        }
        if (largest == i){
            break;
        }
        swap(arr, i, largest);
        draw_array(arr, len, sleep);
        i = largest;
    }
    return 0;
}
int heapify(double arr[], size_t len, int sleep){
    for(size_t i = len/2; i-- > 0; ){
        sift_down(arr, i, len, len, sleep);
    }
    return 0;
}
int heapsort(double arr[], size_t len, int sleep){
	draw_array(arr, len, sleep);
	if(len < 50){
	    int gap_sequence[4] = {1, 4, 10, 23};
	    for(int j = 3; j >= 0; j--){
	        for(int i = gap_sequence[j]; i < len; i++){
	    	    double temp = arr[i];
	        	int k = i;
		        while(k >= gap_sequence[j] && arr[k - gap_sequence[j]] > temp) {
		            arr[k] = arr[k - gap_sequence[j]];
		            k -= gap_sequence[j];
		        }
		        arr[k] = temp;
		        draw_array(arr, len, sleep);
	    	}
    	}
        return 0;
	}
	heapify(arr, len, sleep);
	draw_array(arr, len, sleep);
	size_t remaining = len;
	while(remaining > 0){
		swap(arr, 0, --remaining);
		draw_array(arr, len, sleep);
		sift_down(arr, 0, len, remaining, sleep);
	}
	return 0;
}
