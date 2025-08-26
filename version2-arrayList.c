/* 
Program Description
    Title: Version 2 Implementation of Array Lists
    Programmer: Rean Coyacot
    Date of Last Edit: 8/26/2025
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50

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
    studRecord Elements[MAX];
    int count;
}LIST;


//function prototypes
void initList(LIST **A);
void insertLast(LIST *A, studRecord element);
void display(LIST *A);

int main(){
    //sample data
    studRecord data[MAX] = {
        {
            .name = {"Smith", "John", 'A'},
            .ID = 1001,
            .Course = "BSCS",
            .Year = 2
        },
        {
            .name = {"Johnson", "Mary", 'B'},
            .ID = 1002,
            .Course = "BSIT",
            .Year = 3
        },
        {
            .name = {"Williams", "Robert", 'C'},
            .ID = 1003,
            .Course = "BSECE",
            .Year = 1
        },
        {
            .name = {"Brown", "Jennifer", 'D'},
            .ID = 1004,
            .Course = "BSCE",
            .Year = 4
        },
        {
            .name = {"Davis", "Michael", 'E'},
            .ID = 1005,
            .Course = "BSME",
            .Year = 2
        }
    };

    LIST *L;

    initList(&L);

    int i;
    for(i = 0; i < 5; i++){
        insertLast(L, data[i]);
    }

    display(L);

    return 0;
}

void initList(LIST **A){
    *A = (LIST *) malloc (sizeof(LIST));
    (*A)->count = 0;
}

void insertLast(LIST *A, studRecord element){
    memcpy(&A->Elements[A->count++], &element, sizeof(studRecord));
}

void display(LIST *A){
    int i;
    printf("Current List:\n");
    for( i = 0; i < A->count; i++){
        printf("%-10s %-10s %-10c - %-10d %-10s %-10d\n", A->Elements[i].name.LName, A->Elements[i].name.LName, A->Elements[i].name.Mi, A->Elements[i].ID, A->Elements[i].Course, A->Elements[i].Year);
    }
}

