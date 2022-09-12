//Student: Gustavo Sampaio Lima
//ID: 12623992

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void new_pairs(vector<int> species, int amnt_chambers, vector<int> &pairs);
float calc_imbalance(int amnt_chambers, vector<int> pairs, float AM);

int main(){
    int amnt_chambers = 0, amnt_species = 0, new_specie = 0, sets = 0;
    
    while(cin >> amnt_chambers >> amnt_species){
        vector<int> species;
        sets++;

        float AM = 0;

        for(int i = 0; i < amnt_species; i++){
            cin >> new_specie;
            species.push_back(new_specie);
            AM += new_specie;
        }

        AM = AM / amnt_chambers;
        
        int aux = amnt_species;
        while(aux++ < amnt_chambers*2)
            species.push_back(0);
            
        sort(species.begin(), species.end());
        
        vector<int> pairs(amnt_chambers*2);
        new_pairs(species, amnt_chambers, pairs);

        cout << "Set #" << sets << endl;
        for(int i = 0; i < amnt_chambers*2; i+=2){
            cout << " " << i/2 << ": ";
            if(pairs[i] > 0) cout << pairs[i] << " " ;
            if(pairs[i+1] > 0) cout << pairs[i+1];
            cout << endl;
        }

        cout << "IMBALANCE = ";
        float imbalance = calc_imbalance(amnt_chambers, pairs, AM);
        cout.precision(5);
        cout << fixed << imbalance << endl << endl; 
    }

    return 0;
}

void new_pairs(vector<int> species, int amnt_chambers, vector<int> &pairs){
    int j = 0;
    for(int i = 0; i < amnt_chambers; i++){
        pairs[j] = species[i];
        pairs[j+1] = species[amnt_chambers*2 - 1 - i];
        j += 2;
    }
}

float calc_imbalance(int amnt_chambers, vector<int> pairs, float AM){
    float imbalance = 0, result = 0, CM = 0;    

    for(int i = 0; i < amnt_chambers*2; i += 2){
        CM = pairs[i] + pairs[i + 1];
        result = CM - AM;
        if(result < 0) result *= (-1);
        imbalance += result;
    }

    return imbalance;
}