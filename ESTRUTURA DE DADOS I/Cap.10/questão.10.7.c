#include "./polinomio.c"

Poli soma(Poli P, Poli Q) {
    Poli resultado;

    while (Q != NULL) {
        adt(Q->coef, Q->expo, &resultado);

        Q = Q->prox;
    }

    while (P != NULL) {
        adt(P->coef, P->expo, &resultado);

        P = P->prox;
    }

    return resultado;
}

int main() {
    Poli P = criar_termo(3, 5, criar_termo(-6, 2, criar_termo(1, 0, NULL)));
    Poli Q = criar_termo(7, 2, criar_termo(2, 3, criar_termo(-4, 1, NULL)));

    Poli resultado = soma(P, Q);
    exibe_polinomio(resultado);
}
