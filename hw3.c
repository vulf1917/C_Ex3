#include <stdio.h>
#include "hw3.h"
#define ARR_SIZE 50
/*
 * hw3.c
 *
 *  Created on: dec 13, 2019
 *      Author: semen
 */

static int unsorted[ARR_SIZE]={0};

void printArr(int *arr, int size) {

    for (int i = 0; i < size; i++) {
        printf("%d,", *(arr + i)); //print the arr[i]
    }

}




void swap(int *pa, int *pb)
{
    int temp = *pa; // copy tha value of a to temp
    *pa = *pb;// put the value of b to a
    *pb  = temp;    // put the value of temp to b
}



void shift_element(int* arr, int i) {// move from the end to start and move evry elemnt to one possition to the right
    for(int j = i ; j>=0 ; j--) {
        *(arr+1+j)=*(arr+j);
    }
}




void insertion_sort(int *arr , int len)
{
    for (int i =0 ; i< len-1 ; i++ ) {
        int j = i;
        while((*(arr+i+1)<*(arr+j))&&(j>=0)) {j--;} // find j -> the current place to put arr[i+1]
        if(j!=i) {
            j++;
            int temp = *(arr+i+1); // save the elemnt to insert
            shift_element(arr+j,(i-j)); // shift all the elemnt's right
            *(arr+j)=temp;

        }
    }
}






void mainSort(){

for(int i =0 ; i < 50 ; i++ ) {
int temp =0;
scanf("%d",&temp);
unsorted[i]=temp;
}
insertion_sort(unsorted,50);
printArr(unsorted,50); // print the sorted arr
}










