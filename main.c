#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "generate_dataset.h"
#include "sort_int.h"
#include "sort_string.h"
#define TEST_DATA_CNT 1000000
#define STRING_LEN 100

int main()
{
    //generate dataset
    generate_randint();
    generate_randstring();

    //read random_int dataset
    int i,j=0,int_data;
    int *int_test_data1, *int_test_data2, *int_test_data3, *int_test_data4;

    int_test_data1 = (int *) malloc(sizeof(int)*TEST_DATA_CNT);
    int_test_data2 = (int *) malloc(sizeof(int)*TEST_DATA_CNT);
    int_test_data3 = (int *) malloc(sizeof(int)*TEST_DATA_CNT);
    int_test_data4 = (int *) malloc(sizeof(int)*TEST_DATA_CNT);

    FILE *fp1 = fopen("dataset1.txt","r");
    if(fp1 == NULL){
        perror("Error opening dataset1");
    }
    else{
        while(fscanf(fp1,"%d",&int_data)!=EOF){
            int_test_data1[j] = int_data;
            int_test_data2[j] = int_data;
            int_test_data3[j] = int_data;
            int_test_data4[j] = int_data;
            j++;
        }
    }

    //read random_string dataset
    char *string_data;
    char **string_test_data1, **string_test_data2, **string_test_data3, **string_test_data4;

    string_data = (char *) malloc(sizeof(char)*STRING_LEN);
    string_test_data1 = (char **) malloc(sizeof(char *)*TEST_DATA_CNT);
    string_test_data2 = (char **) malloc(sizeof(char *)*TEST_DATA_CNT);
    string_test_data3 = (char **) malloc(sizeof(char *)*TEST_DATA_CNT);
    for(i=0;i<TEST_DATA_CNT;i++){
        string_test_data1[i] = (char *) malloc(sizeof(char)*STRING_LEN);
        string_test_data2[i] = (char *) malloc(sizeof(char)*STRING_LEN);
        string_test_data3[i] = (char *) malloc(sizeof(char)*STRING_LEN);
    }

    j=0;
    FILE *fp2 = fopen("dataset2.txt","r");
    if(fp2 == NULL){
        perror("Error opening dataset2");
    }
    else{
        while(fgets(string_data,TEST_DATA_CNT,fp2)!=NULL){
            strcpy(string_test_data1[j], string_data);
            strcpy(string_test_data2[j], string_data);
            strcpy(string_test_data3[j], string_data);
            j++;
        }
    }

    //calculate sorting time
    struct timeval start;
    struct timeval end;
    unsigned long diff;

    //quick sorting number
    printf("\nNumber Sorting:\n");
    gettimeofday(&start, NULL);
    quickSort_int(int_test_data1, 0, TEST_DATA_CNT-1);
    gettimeofday(&end, NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec);
    printf("Quick Sorting number performance %ld us (equal %f sec)\n", diff, diff/1000000.0);
    free(int_test_data1);

    //merge sorting number
    gettimeofday(&start, NULL);
    mergeSort_int(int_test_data2, 0, TEST_DATA_CNT-1);
    gettimeofday(&end, NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec);
    printf("Merge Sorting number performance %ld us (equal %f sec)\n", diff, diff/1000000.0);
    free(int_test_data2);

    //heap sorting number
    gettimeofday(&start, NULL);
    heapSort_int(int_test_data3, TEST_DATA_CNT);
    gettimeofday(&end, NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec);
    printf("Heap Sorting number performance %ld us (equal %f sec)\n", diff, diff/1000000.0);
    free(int_test_data3);

    //radix sorting number
    gettimeofday(&start, NULL);
    radixSort_int(int_test_data4, TEST_DATA_CNT);
    gettimeofday(&end, NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec);
    printf("Radix Sorting number performance %ld us (equal %f sec)\n", diff, diff/1000000.0);

    //write result to file
    FILE *fpr_int = fopen("result1.txt","w");
    for(i=0;i<TEST_DATA_CNT;i++){
        fprintf(fpr_int,"%d\n",int_test_data4[i]);
    }
    fclose(fpr_int);
    free(int_test_data4);

    //quick sorting string
    printf("\nString Sorting:\n");
    gettimeofday(&start, NULL);
    quickSort_string(string_test_data1, 0, TEST_DATA_CNT-1);
    gettimeofday(&end, NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec);
    printf("Quick Sorting string performance %ld us (equal %f sec)\n", diff, diff/1000000.0);
    for(i=0;i<TEST_DATA_CNT;i++){
        free(string_test_data1[i]);
    }
    free(string_test_data1);

    //merge sorting string
    gettimeofday(&start, NULL);
    mergeSort_string(string_test_data2, 0, TEST_DATA_CNT-1);
    gettimeofday(&end, NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec);
    printf("Merge Sorting string performance %ld us (equal %f sec)\n", diff, diff/1000000.0);
    for(i=0;i<TEST_DATA_CNT;i++){
        free(string_test_data2[i]);
    }
    free(string_test_data2);

    //heap sorting string
    gettimeofday(&start, NULL);
    heapSort_string(string_test_data3, TEST_DATA_CNT);
    gettimeofday(&end, NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec);
    printf("Heap Sorting string performance %ld us (equal %f sec)\n", diff, diff/1000000.0);

    //write result to file
    FILE *fpr_string = fopen("result2.txt","w");
    for(i=0;i<TEST_DATA_CNT;i++){
        fprintf(fpr_int,"%s",string_test_data3[i]);
        free(string_test_data3[i]);
    }
    fclose(fpr_string);
    free(string_test_data3);
}
