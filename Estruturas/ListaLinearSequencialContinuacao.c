#include <stdio.h>

#define MAX 10
#define true 1
#define false 0

typedef int TIPOCHAVE;
typedef int bool;

typedef struct{
    TIPOCHAVE chave;
}PRODUTO;

typedef struct{
    PRODUTO A[MAX + 1];
    int numElem;
}LISTA;

int main() {
    
    /*
    LISTA felipeInfo;
    LISTA* felipe;
    felipe = &felipeInfo;

    PRODUTO dia;
    PRODUTO mes;
    PRODUTO ano;
    PRODUTO idade;
    
    dia.chave = 23;
    mes.chave = 03;
    ano.chave = 2001;
    idade.chave = 18;
    
    inicializarLista(felipe);
    inserirElem(felipe, dia, 0);
    inserirElem(felipe, mes, 1);
    inserirElem(felipe, idade, 2);
    imprimirLista(felipe);
    printf("Tamanho: %i\n", tamanho(felipe));
    inserirElem(felipe, ano, 2);
    imprimirLista(felipe);
    printf("Tamanho: %i\n", tamanho(felipe));
    printf("Posição: %i\n", buscarElem(felipe, mes));
    excluirElem(felipe, ano);
    imprimirLista(felipe);
    printf("Tamanho: %i\n", tamanho(felipe));
    printf("Sem o elemento: %i\n", buscarElem(felipe, 2018));
   
    */
    return 0;
}


//Métodos da estrutura;

void inicializarLista(LISTA* l){
    l->numElem = 0;
}

int tamanho(LISTA* l){
    return l->numElem;
}

void imprimirLista(LISTA* l){
    
    int i;
    
    printf("Lista: ");
    
    for(i = 0; i < l->numElem; i++){
        printf("%i ", l->A[i].chave);
    }
    
    printf("\n");
}

int buscaElemSentinela(LISTA* l, TIPOCHAVE ch){
    
    int i = 0;
    l->A[l->numElem].chave = ch;
    
    while(i != ch)
        i++;
    
    if(i != l->numElem)
        return i;
    
    else
        return -1;
}

int buscaBinaria(LISTA* l, TIPOCHAVE ch){
    int esq, dir, meio;
    esq = 0;
    dir = l->numElem - 1;
    
    while(esq <= dir){
        meio = (esq + dir) / 2;
        
        if(l->A[meio].chave == ch)
            return meio;
        
        else{
            if(l->A[meio].chave < ch)
                esq = meio + 1;
            else
                dir = meio - 1;
        }
    }
    
    return -1;
}

//Insercao na posicao ordenada;

bool inserirElemListaOrd(LISTA* l, PRODUTO p){
    
    if(l->numElem == MAX)
        return false;
    
    int i;
    
    for(i = l-> numElem; i > 0 && l->A[i - 1].chave > p.chave; i--)
        l->A[i] = l->A[i - 1];
    
    l->A[i] = p;
    l->numElem++;
    return true;
}

bool excluirElemListaOrd(LISTA* l, TIPOCHAVE ch){
    int i;
    int pos = buscaBinaria(l, ch);
    
    if(pos == -1)
        return false;
    
    for(i = pos; i < l->numElem - 1; i++)
        l->A[i] = l->A[i + 1];
    
    l->numElem--;
    return true;
}

void reinicializarLista(LISTA*l){
    l->numElem = 0;
}
