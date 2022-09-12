//Student: Gustavo Sampaio Lima
//ID: 12623992
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<float> analyse_gap(int sprinkler_position, int sprinkler_radio, float camp_width, float camp_height);
int min_calc(vector<vector<float>> gaps, float camp_width);

int main(){
    float amnt_sprinklers = 0, sprinkler_radio = 0, sprinkler_position = 0, min_sprinklers = 0;
    float camp_width = 0, camp_height = 0;
    while(cin >> amnt_sprinklers >> camp_width >> camp_height){
        vector<int> sprinklers;
        vector<vector<float>> gaps;

        for(int i = 0; i < amnt_sprinklers; i++){
            cin >> sprinkler_position >> sprinkler_radio;
            if(sprinkler_radio*2 >= camp_height){
                gaps.push_back(analyse_gap(sprinkler_position, sprinkler_radio, camp_width, camp_height));
            }
        }

        sort(gaps.begin(), gaps.end());

        min_sprinklers = min_calc(gaps, camp_width);
        cout << min_sprinklers << endl;
    }

    return 0;
}

vector<float> analyse_gap(int sprinkler_position, int sprinkler_radio, float camp_width, float camp_height){
    
    vector<float> coordenates(2);
    float real_distance = sqrt(pow(sprinkler_radio, 2) - (pow(camp_height,2)/4.0));
    if(real_distance < 0) real_distance *= (-1);
    
    coordenates[0] = sprinkler_position - real_distance;
    coordenates[1] = sprinkler_position + real_distance;
    
    if(coordenates[0] < 0)
        coordenates[0] = 0;
    if(coordenates[1] > camp_width)
        coordenates[1] = camp_width;

    return coordenates;
}

int min_calc(vector<vector<float>> gaps, float camp_width){
    float lt_one = 0, result = 0;
    int aux1 = -1, aux2 = 0;
    float ft_one = 0;
    
    while (aux1 < (int) gaps.size()  - 1){
        aux2 = aux1 + 1;
        
        if (gaps[aux2][0] > lt_one)
            return -1;
        
        ft_one = lt_one;
        
        while (aux2 < (int) gaps.size()){
            if (gaps[aux2][0] <= lt_one){
                ft_one = max(ft_one, gaps[aux2][1]);
                aux1 += 1;
            }
            aux2 += 1;
        }

        lt_one = ft_one;
        result += 1;
        
        if (lt_one >= camp_width)
            break;
    }

    if (lt_one >= camp_width)
        return result;
    else 
        return -1;
}