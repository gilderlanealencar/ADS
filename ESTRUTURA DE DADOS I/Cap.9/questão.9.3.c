#include "../listaEncadeada.c"

Item ultimo(Lista L) {
    if (L == NULL) {
        return 0;
    } else {
        Item ultimo;

        while (L != NULL) {
            ultimo = L -> item;
            L = L -> prox;
        }
        return ultimo;
    }
}

int main() {
    Lista l = no('a', no('b', no('c', no('d', no('e', NULL)))));

    printf("%c", ultimo(l));
    destroi(&l);

    return 0;
}
