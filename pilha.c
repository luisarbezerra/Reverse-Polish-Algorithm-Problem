#include "pilha.h"

pilha *criaPilha(){ //a função retorna uma pilha criada e vazia.

    pilha *p;
    p = (pilha*)(malloc(sizeof(pilha))); //aloco espaço na memória dinâmica para a estrutura da pilha.
    p->base = NULL; // direciono os ponteiros dela para NULL
    p->topo = NULL;

    return p; //retorno a pilha.
}

void empilhaElemento(int elemento, pilha *p){ //a função empilha o elemento dado na pilha. é do tipo void pois não precisa de retorno.
    nodo *n; //crio e aloco um nodo novo para a pilha.
    n = (nodo*)(malloc(sizeof(nodo)));
    n->valor = elemento; //o valor do nodo será o valor do elemento enviado na função. também direciono os ponteiros dele para NULL.
    n->proximo = NULL;
    n->anterior = NULL;

    if (p->base == NULL) { //caso a pilha estiver vazia, este nodo será sua base e, também, seu topo.
        p->base = n;
        p->topo = n;
    } else {
        n->anterior = p->topo; //caso tenha elementos na pilha, este nodo será organizado de forma a ser o novo topo.
        p->topo->proximo = n;
        p->topo = n;
    }
}

int desempilhaElemento(pilha *p){ //a função desempilha pega o último elemento da pilha e o retorna como um inteiro.

    if (p->base == NULL) { //este caso jamais ocorrerá visto o padrão das entradas (a pilha estar vazia).
        return -2;
    } else {
        int valor = p->topo->valor; //aqui, pego o valor do topo, que será retornado. porém, antes de retornar, preciso dar free no último nodo da pilha e redirecionar o seu topo para o penúltimo nodo dela.
        nodo *q; //crio um nodo auxiliar para desalocar a memória do último nodo.

        q = p->topo->anterior; //o nodo auxiliar recebe o penúltimo nodo.
        free (p->topo); //dou free no último nodo.

        p->topo = q; //o novo topo será o q, ou seja, o antigo penúltimo nodo, agora o último.

        if(p->topo == NULL) p->base = NULL; //caso o topo seja null, a sua base também será null.

        return valor; //retorno o valor pedido.
    }
}
