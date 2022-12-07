#include "./lista_ordenada.c"


bool estaNaLista(Lista *l, ItemType x) {
    while (*l != NULL) {
        if ((*l)->item == x) {
            return true;
        }

        l = &(*l)->prox;
    }

    return false;
}


void inserirSR(ItemType x, Lista *l) {
    if (estaNaLista(l, x)) return;

    while (*l != NULL && (*l)->item < x) {
        l = &(*l)->prox;
    }

    *l = criar_no(x, *l);
}

int main() {
    Lista lista = NULL;
    
    inserirSR(1, &lista);
    inserirSR(7, &lista);
    inserirSR(2, &lista);
    inserirSR(1, &lista); 
    inserirSR(2, &lista); 

    exibir(lista);
