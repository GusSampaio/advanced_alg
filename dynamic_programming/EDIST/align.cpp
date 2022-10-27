//Student: Gustavo Sampaio Lima
//ID: 12623992
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MIN(a,b,c) min(min(a,b),c)

#define MAX 2500

char str1[MAX];
char str2[MAX];

int len1 = 0;
int len2 = 0;

int delta = 1;

int MEMO[MAX+1][MAX+1];

//Delta doesn't care if the change is between vowels/vowels or vowels/consonants
int alpha(int i, int j){
	char cx = str1[i];
	char cy = str2[j];

	if(cx == cy)
		return 0;
    return 1;

}

int align(int i, int j){
    if (MEMO[i][j] != -1)
    	return MEMO[i][j];

    if (i == 0){
    	MEMO[0][j] =  j*delta;
    	return MEMO[0][j];
    }
    if (j == 0){
    	MEMO[i][0] = i*delta;
    	return MEMO[i][0];
    }

	MEMO[i][j] =  MIN(alpha(i-1,j-1) + align(i-1,j-1), delta + align(i-1,j), delta + align(i,j-1));

	return MEMO[i][j];
}

int main(){
	int cases_amount = 0;
	cin >> cases_amount;

	for(int i = 0; i < cases_amount; i++){
		cin >> str1;
		cin >> str2;
		len1 = strlen(str1);
		len2 = strlen(str2);
		memset(MEMO, -1, sizeof MEMO);
		cout << align(len1,len2) << endl;
	}

	return 0;
}