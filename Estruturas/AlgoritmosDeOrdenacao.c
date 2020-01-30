#include <stdio.h>

void ordSelecao(int a[]){
    int temp, i, j, min;
    int tam = sizeof a/ sizeof* a;
    
    for(i = 0; tam - 2; i++){
        min = i;
        for(j = i + 1; j < tam - 1; j++){
            if(a[j] < a[min])
                min = j;
            temp = a[min];
            a[min] = j;
            a[i] = temp;
        }
    }
}

void bubbleSort(int a[]){
    int i, j, temp, trocas;
    int tam = sizeof a/ sizeof* a;
    
    for(i = tam - 1; i > 0; i--){
        trocas = 0;
        for(j = 0; j < i; j++){
            if(a[j-1] > a[j]){
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
                trocas++;
            }
        }
        
        if(trocas == 0)
            break;
    }
}

void quickSort(int array[], int i, int f){
    
}

void partition(int a[], int i, int f){
    int v, k, j, t;
    v = a[f];
    j = i - 1;
    k = f;
    do{
        do{
            j = j + 1;
        }
        while((a[j] < v) && (j < f));
    }
    while((a[k] > v && (k > 0)));
    
    t = a[j];
    a[j] = a[k];
    a[k] = t;
}

int main() {
    
    return 0;
}

