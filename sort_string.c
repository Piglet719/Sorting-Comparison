#include "sort_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_LEN 100

//swap
void SWAP_STRING(char *a,char *b){
    char *tmp = (char *) malloc(sizeof(char)*STRING_LEN);
    strcpy(tmp,a);
    strcpy(a,b);
    strcpy(b,tmp);
    free(tmp);
}

//quickSort
int partition_string(char **text, int left, int right){
    int i=left-1;
    int j;

    for(j=left;j<right;j++) {
        if(strcmp(*(text+j),*(text+right))<=0){
            i++;
            SWAP_STRING(*(text+i), *(text+j));
        }
    }
    SWAP_STRING(*(text+i+1), *(text+right));
    return i+1;
}

void quickSort_string(char **text, int left, int right){
    if(left<right) {
        int q = partition_string(text, left, right);
        quickSort_string(text, left, q-1);
        quickSort_string(text, q+1, right);
    }
}

//mergeSort
void merge_string(char **text, int head, int mid, int tail){
    int lenA = mid-head+1;
    int lenB = tail-(mid+1)+1;
    char **A, **B;
    int i,j,k;

    A = (char **) malloc(sizeof(char *)*lenA);
    B = (char **) malloc(sizeof(char *)*lenB);
    for(i=0;i<lenA;i++){
        A[i] = (char *) malloc(sizeof(char)*STRING_LEN);
        strcpy(A[i],text[head+i]);
    }
    for(j=0;j<lenB;j++){
        B[j] = (char *) malloc(sizeof(char)*STRING_LEN);
        strcpy(B[j],text[mid+1+j]);
    }
    i=0;
    j=0;
    k=head;
    while(i<lenA && j<lenB){
        if(strcmp(A[i],B[j])<0){
            strcpy(text[k++],A[i++]);
        }
        else{
            strcpy(text[k++],B[j++]);
        }
    }
    while(i<lenA){
        strcpy(text[k++],A[i++]);
    }
    while(j<lenB){
        strcpy(text[k++],B[j++]);
    }
    for(i=0;i<lenA;i++){
        free(A[i]);
    }
    free(A);
    for(i=0;i<lenB;i++){
        free(B[i]);
    }
    free(B);
}

void mergeSort_string(char **text, int head, int tail){
    if(head<tail){
        int mid=(head+tail)/2;
        mergeSort_string(text,head,mid);
        mergeSort_string(text,mid+1,tail);
        merge_string(text,head,mid,tail);
    }
}

//heapSort
void heapify_string(char **text, int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && strcmp(*(text+l),*(text+largest))>0){
        largest = l;
    }
    if(r<n && strcmp(*(text+r),*(text+largest))>0){
        largest = r;
    }
    if(largest!=i){
        SWAP_STRING(*(text+i),*(text+largest));
        heapify_string(text, n, largest);
    }
}

void heapSort_string(char **text, int n){
    int i;
    for(i=n/2-1;i>=0;i--){
        heapify_string(text, n, i);
    }
    for(i=n-1;i>0;i--){
        SWAP_STRING(*(text+0), *(text+i));
        heapify_string(text, i, 0);
    }
}
