#include "sort_int.h"
#include <stdio.h>
#include <stdlib.h>
#define TEST_DATA_CNT 1000000

//swap
void SWAP_INT(int *x, int *y){
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

//quickSort
int partition_int(int *number, int left, int right){
    int i=left-1;
    int j;

    for(j=left;j<right;j++) {
        if(number[j]<=number[right]) {
            i++;
            SWAP_INT(&number[i], &number[j]);
        }
    }
    SWAP_INT(&number[i+1], &number[right]);
    return i+1;
}

void quickSort_int(int *number, int left, int right){
    if(left<right) {
        int q = partition_int(number, left, right);
        quickSort_int(number, left, q-1);
        quickSort_int(number, q+1, right);
    }
}

//merge sort
void merge_int(int *number, int head, int mid, int tail){
    int lenA = mid - head + 1;
    int lenB = tail - (mid + 1) + 1;
    int *A, *B;
    int i,j,k;

    A = (int *) malloc(sizeof(int)*lenA);
    B = (int *) malloc(sizeof(int)*lenB);
    for(i=0;i<lenA;i++){
        A[i] = number[head+i];
    }
    for(j=0;j<lenB;j++){
        B[j] = number[mid+1+j];
    }
    i = 0;
    j = 0;
    k = head;
    while(i<lenA && j<lenB){
        if(A[i]<B[j]){
            number[k++] = A[i++];
        }
        else{
            number[k++] = B[j++];
        }
    }
    while(i<lenA){
        number[k++] = A[i++];
    }
    while(j<lenB){
        number[k++] = B[j++];
    }
    free(A);
    free(B);
}

void mergeSort_int(int *number, int head, int tail){
    if(head<tail){
        int mid = (head+tail)/2;
        mergeSort_int(number, head, mid);
        mergeSort_int(number, mid+1, tail);
        merge_int(number, head, mid, tail);
    }
}

//heap sort
void heapify_int(int *number, int n, int i){
    int largest = i; //Initialize largest as root
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && number[l]>number[largest]){
        largest = l;
    }
    if(r<n && number[r]>number[largest]){
        largest = r;
    }
    //If largest is not root
    if(largest!=i){
        SWAP_INT(&number[i],&number[largest]);
        heapify_int(number, n, largest); //Recursively heapify the affected sub-tree
    }
}

void heapSort_int(int *number, int n){
    int i;
    //Build heap
    for(i=n/2-1;i>=0;i--){
        heapify_int(number, n, i);
    }
    //One by one extract an element from heap
    for(i=n-1;i>0;i--){
        SWAP_INT(&number[0], &number[i]);
        heapify_int(number, i, 0);
    }
}

//radix sort
int get_max_int(int *number, int n){
    int max,i;
    max = number[0];
    for(i=1;i<n;i++){
        if(number[i] > max){
            max = number[i];
        }
    }
    return max;
}

void radixSort_int(int *number, int n){
    int **bucket, *bucket_cnt;
    int i,j,k,r,NOP=0,divisor=1,lar,pass;

    bucket = (int **) malloc(sizeof(int*)*10);
    for(i=0;i<10;i++){
        bucket[i] = (int *) malloc(sizeof(int)*TEST_DATA_CNT);
    }
    bucket_cnt = (int *) malloc(sizeof(int)*TEST_DATA_CNT);
    lar = get_max_int(number, n);
    while(lar > 0){
        NOP++;
        lar /= 10;
    }
    for(pass=0;pass<NOP;pass++){
        for(i=0;i<TEST_DATA_CNT;i++){
            bucket_cnt[i] = 0;
        }
        for(i=0;i<n;i++){
            r = (number[i] / divisor) % 10;
            bucket[r][bucket_cnt[r]] = number[i];
            bucket_cnt[r] += 1;
        }
        i=0;
        for(k=0;k<10;k++){
            for(j=0;j<bucket_cnt[k];j++){
                number[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;
    }
    free(bucket_cnt);
    for(i=0;i<10;i++){
        free(bucket[i]);
    }
    free(bucket);
}
