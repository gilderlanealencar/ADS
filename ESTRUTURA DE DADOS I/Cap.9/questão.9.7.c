#include "../listaEncadeada.c"

int igual(Lista L, Lista M) {
    if (tam(L) != tam(M)) {
        return 0;
    } else {
        while (L != NULL) {
            if (L -> item != M -> item) {
                return 0;
            }
            L = L -> prox;
            M = M -> prox;
        }
        return 1;
    }
}

int main() {
    Lista l = no(5, no(1, no(5, no(3, no(7, no(5, NULL))))));
    Lista m = no(5, no(1, no(5, no(3, no(7, no(5, NULL))))));
    Lista n = no(5, no(1, no(6, no(3, no(7, no(5, NULL))))));

    printf("%d\n", igual(l, m));
    printf("%d", igual(l, n));
    destroi(&l);
    destroi(&m);
    destroi(&n);

    return 0;
