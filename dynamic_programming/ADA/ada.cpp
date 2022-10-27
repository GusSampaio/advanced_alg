//Student: Gustavo Sampaio Lima
//ID: 12623992
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> price_letters(26);
int N = 0, M = 0;
long long int memo[2005][2005];

long long int LCS(int i,int j, vector<char> &vec_N, vector<char> &vec_M){
    if(i < 0 or j < 0) //Out of limits
        return 0;
    if(memo[i][j] != 0)
        return memo[i][j];
    else if(vec_N[i] == vec_M[j]){
        memo[i][j] = price_letters[vec_N[i] - 97] + LCS(i-1, j-1, vec_N, vec_M);
        return memo[i][j];
    }
    else{
        memo[i][j] = max(LCS(i-1, j, vec_N, vec_M), LCS(i, j-1, vec_N, vec_M));
        return memo[i][j];
    }
}   

int main(){
    cin >> N >> M; //row(N) by column(M)
    memset(memo, 0, sizeof(memo)); //matrix used to memoize

    for(int i = 0; i < 26; i++){
        cin >> price_letters[i];
    }
    
    vector<char> vec_N(N);
    for(int i = 0; i < N; i++){
        cin >> vec_N[i];
    } 

    vector<char> vec_M(M);
    for(int i = 0; i < M; i++){
        cin >> vec_M[i];
    }

    LCS(N-1, M-1, vec_N, vec_M);
    cout << memo[N-1][M-1];
    return 0;
}