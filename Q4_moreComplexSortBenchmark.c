#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SWAP(x,y) {int t; t = x; x = y; y = t;} 


void quickSort(int number[], int left, int right) { 
    if(left < right) { 
        int s = number[(left+right)/2]; 
        int i = left - 1; 
        int j = right + 1; 

        while(1) { 
            while(number[++i] < s) ;   
            while(number[--j] > s) ;   
            if(i >= j) 
                break; 
            SWAP(number[i], number[j]);  
        } 

        quickSort(number, left, i-1);   
        quickSort(number, j+1, right);  
    } 
}

int main(){
 

    int size = 500000;

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        perror("Failed to allocate memory for array");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < size; i++){
        arr[i] = rand() % size + 1;
    }

    quickSort(arr, 0, size-1);

    free(arr);
    arr = NULL;

    return 0; 

}

