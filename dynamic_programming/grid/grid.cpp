/*se posicao = '.' -> caminho livre
# se posicao = '#' -> parede
# (1,1) é sempre um caminho livre
# Só se movimenta para a direita ou para baixo

# para evitar overflow usar '(a+b) % 10^9+7' ao inves de 'a+b' somente*/

//Student: Gustavo Sampaio Lima
//ID: 12623992
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MAXSIZE 1000

int main(){
    int rows = 0, columns = 0;
    cin >> rows >> columns;
    
    vector<vector<char>> board[MAXSIZE][MAXSIZE];
    vector<vector<int>> MEMO[MAXSIZE][MAXSIZE];

    char entry;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cin >> entry;
            if(entry == " ") cin >> entry;
                board[i][j] = entry;
                MEMO[i][j] = -1;
        }    
    }

    return 0;
}

