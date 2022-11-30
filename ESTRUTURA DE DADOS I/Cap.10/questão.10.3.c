#include "../listaOrdenada.c"

int insSR(Item x, Lista L) {
    if (L == NULL) return 0;
    if (x == L -> item) return 1;
    return insSR(x, L -> prox);
}


void ins(Item x, Lista *p) {
    while (*p != NULL && (*p) -> item > x) {
        p = &(*p) -> prox;
    }
    if (!insSR(x, *p)) *p = no(x, *p);
}


int main() {
    int num, alg;

    printf("Quantidade de inteiros: ");
    scanf("%d", &num);

    Lista l = NULL;

    for (int i = 0; i < num; i++) {
        printf("Insira o elemento: ");
        scanf("%d", &alg);

        ins(alg, &l);
    }

    exibe(l);
    destroi(&l);

    return 0;
}
