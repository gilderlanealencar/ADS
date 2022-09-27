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

class Pilha{
	public:
		No *topo;

		Pilha(){
			topo = NULL;
		}

		void push(char n){
                No *novo= new No(n);
                if (isEmpty()){
                        topo = novo;
                }
                else{
                        novo->prox = topo;
                        topo = novo;
                //      topo -> prox = novo;
                //      topo = novo;
                }

		}

		char pop(){
                if (topo == NULL){
                        cout<<"\nLista vazia!!!";
                }
                else{
                        No *exclui;
                        //No *item  = topo;
                        //while(topo!= NULL){
                                cout<< topo->nome <<endl;
                                exclui = topo;
                                topo = topo -> prox;
                                free(exclui);
                        //}
                }

		}

		int isEmpty(){
			    return (topo == NULL);
		}


};

int main(){
Pilha *p = new Pilha();

p->push('a');
p->push('b');
p->push('c');
p->pop();
p->pop();
p->pop();
p->pop();
}
