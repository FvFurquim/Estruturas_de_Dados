#include <stdio.h>

#define MAX 10
#define INVALIDO -1
#define true 1
#define false 0

typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}PRODUTO;

typedef struct{
    PRODUTO prod;
    int prox;
}ELEMENTO;

typedef struct{
    ELEMENTO A[MAX];
    int inicio;
    int dispo;
}LISTA;

int main(){
    
    return 0;
}

void inicializarLista(LISTA* l){
    int i;
    
    for(i = 0; i < MAX - 1; i++)
        l->A[i].prox = i + 1;
    
    l->A[MAX - 1].prox = INVALIDO;
    l->inicio = INVALIDO;
    l->dispo = 0;
}

int tamanho(LISTA* l){
    int i = l->inicio;
    int tam = 0;
    
    while(i != INVALIDO){
        tam++;
        i = l->A[i].prox;
    }
    
    return tam;
}

void imprimirLista(LISTA* l){
    int i = l->inicio;
    
    printf("Lista: ");
    
    while(i != INVALIDO){
        printf("%i ", l->A[i].prod.chave);
        i = l->A[i].prox;
    }
    
    printf("\n");
}

int buscaSeqOrd(LISTA* l, TIPOCHAVE ch){
    int i = l->inicio;
    
    while(i != INVALIDO && l->A[i].prod.chave)
        i = l->A[i].prox;
    
    if(i != INVALIDO)
        return i;
    
    return INVALIDO;
}

// Para a insercao de um elemento, sera criado uma funcao auxiliar "obterNo", que retira o primeiro elemento da "lista" de disponiveis e retorna sua posicao;

int obterNo(LISTA* l){
    int retirado = l->dispo;
    
    if(l-> dispo != INVALIDO)
        l->dispo = l->A[l->dispo].prox;
    
    return retirado;
}

bool inserirElem(LISTA* l, PRODUTO p){
    if(l->dispo == INVALIDO)
        return false;
    
    int ant = INVALIDO;
    int i = l->inicio;
    TIPOCHAVE ch = p.chave;
    
    while(i != INVALIDO && l->A[i].prod.chave < ch){
        ant = i;
        i = l->A[i].prox;
    }
    
    if(i != INVALIDO && l->A[i].prod.chave == ch)
        return false;
    
    //A partir desse ponto, ja eh confirmado que pode ser inserido, basta saber aonde;
    
    i = obterNo(l);
    l->A[i].prod = p;
    
    if(ant == INVALIDO){
        l->A[i].prox = l->inicio;
        l->inicio = i;
    }
    
    else{
        l->A[i].prox = l->A[ant].prox;
        l->A[ant].prox = i;
    }
    
    return true;
}

//Funcao auxiliar para devolver um elemento para a lista de disponiveis;

void devolverNo(LISTA* l, int j){
    l->A[j].prox = l->dispo;
    l->dispo = j;
}

bool excluirElem(LISTA* l, TIPOCHAVE ch){
    if(l->inicio == INVALIDO){
        return false;
    }
    
    int ant = INVALIDO;
    int i = l->inicio;
    
    while(i != INVALIDO && l->A[i].prod.chave < ch){
        ant = i;
        i = l->A[i].prox;
    }
    
    if(ant == INVALIDO)
        l->inicio = l->A[i].prox;
    
    else
        l->A[ant].prox = l->A[i].prox;
    
    devolverNo(l, i);
    
    return true;
}

void reinicializar(LISTA* l){
    inicializarLista(l);
}
