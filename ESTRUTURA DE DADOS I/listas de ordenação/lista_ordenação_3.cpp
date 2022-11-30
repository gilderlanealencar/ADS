#include<stdio.h>
#include<iostream>
using namespace std;

void intercala(int vetor[], int inicio, int meio, int fim){
    int *w = malloc((fim+inicio+1)*sizeof(int));
    if(w != NULL){
        int i = inicio, j = meio + 1, k = 0;
        while(i<=meio && j<=fim)
            if(vetor[i] < vetor[j]) w[k++] = vetor[i++];
            else w[k++] = vetor[j++];
        while(i<= meio) w[k++] = vetor[i++];
        while(j<=fim) w[k++] = vetor[j++];
        for(k=0; k<=fim-inicio; k++) vetor[inicio+k] = w[k];
        free(w);
    }
    else{
        printf("erro");
    }
};
void merge_sort(int v[],int inicio, int fim){
    if(inicio == fim) return;
    int meio = (fim+fim)/2;
    merge_sort(v,inicio,meio);
    merge_sort(v,meio+1,fim);
    intercala(v,inicio,meio,fim);
};

int main(){
   int vetor[6] = {7, 9, 4, 3,6,1};
   int i;



   printf("\n2.Vetor ordenado:\n");
   for(i = 0; i <= 5; i++){
      printf("%d ", vetor[i]);
   }
   printf("\n");
}
