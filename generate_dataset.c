#include <stdio.h>
#include <stdlib.h>
#define TEST_DATA_CNT 1000000
#define STRING_LEN 100

void generate_randint(){
    FILE *fp;
    int i;
    fp = fopen("dataset1.txt","w");

    srand(1);
    for(i=0;i<TEST_DATA_CNT;i++){
        fprintf(fp,"%d\n",rand());
    }
    fclose(fp);
}

void generate_randstring(){
    FILE *fp;
    int i,j;
    char randChar;
    fp = fopen("dataset2.txt","w");

    srand(1);
    for(i=0;i<TEST_DATA_CNT;i++){
        for(j=0;j<STRING_LEN;j++){
            randChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[rand()%52];
        	fprintf(fp,"%c",randChar);
        }
    	fprintf(fp,"\n");
    }
    fclose(fp);
}
