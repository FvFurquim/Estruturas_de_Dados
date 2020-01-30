#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0

typedef int bool;

typedef struct aux{
    float valor;
    int coluna;
    struct aux* prox;
}NO;

typedef struct{
    NO** A;     //Ponteiro para um array de ponteiros de NO
    int linhas;
    int colunas;
}MATRIZ;

void inicializarMatriz(MATRIZ* m, int lin, int col){
    int i;
    m->linhas = lin;
    m->colunas = col;
    m->A = (NO**)malloc(lin*sizeof(NO*));
    for(i = 0; i < lin; i++)
        m->A[i] = NULL;
}

bool inserirValor(MATRIZ* m, int lin, int col, float val){
    if(lin < 0 || lin >= m->linhas || col < 0 || col >= m->colunas)
        return false;
    
    NO* ant = NULL;
    NO* atual = m->A[lin];
    
    while(atual != NULL && atual->coluna < col){
        ant = atual;
        atual = atual->prox;
    }
    
    if(atual != NULL && atual->coluna == col){
        if(val == 0){
            if(ant == NULL)
                m->A[lin] = atual->prox;
            else
                ant->prox = atual->prox;
            free(atual);
        }
        
        else
            atual->valor = val;
    }
    
    else if(val != 0){
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->coluna = col;
        novo->valor = val;
        novo->prox = atual;
        if(ant == NULL)
            m->A[lin] = novo;
        else
            ant->prox = novo;
    }
    
    return true;
}

float valorMatriz(MATRIZ* m, int lin, int col){
    if(lin < 0 || lin >= m->linhas || col < 0 || col >= m->colunas)
        return 0;
    
    NO* atual = m->A[lin];
    while(atual != NULL && atual->coluna < col)
        atual = atual->prox;
    
    if(atual != NULL && atual->coluna == col)
        return atual->valor;
    
    return 0;
}

int main() {

    return 0;
}

