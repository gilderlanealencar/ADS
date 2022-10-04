#include <iostream>
#include "./filaIncompleta.cpp"
#include "Data Structure\Stack in C\pilhaIncompleta.cpp"
#include <cctype>

using namespace std;

int main(){
    string frase;
    Fila* F = new Fila();
    Pilha* P = new Pilha();

    cout << "Frase: ";
    getline(cin,frase);

    for(int i = 0; i < frase.length(); i++){
        if(isalpha(frase[i])){
            F->append(toupper(frase[i]));
            P->push(toupper(frase[i]));
        }
    }

    while(F->isEmpty() == false && F->pop() == P->pop());

    if(F->isEmpty()){
        cout << "E palindroma" << endl;
    }else{
        cout << "Nao e palindroma" << endl;
    }
}
