#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class No {
	public:
		int mat;
		char nome[23];
		No *prox;
		No *ant;

		No(int m, char n[23]) {
			mat = m;
			strcpy(nome, n);
			prox = NULL;
			ant = NULL;
		}
};

class Lista {
	public:
		No* inicio;
		No* fim;
	
	    Lista() {
	    	inicio = NULL;
	    	fim = NULL;
		}

		bool listaVazia() {
			return inicio == NULL;
		}	

		void addToFinal(int m, char n[23]) {
			No* novo = new No(m, n);

			if(listaVazia()) {
				fim = novo;
				inicio = fim;
			} else {
				fim->prox = novo;
				novo->ant = fim;
				fim = novo; 
			}	
		}
		
		void addToIni(int m, char n[23]) {
			No* novo = new No(m, n);

			if(listaVazia()) {
				inicio = novo;
				fim = inicio;
			} else {
				novo->prox = inicio;
				inicio->ant = novo;
				inicio = novo; 
			}	
		}
		
		void addOrd(int m, char n[23]) {
			No* last = inicio;
			No* atual = inicio;
			while(atual != NULL && atual->mat < m) {
				last = atual;
				atual = atual->prox;
			}

			if(atual == NULL && !listaVazia()) {
				No* novo = new No(m, n);
				last->prox = novo;
				novo->ant = last;
			} else if(atual == NULL && listaVazia()) {
				addToFinal(m, n);
			} else {
				No* novo = new No(m, n);
				novo->prox = atual;
				novo->ant = atual->ant;

				if(atual != inicio) atual->ant->prox = novo;
				atual->ant = novo;
			}

		}
		
		//mostra todos os elementos do inicio ao final da lista
		void mostraIniFim() {
			No* atual = inicio;
			while(atual != NULL) {
				printf("matricula: %d\nnome: %s\n\n", atual->mat, atual->nome);
				atual = atual->prox;
			}
		}
		
		// mostra todos os elementos do final ao inicio da lista
		void mostraFimIni() {
			No* atual = fim;
			while(atual != NULL) {
				printf("matricula: %d\nnome: %s\n\n", atual->mat, atual->nome);
				atual = atual->ant;
			}
		}
		
		int removerFinal() {
			No* aux = fim;
			fim->ant->prox = NULL;
			fim = fim->ant;
			free(aux);		
		}
		
		int removerInicio() {
			No* aux = inicio;
			inicio->prox->ant = NULL;
			inicio = inicio->prox;
			free(aux);		
		}

		int remover(int m) {
			No* atual = inicio;
			while(atual->mat != m && atual != NULL) {
				atual = atual->prox;
			}

			if(atual != NULL) {
				if(atual != inicio) atual->ant->prox = atual->prox;
				if(atual != fim) atual->prox->ant = atual->ant;
				free(atual);
				return 1;
			}

			return 0;
    	}
};

main() {
	Lista *l = new Lista();

	l->addOrd(1, "Gabriela");
	l->addOrd(10, "Gilderlane Alencar");
	// l->mostra();
	l->addOrd(8, "Gilmara");
	l->addOrd(4, "Maria");
	l->mostraIniFim(); 
	// l->mostraFimIni();	

	if (l->remover(4)==1) {
		cout<<"Elemento removido!!"<<endl;
	} else {
		cout<<"Elemento nao encontrado!!"<<endl;    
	}

	l->mostraIniFim(); 

}
