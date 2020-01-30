#include <stdio.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}PRODUTO;

typedef struct aux{
    PRODUTO prod;
    struct aux* prox;
}ELEMENTO;

typedef struct{
    ELEMENTO* cabeca;
}LISTA;

void inicializarLista(LISTA* l){
    l->cabeca = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    l->cabeca->prox = l->cabeca;
}

int tamanho(LISTA* l){
    int tam = 0;
    ELEMENTO* end = l->cabeca->prox;
    
    while(end != l->cabeca){
        end = end->prox;
        tam++;
    }
    
    return tam;
}

void imprimirLista(LISTA* l){
    ELEMENTO* end = l->cabeca->prox;
    
    printf("Lista: ");
    
    while(end != l->cabeca){
        printf("%i ", end->prod.chave);
        end = end->prox;
    }
    
    printf("\n ");
}

ELEMENTO* buscarElem(LISTA* l, TIPOCHAVE ch){
    ELEMENTO* pos = l->cabeca->prox;
    l->cabeca->prod.chave = ch; //Sentinela;
    
    while(pos->prod.chave != ch)
        pos = pos->prox;
    
    if(pos != l->cabeca)
        return pos;
    
    return NULL;
}

ELEMENTO* buscaAuxiliar(LISTA* l, TIPOCHAVE ch, ELEMENTO** ant){
    *ant = l->cabeca;
    ELEMENTO* atual = l->cabeca->prox;
    l->cabeca->prod->chave = ch; //Sentinela;
    
    while(atual->prod.chave != ch){
        *ant = atual;
        atual = atual->prox;
    }
    
    if(atual != l->cabeca && atual->prod.chave != ch)
        return atual;
    
    else
        return NULL;
}

bool inserirElem(LISTA* l, PRODUTO p){
    ELEMENTO* ant, i;
    i = buscaAuxiliar(l, p->chave, ant);
    
    if(i != NULL)
        return false;
    
    i = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    i->prod = p;
    i->prox = ant->prox;
    ant->prox = i;
    
    return true;
}

bool excluirElem(LISTA* l, TIPOCHAVE ch){
    ELEMENTO* i, ant;
    i = buscaAuxiliar(l, ch, ant);
    
    if(ant == NULL)
        return false;
    
    ant->prox = i->prox;
    free(i);
    
    return true;
}

void reinicializarLista(LISTA* l){
    ELEMENTO* end = l->cabeca->prox;
    
    while(end != l->cabeca){
        ELEMENTO* apagar = end;
        end = end->prox;
        free(apagar);
    }
    
    l->cabeca->prox = l->cabeca;
}

int main(){
    
    
    return 0;
}