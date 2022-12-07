#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class No {
	public:
		int mat;
		char nome[23];
		No* prox;
		
		No(int m, char n[23]) {
			mat = m;
			strcpy(nome, n);			
			prox = NULL;
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

		void addToFinal(int m, char n[23]) {
			No* novo = new No(m, n);
			if(fim == NULL) {
				inicio = novo;
				fim = novo;
			} else {
				fim->prox = novo;
				fim = novo;
			}
		}
		
		int lst_vazia() {
			return (inicio == NULL);
		}

		void addToInicio(int m, char n[23]) {	
			No* novo = new No(m, n);
			if(inicio == NULL) {
				inicio = novo;
				fim = novo;
			} else {
				novo->prox = inicio;
				inicio = novo;
			}
		}

		void mostra() {
			if (lst_vazia()) {
				cout << "\nLista vazia!!!";
			} else {
				No* atual = inicio;

				while(atual != NULL) {
					cout << "Matrícula: " << atual->mat << ", ";
					cout << "Nome: " << atual->nome << endl;
					
					atual = atual->prox;
				}
			}	
		}
		
		int remove(int mat) {

			if(inicio->mat == mat) {
				No* aux = inicio;
				inicio = inicio->prox;
				free(aux);
				return 1;
			}

			No* tormv =	busca(mat);

			if(tormv != NULL) {
				No* aux = tormv->prox;
				tormv->prox = tormv->prox->prox;
				free(aux);
				return 1;
			}

			return 0;
		}
		
		// auxiliar no método remove
		// retornar o endereco do nó anterior
		No* busca(int mat) {
			No* atual = inicio;
			while(atual->prox != NULL) {
				if(atual->prox->mat == mat) {
					return atual;
				}
				atual = atual->prox;
			}

			return NULL;
		}
		
		void removeTodos() {
			No* atual = inicio;
			No* proximo = NULL;

			while(atual != NULL) {
				proximo = atual->prox;
				cout << "\n Apaga:" << atual->nome;
				free(atual);
				atual = proximo;						
			}

			inicio = atual;
		}
		
		// criar uma nova lista que seja o inverso da primeira
		void crialistainversa() {
			Lista* invertida = new Lista();
			No* atual = inicio;
			while(!lst_vazia() && atual->prox != NULL) {
				invertida->addToInicio(atual->mat, atual->nome);
			}

			invertida->mostra();
		}
		
		//inverter a propria lista
		void listainvertida() {
			if(lst_vazia()) {
				return;
			}

			No* atual = inicio;

			while(atual->prox != NULL) {

				int matricula = atual->prox->mat;
				char nome[23];
				strcpy(nome, atual->prox->nome);

				remove(matricula);

				addToInicio(matricula, nome);

			}
		}
};

main() {
	Lista* l = new Lista();

	l->addToFinal(1,"Joao");
	l->addToFinal(2,"Gabriela");
	l->addToFinal(3,"Fabiola");
	l->addToInicio(5,"Joana Oliveira");
	l->addToInicio(6,"Cristiano Oliveira");
	l->mostra();

	cout << endl;
 
	l->listainvertida();
	l->mostra();
}
