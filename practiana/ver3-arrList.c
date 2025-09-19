/* 
Program Description
    Title: Version 3 of Array List
    Programmer: Rean G. Coyacot
    Date of Last Edit: 08/27/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char LName [16];
    char FName [24];
    char Mi;
}nameType;

typedef struct {
    nameType name;
    int ID;
    char Course [8];
    int Year;
}studRecord;

typedef struct{
    studRecord *elemPtr;
    int count;
    int arrSize;
}LIST;

int main(){


    return 0;
}

void initList(LIST *A){
    A->arrSize = 50;
    A->count = 0;
    A->elemPtr = (LIST *) malloc (sizeof(LIST)*(A->arrSize));
}

void insertLast(LIST * A, studRecord data){
    A->elemPtr[A->count++] = data;
}

void display(LIST A){
    int i;
    for(i = 0; i < A.count; i++){
        printf("oteotenote");
    }
}

