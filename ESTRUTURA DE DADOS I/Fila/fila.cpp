#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class No{
	public:
		char nome;
		No *prox;
		No(char n){
			nome = n;
			prox = NULL;
		}
};

class Fila{
	public:
		No *inicio;
		No *fim;

		Fila(){
			inicio = NULL;
			fim = NULL;
		}

		void append(char n){
			   No *novo= new No(n);
			   if (isEmpty()){
			           inicio = novo;
			           fim = novo;
               }
               else{
                       fim->prox = novo;
                       fim = novo;
               }
		}

		char pop(){
			    if (inicio == NULL){
			            cout<<"\nlista vazia!!!";
                }
                else{
                        No *exclui;
                                cout<< inicio-> nome <<endl;
                                exclui = inicio;
                                inicio = inicio -> prox;
                                free(exclui);
                }
		}

		bool isEmpty(){
			return (inicio == NULL);
		}

	    public: void popAll(){
	             if (inicio == NULL){
	                          cout<<"\nlista vazia!!!";
                 }
                 else{
                        No *exclui;
                        //No *item = topo;
                        while(inicio != NULL ){
                               cout<< inicio->nome <<endl;
                               exclui = inicio;
                               inicio = inicio -> prox;
                               free(exclui);
                               }
                        }


		}

};

int main(){
        Fila *f = new Fila();

        f->append('a');
        f->append('b');
        f->append('c');
        f->append('d');
        f->append('e');
        f->pop();
        f->pop();
        f->popAll();






}
