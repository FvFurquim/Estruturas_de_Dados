#include <stdio.h>
#include<malloc.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}PRODUTO;

typedef struct aux{
    PRODUTO prod;
    struct aux* ante;
    struct aux* prox;
}ELEMENTO;

typedef struct{
    ELEMENTO* cabeca;
}DECK;

void inicializarDeque(DECK* d){
    d->cabeca = (ELEMENTO*)malloc(sizeof(ELEMENTO));
    d->cabeca->ante = d->cabeca;
    d->cabeca->prox = d->cabeca;
}

int tamanho(DECK* d){
    ELEMENTO* end = d->cabeca->prox;
    int tam = 0;
    
    while(end != d->cabeca){
        tam++;
        end = end->prox;
    }
    
    return tam;
}

void imprimirDeck(DECK* d){
    ELEMENTO* end = d->cabeca->prox;
    
    printf("Deck: ");
    
    while(end != d->cabeca){
        printf("%i", end->prod.chave);
        end = end->prox;
    }
    
    printf("\n");
}

bool inserirElemIniio(DECK* d, PRODUTO p){
    ELEMENTO* novo = (ELEMENTO*)malloc(sizeof(ELEMENTO));
    novo->prod = p;
    novo->prox = d->cabeca->prox;
    novo->ante = d->cabeca;
    d->cabeca->prox->ante = novo;
    d->cabeca->prox = novo;
    
    return true;
}

bool inserirElemFim(DECK* d, PRODUTO p){
    ELEMENTO* novo = (ELEMENTO*)malloc(sizeof(ELEMENTO));
    novo->prod = p;
    novo->prox = d->cabeca;
    novo->ante = d->cabeca->ante;
    d->cabeca->ante->prox = novo;
    d->cabeca->ante = novo;
    
    return true;
}

bool excluirElemInicio(DECK* d, PRODUTO* p){
    if(d->cabeca->prox == d->cabeca)
        return false;
    
    ELEMENTO* apagar;
    apagar = d->cabeca->prox;
    *p = apagar;
    d->cabeca->prox = apagar->prox;
    apagar->prox->ante = d->cabeca;
    free(apagar);
    
    return true;
}

bool excluirElemFim(DECK* d, PRODUTO* p){
    if(d->cabeca->prox == d->cabeca)
        return false;
    
    ELEMENTO* apagar;
    apagar = d->cabeca->ante;
    *p = apagar;
    d->cabeca->ante = apagar->ante;
    apagar->ante->prox = d->cabeca;
    free(apagar);
    
    return true;
}

void reinicializarDeck(DECK* d){
    ELEMENTO* end = d->cabeca->prox;
    
    while(end != d->cabeca){
        ELEMENTO* apagar = end;
        end = end->prox;
        free(apagar);
    }
}

int main(){
    
    return 0;
}