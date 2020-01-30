#include <stdlib.h>

#define true 0
#define false 1
#define MAX 50

typedef int bool;

typedef struct{
    int chave;
}ELEMENTO;

typedef struct{
    ELEMENTO A[MAX];
    int topo1, topo2;
}PILHADUPLA;

void inicializarPilhaDupla(PILHADUPLA* p){
    p->topo1 = -1;
    p->topo2 = MAX;
}

int tamanhoTotal(PILHADUPLA* p){
    return (p->topo1 - 1) + (MAX - p->topo2);
}

bool imprimirUmaPilha(PILHADUPLA* p, int pilha){
    if(pilha < 1 || pilha > 2)
        return false;
    
    int i;
    
    printf("Pilha %i", pilha);
    
    if(pilha == 1)
        for(i = p->topo1; i >= 0; i--)
            printf("%i ", p->A[i].chave);
        
    else
        for(i = p->topo2; i < MAX; i++)
            printf("%i ", p->A[i].chave);
    
    printf("\n");
    return true;
}

bool inserirElemento(PILHADUPLA* p, ELEMENTO elem, int pilha){
    if(pilha < 1 || pilha > 2)
        return false;
    if(p->topo1 + 1 == p->topo2)
        return false;
    
    if(pilha == 1){
        p->topo1 = p->topo1 + 1;
        p->A[p->topo1] = elem;
    }
    else{
        p->topo2 = p->topo2 - 1;
        p->A[p->topo2] = elem;
    }
    
    return true;
}

bool exluirElemento(PILHADUPLA* p, int pilha, ELEMENTO* elem){
    if(pilha < 1 || pilha > 2)
        return false;
    
    if(pilha == 1){
        if(p->topo1 == -1) return false;
        *elem = p->A[p->topo1];
        p->topo1 = p->topo1 - 1;
    }
    
    else{
        if(p->topo2 == MAX) return false;
        *elem = p->A[p->topo2];
        p->topo2 = p->topo2 + 1;
    }
    
    return true;
}

void reinicializarPilhaDupla(PILHADUPLA* p){
    inicializarPilhaDupla(p);
}

int main(){
    
    return 0;
}