#include <stdio.h>
#include <malloc.h>

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
    ELEMENTO* topo;
}PILHA;

void inicializarPilha(PILHA* p){
    p->topo = NULL;
}

int tamanho(PILHA* p){
    ELEMENTO* end = p->topo;
    int tam = 0;
    
    while(end != NULL){
        tam++;
        end = end->prox;
    }
    
    return tam;
}

// estaVazia é mais rápida do que verificar o tamanho;

bool estaVazia(PILHA* p){
    if(p->topo == NULL)
        return true;
    
    return false;
}

void imprimirPilha(PILHA* p){
    ELEMENTO* end = p->topo;
    
    printf("Pilha: ");
    
    while(end != NULL){
        printf("%i ", end->prod.chave);
        end = end->prox;
    }
    
    printf("\n");
}

bool inserirElem(PILHA* p, PRODUTO pro){
    ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    novo->prod = pro;
    novo->prox = p->topo;
    
    p->topo = novo;
    
    return true;
}

bool excluirElem(PILHA* p, PRODUTO* pro){
    if(estaVazia(p) == true)
        return false;
    
    *pro = p->topo->prod;
    ELEMENTO* apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    
    return true;
}

void reinicializarPilha(PILHA*p){
    ELEMENTO* apagar;
    ELEMENTO* posicao = p->topo;
    
    while(posicao != NULL){
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    
    p->topo = NULL;
}

int main(){
    
    
    return 0;
}