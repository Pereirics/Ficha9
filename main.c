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
//1.
//a)
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

//b)
int nFolhas (ABin a) {
    int cont = 0;

    if (a != NULL) {
        if (a->esq == NULL && a->dir == NULL) cont = 1;
        else cont = nFolhas(a->esq) + nFolhas(a->dir);
    }

    return cont;
}

//c)
ABin maisEsquerda (ABin a) {
    if (a != NULL) {
        while (a->esq != NULL) {
            a = a->esq;
        }
    }
    return a;
}

//d)
void imprimeNível(ABin a, int l) {
    if (a != NULL && l > 0) {
       imprimeNível(a->dir, l-1);
       imprimeNível(a->esq, l-1);
    }
    else if (a != NULL && l == 0) {
        printf("%d", a->valor);
    }
}

//e)
int min (int x, int y) {
    if (x < y) return x;
    else return y;
}

int procuraE (ABin a, int x) { //1 é F, 0 é V
    int r = 1;
    if (a != NULL) {
        if (a->valor == x) {
            r = min(min(0, procuraE(a->esq, x)), procuraE(a->dir, x));
        }
        else {
            r = min(r, min(procuraE(a->esq, x), procuraE(a->esq,x)));
        }
    }
    return r;
}

//2.
//f)
ABin result(ABin a, ABin b) {
    if (a != NULL) return a;
    else return b;
}

struct nodo *procura (ABin a, int x) {
    ABin r = NULL;
    if (a != NULL) {
        if (a->valor == x) {
            r = a;
        }
        if (a->valor > x) {
            r = procura(a->esq, x);
        }
        if (a->valor < x) {
            r = procura(a->dir, x);
        }
    }
    return r;
}

int nivel (ABin a, int x) {
    int r;
    for (r = 0; a != NULL && a->valor != x; r++) {
        if (a->valor < x) {
            a = a->dir;
        }
        else a = a->esq;
    }
    if (a != NULL) return r;
    else return -1;
}

void imprimeAte (ABin a, int x) { //Não aparece ordenado
    if (a != NULL) {
        if (a->valor < x) {
            printf("%d ", a->valor);
        }
        imprimeAte(a->dir, x);
        imprimeAte(a->esq, x);
    }
}

void imprimeAte1 (ABin a, int x){ //Versão Carlos, aparece ordenado. Não percebi porquê
    if(a!=NULL){
        imprimeAte(a->esq, x);
        if(a->valor<x){
            printf("%d ", a->valor);
            imprimeAte1(a->dir, x);
        }
    }
}


























