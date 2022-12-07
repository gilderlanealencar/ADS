#include<stdio.h>
#include<iostream>
#define troca(a,b) {int x=a; a=b; b=x;}
using namespace std;
void Quick(int vetor[10], int inicio, int fim);

int main(){
   int vetor[6] = {7, 9, 4, 3,6,1};
   int i;
   Quick(vetor, 0, 5);
   printf("\n2.Vetor ordenado:\n");
   for(i = 0; i <= 5; i++){
      printf("%d ", vetor[i]);
   }
   printf("\n");
}

int particiona(int v[], int inicio, int fim){
   int x = v[inicio];
   inicio--;
   fim++;
   while(inicio<fim){
      do fim--; while(v[fim]>x);
      do inicio++; while(v[inicio]<x);
      if(inicio<fim) troca(v[inicio], v[fim]);
   }
   return fim;
}

void Quick(int vetor[10], int inicio, int fim){
        if(inicio>=fim) return;
        int meio = particiona(vetor,inicio,fim);
        Quick(vetor,inicio,meio);
        Quick(vetor,meio+1,fim);
}
