void insertSorted(LIST *A, char X){
    int i, j;
    if (A->count < MAX){
        for(i = 0 ; i < A->count && A->Elements[i] < X; i++){}
        for(j = A->count; j > i; j--){
            A->Elements[j] = A->Elements[j-1];
        }
        A->Elements[i] = X;
        A->count++;
}


void deleteElem(LIST *A, char X){
    if (A->count != 0){
        int i;
        for (i = 0; i < A->count && A->Elements[i] != X; i++){}
        for(; i < A->count -1; i++){
            A->Elements[i] = A->Elements[i+1];
        }
        A->count--;
    }
}
