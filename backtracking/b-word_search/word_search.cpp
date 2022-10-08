//Student: Gustavo Sampaio Lima
//ID: 12623992
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<string> matrix;

int search_for_first_letter(string word, int matrix_y, int matrix_x);
int search_for_word(string word, int y_pos, int x_pos, int word_letter, int word_size);

int main(){
    int matrix_y = 0, matrix_x = 0;
    cin >> matrix_y >> matrix_x;
    
    string actual_line;
    for(int i = 0; i < matrix_y; i++){
        cin >> actual_line;
        matrix.push_back(actual_line);
    }

    int word_size = 0;
    cin >> word_size;
    string word;
    cin >> word;

    int answer = search_for_first_letter(word, matrix_y, matrix_x);
    answer ? printf("Yes") : printf("No");

    return 0;
}

int search_for_first_letter(string word, int matrix_y, int matrix_x){
    for(int i = 0; i < matrix_y; i++)
        for(int j = 0; j < matrix_x; j++)
            if(word[0] == matrix[i][j])
                if(search_for_word(word, i, j, 0, word.length()))
                    return 1;
    return 0;
}

int search_for_word(string word, int y_pos, int x_pos, int word_letter, int word_size){
    //Succeful final case
    if(word_letter == word_size)
        return 1;

    //Out of borders
    if(y_pos > (int) matrix.size() - 1 || x_pos > (int) matrix[0].size() - 1)
        return 0;
    if(y_pos < 0 || x_pos < 0)
        return 0;

    int case1 = 0, case2 = 0, case3 = 0, case4 = 0;
    if(matrix[y_pos][x_pos] == word[word_letter]){
        matrix[y_pos][x_pos] = '.';
        case1 = search_for_word(word, y_pos+1, x_pos, word_letter+1, word_size);
        case2 = search_for_word(word, y_pos, x_pos+1, word_letter+1, word_size);
        case3 = search_for_word(word, y_pos, x_pos-1, word_letter+1, word_size);
        case4 = search_for_word(word, y_pos-1, x_pos, word_letter+1, word_size);

        if(case1 == 1 || case2 == 1 || case3 == 1 || case4 == 1)
            return 1;
        else
            matrix[y_pos][x_pos] = word[word_letter];
    }

    return 0;
}