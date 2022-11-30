#include <string.h>
#include <iostream>
using namespace std;
#define troca(a,b) {int x=a; a=b; b=x;}


void bubble_sort(int v[], int n){
    for(int i = 1; i<n-1; i++){
        for(int j = 0; j<n-1; j++){
            if(v[j]>v[j+1]){
                troca(v[j], v[j+1]);
            }
        }
    }
}

int selecionar(int v[], int n){
    int i = 0;
    for(int j = 1; j<n; j++)
        if(v[i]<v[j]) i = j;
    return i;
}

void selection_sort(int v[], int n){
    while(n>1){
        troca(v[selecionar(v,n)], v[n-1]);
        n--;
    }
}

void insere(int x, int v[], int n){
    while(n > 0 && x < v[n-1]){
        v[n] = v[n-1];
        n--;
    }
    v[n] = x;
}

void insertion_sort(int v[], int n){
    for(int i = 0; i < n; i++)
        insere(v[i], v, i);
    }


int main(){
    const int n = 21;
    int v[] = {3};
    
    insertion_sort(v, n);
}
