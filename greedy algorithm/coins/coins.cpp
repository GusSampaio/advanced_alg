#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve_change(int change, vector<int> coins, int amount_coins, vector<int> &solution);

int main(){

    vector<int> coins = {100, 50, 25, 10, 5, 1};
    int amount_coins = (int) coins.size();

    int change = 0;

    cout << "What is the change? (in cents): ";
    cin >> change;

    vector<int> solution;
    
    int solution_exist = solve_change(change, coins, amount_coins, solution);

    if(solution_exist){
        cout << "A possible solution is: ";
        for( int i = 0; i < (int) solution.size(); i++) cout << solution[i] << " ";
    }
    else
        cout << "There's no possible solution.\n";

    return 0;
}

int solve_change(int change, vector<int> coins, int amount_coins, vector<int> &solution){
    int sum = 0, counter = 0;

    while (sum != change){
        if(sum + coins[counter] <= change){
            solution.push_back(coins[counter]);
            sum += coins[counter];
        }
        else if(counter == coins.size())
            return 0;
        else
            counter += 1;
    }

    return 1;
}