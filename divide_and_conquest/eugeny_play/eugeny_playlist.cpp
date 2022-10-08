//Student: Gustavo Sampaio Lima
//ID: 12623992
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> tempos_reais;

int busca_binaria(int chave, int menor, int maior);

int main(){
    int n_pares = 0, n_escritos = 0;
    cin >> n_pares >> n_escritos;
    
     vector<pair<int,int>> pares;
    int par1 = 0, par2 = 0;
    for(int i = 0; i < n_pares; i++){
        cin >> par1 >> par2;
        pares.push_back(make_pair(par1, par2));
    }

    int ult_tempo = 0;
    for(int i = 0; i < n_pares; i++){
        ult_tempo += pares[i].first * pares[i].second;
        tempos_reais.push_back(ult_tempo);
    }

    //tamanho do vetor "tempos_reais"
    int t_t_r = tempos_reais.size();

    vector<int> tempos_req(n_escritos);
    for(int i = 0; i < n_escritos; i++){
        cin >> tempos_req[i];
    }
    
    for(int i = 0; i < n_escritos; i++){
        cout << busca_binaria(tempos_req[i], 0, t_t_r) + 1 << endl;
    }

    return 0;
}

int busca_binaria(int chave, int menor, int maior){
    if (menor > maior)
        return -1; 
   
    else{      
        int meio = (menor + maior) / 2;
        if(meio == 0 and chave <= tempos_reais[0])
            return meio;
        
        else if (chave <= tempos_reais[meio] and tempos_reais[meio - 1] < chave)
            return meio;
       
        else if (chave > tempos_reais[meio])        
            return busca_binaria(chave, meio + 1, maior);
               
        else                       
            return busca_binaria(chave, menor, meio - 1);
    } 
}