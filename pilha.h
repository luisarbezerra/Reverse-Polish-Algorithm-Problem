#ifndef _PILHA_H
#define _PILHA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo { //crio a estrutura do nodo da pilha, que contém o valor, o ponteiro para a próxima posição e para a posição anterior.
    int valor;
    struct nodo *proximo;
    struct nodo *anterior;
}nodo;

typedef struct pilha { //aqui, crio a estrutura da pilha, que contém um apontador para sua base e topo.
    nodo *base;
    nodo *topo;
}pilha;

pilha *criaPilha();

void empilhaElemento(int elemento, pilha *p);

int desempilhaElemento(pilha *p);

#endif // _PILHA_H
