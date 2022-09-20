#include <stdio.h>
#include <string.h>
#include "./pilhaS.h" // Pilha de char

int ehAbrindo(char item) {
    return item == '[' || item == '{' || item == '(';
}

int ehFechamentoValido( char topItem, char currentItem) {
    if(topItem == '[') {
        return currentItem == ']';
    } else if (topItem == '{') {
        return currentItem == '}';
    } else {
        return currentItem == ')';
    }
}

int verificarExpressao(char exp[]) {
    PilhaS pilha = criarPilhaS(strlen(exp));

    for (int i = 0; i < strlen(exp); i++) {
        if(ehAbrindo(exp[i])) {
            pushS(exp[i], pilha);
        } else {
            if(!ehFechamentoValido(pilha->item[pilha->topo], exp[i])) {
                return 0;
            } else {
                pushS(exp[i], pilha);
                
                popS(pilha);
                popS(pilha);
            }
        }
    }
}

int main() {

    char* exp = (char*)malloc(sizeof(char) * 700);
    
    printf("Expressao: ");
    scanf("%s", exp);

    int ehExpBalanceada = verificarExpressao(exp);

    if(ehExpBalanceada) {
        printf("Balanceada!\n");
    } else {
        printf("Nao Balanceada!\n");
    }
    
    system("pause");

}