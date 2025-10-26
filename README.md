### heapsort_bars
- a terribly implemented C heapsort for... idk, nothing? ;)
## FUNCTIONS THAT YOU USE
- int heapsort(double arr[], size_t len)
## SYNOPSIS
Heapsort is an unstable (like my brain) sorting algorithm usually used as a consistent fallback algorithm in cases that quicksort is hitting asymptotic O(n^2) performance. It works by turning the array into an in-place heap and using this to pretty much make selection sort but more big brain. This implementation uses a Ciura-sequence shellsort for all arrays less than 50 elements, and is probably going to achieve better performance than heapsort on small arrays anyway.
## HIDDEN STUFF
- int heapify(double arr[], size_t len)
- this is the heapify function which turns everything from index 0 to len-1 into an in-place heap. I really don't know why you'd want to use it but if you do just remove the static. That's it.
- int swap(double arr[], size_t i1, size_t i2);
- I imagine this'll be useful for other sorts! Definitely not forshadowing. btw i1 and i2 are 0-based so to swap elements 0 and 1 i1=0 and i2=1.
## LICENSE
- LGPL v2.1 (I rolled some dice, alright?)
## CONTRIBUTING
- if you want to add sorting algorithms, go for it. We stop when we reach a fully optimal blocksort and have defeated all other sorting algorithms with it.
## COMPILING
- gcc -o heapsort sort.c main.c
- just don't use any optimizations, it makes it slower. Why? NOBODY KNOWS.
## PERFORMANCE
- beats qsort() by 0.04 milliseconds
- aggressive optimiztion makes it slower, as said above. :(
- flags: none. Don't be fancy
- don't use clang, ~35% slower than GCC
## FAQ
- Why did you make this?
	- ¯\_(ツ)_/¯
- Can I use this in prod?
	- if you want to watch bars go brrr, then yes.
- Can I contribute?
	- sure, why not. Our eventual goal is blocksort
 
