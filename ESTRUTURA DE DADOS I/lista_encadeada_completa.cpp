#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class No{
	public:
		int mat;
		char nome[23];
		No *prox;
		No *ant;
		No(int m,char n[23]){
			mat=m;
			strcpy(nome,n);
			prox=NULL;
			ant=NULL;
		}
};

class Lista{
	public:
		No *inicio;
		No *fim;

	    Lista(){
	    	inicio = NULL;
	    	fim = NULL;
		}
		void addToFinal(int m, char n[23]){
		    No *novo = new No(m,n);
		    if(inicio == NULL){
                inicio = novo;
                fim = novo;
		    }
		    else{
                fim->prox = novo;
                novo->ant = fim;
                fim = novo;
		    }
		}

		void addToIni(int m, char n[23]){
		    No *novo = new No(m,n);
		    if(fim == NULL){
                inicio = novo;
                fim = novo;
		    }
		    else{
                novo->prox = inicio;
                inicio->ant = novo;
                inicio = novo;
		    }
		}

		void addOrd(int m, char n[23]){
            No *novo = new No(m,n);
            if(fim == NULL){
                inicio = novo;
                fim = novo;
            }
            else{
                if(novo->mat < inicio->mat){
                    novo->prox = inicio;
                    inicio->ant = novo;
                    inicio = novo;
                }
                else if(novo->mat > fim->mat){
                    fim->prox = novo;
                    novo->ant = fim;
                    fim = novo;
                }
                else{
                    No *item = inicio;
                    while(item != NULL){
                        if(novo->mat < item->mat){
                            novo->ant = item->ant;
                            item->ant = novo;
                            novo->ant->prox = novo;
                            novo->prox = item;
                            break;
                        }
                        item = item->prox;
                    }
                }
            }
		}
		bool vazia(){
            return (inicio == NULL);
		}
		void mostraIniFim(){
				if(vazia()){
                    printf("Vazia");
				}
				else{
                    No *item = inicio;
                    while(item != NULL){
                        cout<<item->mat<<" "<<item->nome;
                        item = item->prox;
                    }
				}
		}

		void mostraFimIni(){
			if(vazia()){
                printf("vazia");
			}
			else{
                No *item = fim;
                while(item != NULL){
                    cout<<item->mat<<item->nome;
                    item = item->ant;
                }
			}

		}

		int removerFinal(){
			No *atual = fim;
			fim = fim->ant;
			fim->prox = NULL;
			free(atual);
		}

		int removerInicio(){
			No *atual = inicio;
			inicio = inicio->prox;
			inicio->ant = NULL;
			free(atual);
		}
		int remover(int mat){
			No *atual = inicio;
			while(atual != NULL){
                if(atual->mat == mat){
                    if(atual == inicio){
                        inicio = inicio->prox;
                        inicio->ant = NULL;
                    }
                    else if(atual == fim){
                        fim = fim->ant;
                        fim->prox = NULL;
                    }
                    else{
                        atual->ant->prox = atual->prox;
                        atual->prox->ant = atual->ant;
                    }
                    free(atual);
                    return 1;
                }
                atual = atual->prox;
			}
			return 0;
    	}
};
main(){
   Lista *l=new Lista();

   l->addOrd(1,"Joana Oliveira");
   l->addOrd(10,"Cristiano Oliveira");
   l->addOrd(8,"Joao");
   l->addOrd(4,"Fabio");
   l->mostraIniFim();

   if (l->remover(4)==1)
       cout<<"\nElemento removido!!";
   else
       cout<<"\nElemento nao encontrado!!";
   l->mostraIniFim();

}
