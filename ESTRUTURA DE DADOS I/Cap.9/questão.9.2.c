#include "../listaEncadeada.c"

int ocorrencias(int x, Lista L) {
    int cont = 0;

    while (L != NULL) {
        if (x == L -> item) {
            cont++;
        }
        L = L -> prox;
    }
    return cont;
}

int main() {
    int num;
    Lista l = no(5, no(1, no(5, no(3, no(7, no(5, NULL))))));

    printf("Numero a ser verificado: ");
    scanf("%d", &num);

    printf("%d ", ocorrencias(num, l));
    destroi(&l);

    return 0;
}
