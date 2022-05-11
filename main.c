#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}

int max(int x, int y) {
    if (x>y) return x;
    else return y;
}

int altura (ABin a) {
    int cont = 0;

    if (a != NULL) {
        cont = 1 + max(altura(a->esq), altura(a->dir));
    }

    return cont;
}

int nFolhas (ABin a) {
    int cont = 0;

    if (a != NULL) {
        if (a->esq == NULL && a->dir == NULL) cont = 1;
        else cont = nFolhas(a->esq) + nFolhas(a->dir);
    }

    return cont;
}

ABin maisEsquerda (ABin a) {
    if (a != NULL) {
        while (a->esq != NULL) {
            a = a->esq;
        }
    }
    return a;
}

void imprimeNível(ABin a, int l) {
    if (a != NULL && l > 0) {
       imprimeNível(a->dir, l-1);
       imprimeNível(a->esq, l-1);
    }
    else if (a != NULL && l == 0) {
        printf("%d", a->valor);
    }
}