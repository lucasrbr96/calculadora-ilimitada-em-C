#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

typedef struct no No;

struct lista {
	int tam;
	No * ini, * fim;
};

struct no {
	int info;
	No * prox;
};

Lista * criar() {
	Lista * l = malloc(sizeof(Lista));	
	l->tam = 0;
	l->ini = l->fim = NULL;
	return l;
}

void destruir(Lista * l) {
	if (l != NULL) {
		limpar(l);
		free(l);
	}
}

void limpar(Lista * l) {
	No * aux =  l->ini;
	while(aux != NULL) {
		l->ini = aux->prox;
		free(aux);
		aux = l->ini;
	}
	l->fim = NULL;
	l->tam = 0;
}

int tamanho(Lista * l) {
	return l->tam;	
}

int esta_vazia(Lista * l) {
	return tamanho(l) == 0;	
}

int ler_pos(Lista * l, int p) {
	No * aux; int i;
	if (p < 0 || p >= tamanho(l)) {
		printf("Posição inválida!\n");
		return -1;
	}
	for (aux = l->ini, i=0; i < p; i++) {
		aux = aux->prox;
	}
	return aux->info;
}

int primeiro(Lista * l) {
	return ler_pos(l, 0);
	// return l->ini != NULL ? l->ini->info : -1;
}

int ultimo(Lista * l) {
	return ler_pos(l, tamanho(l)-1);
	//return l->fim != NULL ? l->fim->info : -1;
}

int buscar(Lista * l, int v) {
	int p = 0;
	No * aux =  l->ini;
	while(aux != NULL) {
		if (aux->info == v) {
			return p;
		}
		aux = aux->prox;
		p++;
	}
	return -1;
	/* 
	int i;
	for (i=0; i<tamanho(l); i++) {
		if (ler_pos(i) == v) {
			return i;
		}
	}
	return -1;
	*/	
}

void imprimir(Lista * l) {
	int i;
	printf("[ ");
	No * aux =  l->ini;
	while(aux != NULL) {
		printf("%d ", aux->info);
		aux = aux->prox;
	}
	printf("]\n");
}

void escrever_pos(Lista * l, int p, int v) {
	int i;
	No * aux;
	if (p < 0 || p >= tamanho(l)) {
		printf("Posição inválida!\n");
		return;
	}
	for (aux = l->ini, i=0; i < p; i++) {
		aux = aux->prox;
	}	
	aux->info = v;
}

void inserir_pos(Lista * l, int p, int v) {
	int i, tam = tamanho(l);
	No * aux, * aux2;
	if (p < 0 || p > tam) {
		printf("Posição inválida!\n");
		return;
	}	
	aux2 = malloc(sizeof(No));
	aux2->info = v;
	if (p == 0) {
		aux2->prox = l->ini;
		l->ini = aux2;
	} else {
		for (aux = l->ini, i=0; i < p-1; i++) {
			aux = aux->prox;
		}	
		aux2->prox = aux->prox;
		aux->prox = aux2;
	}
	if (p == tam) {
		l->fim = aux2;
	}
	l->tam++;
}

void inserir_primeiro(Lista * l, int v) {
	//inserir_pos(l, 0, v);
	No * aux = malloc(sizeof(No));
	aux->info = v;
	aux->prox = l->ini;
	l->ini = aux;
	if (l->tam == 0) {
		l->fim = aux;
	}
	l->tam++;
}


void inserir_ultimo(Lista * l, int v) {
	inserir_pos(l, tamanho(l), v);
}

int remover_pos(Lista * l, int p) {
	int i, v, tam = tamanho(l);
	No * aux = NULL, * aux2;
	if (p < 0 || p >= tam) {
		printf("Posição inválida!\n");
		return -1;
	}		
	if (p == 0) {
		aux2 = l->ini;
		l->ini = aux2->prox;
	} else {
		for (aux = l->ini, i=0; i < p-1; i++) {
			aux = aux->prox;
		}		
		aux2 = aux->prox;
		aux->prox = aux2->prox;
	}
	if (p == tam-1) {
		l->fim = aux;
	}
	v = aux2->info;
	free(aux2);
	l->tam--;
	return v;
}

int remover_primeiro(Lista * l) {
	//return remover_pos(l, 0);
	int v;
	if (l->tam == 0) {
		printf("Lista vazia!\n");
		return -1;
	}		
	No * aux = l->ini;
	l->ini = aux->prox;
	v = aux->info;
	free(aux);
	if (l->tam == 1) {
		l->fim = NULL;
	}
	l->tam--;
	return v;
}

int remover_ultimo(Lista * l) {
	//return remover_pos(l, tamanho(l)-1);	
	int i, v, tam = tamanho(l);
	No * aux = NULL, * aux2;
	if (l->tam == 0) {
		printf("Lista vazia!\n");
		return -1;
	}		
	aux2 = l->fim;
	if (l->tam == 1) {
		l->ini = NULL;
		l->fim = NULL;
	} else {
		for (aux = l->ini, i=0; i < tam-2; i++) {
			aux = aux->prox;
		}		
		aux->prox = NULL;
		l->fim = aux;
	}
	v = aux2->info;
	free(aux2);
	l->tam--;
	return v;
}

Lista * concatenar(Lista * l1, Lista * l2) {
	Lista * l3 = criar();
	No * aux = l1->ini, * aux2;
	while(aux != NULL) {
		aux2 = malloc(sizeof(No));
		aux2->info = aux->info;
		aux2->prox = NULL;
		if (l3->tam == 0) {
			l3->ini = aux2;
		} else {
			l3->fim->prox = aux2;
		}
		l3->fim = aux2;
		l3->tam++;
		aux = aux->prox;
	}
	aux = l2->ini;
	while(aux != NULL) {
		aux2 = malloc(sizeof(No));
		aux2->info = aux->info;
		aux2->prox = NULL;
		if (l3->tam == 0) {
			l3->ini = aux2;
		} else {
			l3->fim->prox = aux2;
		}
		l3->fim = aux2;
		l3->tam++;
		aux = aux->prox;
	}
	return l3;
}

void remover(Lista * l, int v) {
	int i, p = 0, tam = tamanho(l);
	No * aux = NULL, * aux2 =  l->ini;
	while(aux2 != NULL) {
		if (aux2->info == v) {
			break;
		}
		aux = aux2;
		aux2 = aux2->prox;
		p++;
	}
	if (aux2 == NULL) {
		return;
	}
	if (p == 0) {
		aux2 = l->ini;
		l->ini = aux2->prox;
	} else {
		for (aux = l->ini, i=0; i < p-1; i++) {
			aux = aux->prox;
		}		
		aux2 = aux->prox;
		aux->prox = aux2->prox;
	}
	if (p == tam-1) {
		l->fim = aux;
	}
	v = aux2->info;
	free(aux2);
	l->tam--;
}
