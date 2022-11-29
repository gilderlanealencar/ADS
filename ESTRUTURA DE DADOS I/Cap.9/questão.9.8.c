#include "./listaEncadeada.c"

ItemType enesimo(Lista l, int n) {
    int contador = 1;

    while (contador < n) {
        if (l == NULL) {
            printf("\n\n## Erro fatal!");

            return 0;
        }

        l = l->prox;
        contador++;
    }

    return l->item;
}

int main() {
    Lista lista = criar_no(2, criar_no(3, criar_no(5, NULL)));

    printf("Lista: ");
    exibir(lista);

    printf("\n\nenesimo(lista, 2): " format, enesimo(lista, 2));
}
