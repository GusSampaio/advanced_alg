#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

bool primo(ll n){
    //se for par, retorna falso => 2 é o unico primo
    if(n>2 and n%2 == 0) return false;

    //itera nos impares até a raiz quadrada => teoria dos numeros
    for(ll i=3; i*i <= n; i+=2) //usar raiz quadrada no for é caro, usamos entao i*i
        if(n%i == 0) return false;

    return true;
}

int main(){

    ll nro;

    cin >> nro;

    if(primo(nro))
        printf("%lld eh um nmr primo\n", nro);
    else
        printf("%lld n eh um nmr primo\n", nro);

}