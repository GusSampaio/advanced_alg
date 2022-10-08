//Student: Gustavo Sampaio Lima
//ID: 12623992
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> nos;
vector<int> vet_temps;

int cross(int n_nos);
int vai_para(int esqr, int dir);
int merge_sort(int esqr, int dir, int meio);

int main(){
    int tempos = 0;
    cin >> tempos;

    int n_nos = 0, novo_no = 0;
    for(int i = 0; i < tempos; i++){
        cin >> n_nos;
        for(int j = 0; j < n_nos; j++){
            cin >> novo_no;
            nos.push_back(novo_no);
        }
        cout << cross(n_nos) << endl;
        nos.clear();
        vet_temps.clear();
    }
    return 0;
}

int cross(int n_nos){
    for(int i = 0; i < n_nos; i++)
        vet_temps.push_back(0);
    return vai_para(0, n_nos-1);
}

int vai_para(int esqr, int dir){
    int contador = 0, meio = 0;
    if(dir > esqr){
        meio = (dir + esqr) / 2;
        contador += vai_para(esqr, meio);
        contador += vai_para(meio+1, dir);
        contador += merge_sort(esqr, dir, meio);
    } 
    
    return contador;
}

int merge_sort(int esqr, int dir, int meio){
    int a = esqr, b = meio + 1, c = esqr, contador = 0;

    while(a <= meio and b <= dir){
        if(nos[a] < nos[b]){
            vet_temps[c] = nos[a];
            a += 1;
            c += 1;
        }
        else{
            cout << "houve crossing\n";
            vet_temps[c] = nos[b];
            contador += (meio-a + 1);
            b += 1;
            c += 1;
        }
    }

    while(a <= meio){
        vet_temps[c] = nos[a];
        a += 1;
        c += 1;
    }

    while(b <= dir){
        vet_temps[c] = nos[b];
        b += 1;
        c += 1;
    }

    for(int i = 0; i < dir - esqr; i++){
        nos[i] = vet_temps[i];
    }
    
    return contador;
}