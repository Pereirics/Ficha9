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

//25/05/2022

//1.
//a)
int max1 (int x, int y) {
    if (x>y) return x;
    return y;
}

int altura1 (ABin a) {
    int r = 0;
    if (a != NULL) {
        r = 1 + max1(altura1(a->esq), altura1(a->dir));
    }
    return r;
}

//b)
int nFolhas1 (ABin a) {
    int r = 0;
    if (a != NULL) {
        r = 1 + nFolhas1(a->esq) + nFolhas1(a->dir);
    }
    return r;
}

//c)
ABin maisEsquerda1 (ABin a) {
    if (a != NULL) {
        while (a->esq != NULL) {
            a = a->esq;
        }
        return a;
    }
    return NULL;
}

//d)
void imprimeNivel1 (ABin a, int l) {
    int nivel = 0;

    if (nivel == l && a != NULL) {
        printf("%d ", a->valor);
    }
    else if (nivel < l && a != NULL) {
        imprimeNivel1(a->esq, l-1);
        imprimeNivel1(a->dir, l-1);
    }
}

//e)
int max2 (int x, int y, int z) {
    int max = x;
    if (y > x) {
        max = y;
    }
    if (max > z) return max;
    return z;
}

int procuraE1(ABin a, int x) {
    int r = 0;
    if (a != NULL) {
        if (a->valor == x) r = 1;
        max2(r, procuraE1(a->esq, x), procuraE1(a->dir, x));
    }
    return 0;
}

//2.
//f)
struct nodo *procura1 (ABin a, int x) {
    ABin r = NULL;
    if (a != NULL) {
        if (a->valor == x) r = a;
        if (a->valor < x) r = procura1(a->dir, x);
        r = procura1(a->esq, x);
    }
    return r;
}

//g)
int nivel1 (ABin a, int x) {
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

//h)
void imprimeAte2 (ABin a, int x) {
    if (a != NULL) {
        imprimeAte2(a->esq, x);
        if (a->valor < x) {
            printf("%d", a->valor);
            imprimeAte2(a->dir, x);
        }
    }
}



































































