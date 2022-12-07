#include<stdio.h>
#include<iostream>
#include <string.h>

using namespace std;

int pesquisa_linear(int x,int v[], int n){
        for(int i = 0; i< n; i++)
        if(x == v[i]){
            return 1;
        }
    return 0;
};
int pesquisa_binaria(int x,int v[], int n){
        int p = 0;
    int u = n - 1;
    while(p <= u){
        int m = (p+u)/2;
        if(x == v[m]) return 1;
        if(x < v[m]) u = m-1;
        else p = m+1;
    }
    return 0;
};

int main(){
  int n[] = {3,6,0,5,4,1};
  pesquisa_linear(2,n,5);
  pesquisa_binaria(1,n,1);

}
