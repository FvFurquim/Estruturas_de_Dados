#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0

typedef int bool;

typedef struct{
    int chave;
}PRODUTO;

typedef struct aux{
    PRODUTO* prod;
    struct aux* prox;
}ELEMENTO;

typedef struct{
    ELEMENTO* inicio;
    ELEMENTO* fim;
}FILA;

void inicializarFila(FILA* f){
    f->inicio = NULL;
    f->fim = NULL;
}

int tamanho(FILA* f){
    ELEMENTO* end = f->inicio;
    int tam;
    
    while(end != NULL){
        end = end->prox;
        tam++;
    }
    
    return tam;
}

void imprimirFila(FILA* f){
    ELEMENTO* end = f->inicio;
    
    printf("Fila:");
    
    while(end != NULL){
        printf(" %i", end->prod.chave);
        end = end->prox;
    }
    
    printf("\n");
}

bool inserirElem(FILA* f, PRODUTO* p){
    ELEMENTO* novo = (ELEMENTO*)malloc(sizeof(ELEMENTO));
    novo->prod = p;
    novo->prox = NULL;
   
    if(f->inicio == NULL)
        f->inicio = novo;
    
    else
        f->fim->prox = novo;
    
    f->fim = novo;
    
    return true;
}

bool excluirElem(FILA* f, PRODUTO* p){
    if(f->inicio == NULL)
        return false;
    
    *p = f->inicio->prod;
    ELEMENTO* apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    
    if(f->inicio == NULL)
        f->fim = NULL;
    
    return true;
}
