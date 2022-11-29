#include "../listaEncadeada.c"

void substitui(char x, char y, Lista L) {
   int cont = 0;

    while (L != NULL) {
        if (x == L -> item) {
            L -> item = y;
            cont++;
        }
        L = L -> prox;
    }
    if (cont == 0) {
        printf("Caractere nao encontrado!\n");
    }
}

int main() {
    Lista l = no('b', no('o', no('l', no('o', NULL))));

    substitui('o', 'a', l);
    exibe(l);
    destroi(&l);

    return 0;
}
