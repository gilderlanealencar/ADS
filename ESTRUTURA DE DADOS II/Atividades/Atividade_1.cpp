#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef int Item;
typedef struct arv{
    struct arv* esq;
    Item item;
    struct arv* dir;
} *Arv;

Arv arv_cria(Item x, Arv e, Arv d){
        Arv n = (Arv)malloc(sizeof(struct arv));
        n->esq = e;
        n->item = x;
        n->dir = d;
        return n;
}
Arv arv_vazia(void){
    return NULL;
}

int vazia(Arv a){
    return a == NULL;
}

void arv_imprime(Arv a){
    if(!vazia(a)){
        cout<<"<"<<a->item;
        arv_imprime(a->esq);
        arv_imprime(a->dir);
        cout<<">";
    }
    else
        cout<<"<>";
}

int main(){
    Arv a1 = arv_cria(4,arv_vazia(),arv_vazia());
    Arv a2 = arv_cria(2,arv_vazia(),a1);
    Arv a3 = arv_cria(3,arv_vazia(),arv_vazia());
    Arv a4 = arv_cria(1,a2,a3);
    arv_imprime(arv2);
}
