#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int pesquisa_linear(int x, int v[], int n) {
   
   for(int i = 0; i < n; i++) {
      if(x == v[i]) {
         return i;
      }
   }

   return -1;
}

int pesquisa_binaria(int x, int v[], int l, int r) {
   int resultado;

   if (r > l) {

      int meio = (r - l) / 2;

      if (v[meio] == x) {
         return meio;
      } else if (v[meio] > x) {
         return pesquisa_binaria(x, v, l, meio - 1);
      } else if (v[meio] < x) {
         return pesquisa_binaria(x, v, meio + 1, r);
      }
   }
   return -1;
}

int* ler_valores() {

   int* valores = (int*) malloc(5*sizeof(int));

   printf("Digite valores: \n");

   for(int i = 0; i < 5; i++) {
      scanf("%d", &valores[i]);
   }

   return valores;
}

int ler_valor_desejado() {
   int procurado;

   printf("\nDigite valor a ser procurado: ");

   scanf("%d", &procurado);

   return procurado;

}

int main(){

   int* valores = ler_valores();
   int valor_procurado = ler_valor_desejado();

   int resultado;

   resultado = pesquisa_linear(valor_procurado, valores, 5);

   printf("\nResultado está na posição: %d (busca linear)\n", resultado);

   resultado = pesquisa_binaria(valor_procurado, valores, 0, 4);

   printf("\nResultado está na posição: %d (busca binária)\n", resultado);
      
}
