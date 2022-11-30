#include "./lista_ordenada.c"

void ins_decresc(ItemType x, Lista *l) {
    while (*l != NULL && (*l)->item > x) {
        l = &(*l)->prox;
    }

    *l = criar_no(x, *l);
}

int main() {
    Lista lista = NULL;
    
    ins_decresc(1, &lista);
    ins_decresc(7, &lista);
    ins_decresc(2, &lista);

    exibir(lista);
}
