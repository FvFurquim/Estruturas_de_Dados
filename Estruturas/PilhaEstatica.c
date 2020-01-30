#include <stdio.h>

#define MAX 10
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}PRODUTO;

typedef struct{
    PRODUTO A[MAX];
    int topo;
}PILHA;

void inicializarPilha(PILHA* p){
    p->topo = -1;
}

int tamanho(PILHA* p){
    return p->topo + 1;
}

void imprimirPilha(PILHA* p){
    int i;
    
    printf("Lista: ");
    
    for(i = 0; i <= p->topo; i++)
        printf("%i", p->A[i].chave);
    
    printf("\n");
}

bool inserirElem(PILHA* p, PRODUTO prod){
    if(p->topo >= MAX - 1)
        return false;
    
    p->A[p->topo + 1] = prod;
    p->topo = p->topo + 1;
    
    return true;
}

// Insere-se um PRODUTO para armazenar (retornar) o elemento PRODUTO excluído;

bool excluirElem(PILHA* p, PRODUTO* prod){
    if(p->topo == -1)
        return false;
    
    *prod = p->A[p->topo];
    p->topo = p->topo - 1;
    
    return true;
}

void reinicializar(PILHA* p){
    p->topo = -1;
}

int main(){
    
    
    return 0;
}