#include "./listaEncadeada.c"

ItemType soma(Lista l) {
    ItemType somatorio;

    while (l != NULL) {
        somatorio += l->item;

        l = l->prox;
    }

    return somatorio;
}

int main() {
    Lista lista = criar_no(3, criar_no(3, criar_no(5, NULL)));

    printf("Lista: ");
    exibir(lista);

    printf("\n\nSoma dos itens da lista: " format, soma(lista));
}
