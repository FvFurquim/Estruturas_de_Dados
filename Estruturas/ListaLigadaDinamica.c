#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}PRODUTO;

typedef struct pont{
    PRODUTO prod;
    struct pont* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT inicio;
}LISTA;

int main(){
    
    return 0;
}

void inicializarLista(LISTA* l){
    l->inicio = NULL;
}

int tamanho(LISTA* l){
    int tam = 0;
    PONT end = l->inicio;
    
    while (end != NULL){
        tam++;
        end = end->prox;
    }
    
    return tam;
}

void exibirLista(LISTA* l){
    PONT end = l->inicio;
    
    printf("Lista: ");
    
    while(end != NULL){
        printf("%i ", end->prod.chave);
        end = end->prox;
    }
    
    printf("\n");
}

// Busca normal;

int buscarElem(LISTA*l, TIPOCHAVE ch){
    PONT pos = l->inicio;
    
    while(pos != NULL){
        if(pos->prod.chave == ch)
            return pos;
        pos = pos->prox;
    }
    
    return NULL;
}

// Busca em uma lista ordenadaa pela chave;

int buscarElemOrd(LISTA* l, TIPOCHAVE ch){
    PONT pos = l->inicio;
    
    while(pos != NULL && pos->prod.chave != ch)
        pos = pos->prox;
    
    if(pos != NULL && pos->prod.chave == ch)
        return pos;
    
    return NULL;
}

// Funcao auxiliar para retornar o endereco do endereco caso ele exista e retornar seu predecessor independentemente se o elemento existe ou nao;

// Recebe o endereco de ant, uma variavel que o usuario passa para guardar o anterior;

PONT buscaAuxiliar(LISTA* l, TIPOCHAVE ch, PONT* ant){
    *ant == NULL;
    PONT atual = l->inicio;
    
    while(atual != NULL && atual != atual->prod.chave){
        *ant = atual;
        atual = atual->prox;
    }
    
    if(atual != NULL && atual->prod.chave == ch){
        return atual;
    }
    
    return NULL;
}

bool inserirElem(LISTA* l, PRODUTO p){
    TIPOCHAVE ch = p->chave;
    PONT ant, i;
    i = buscaAuxiliar(l, ch, &ant);
    
    if(i != NULL)
        return false;
    
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->prod = p;
    
    if(ant == NULL){
        i->prox = l->inicio;
        l->inicio = i;
    }
    
    else{
        i->prox = ant->prox;
        ant->prox = i;
    }
    
    return true;
}

bool excluirElem(LISTA* l, TIPOCHAVE ch){
    PONT ant, i;
    i = buscaAuxiliar(l, ch, &ant);
    
    if(i == NULL)
        return false;
    
    if(ant == NULL)
        l->inicio = i->prox;
    
    else
        ant->prox = i->prox;
    
    free(i);
    
    return true;
}

void reinicializarLista(LISTA* l){
    PONT end = l->inicio;
    
    while(end != NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    
    l->inicio = NULL;
}