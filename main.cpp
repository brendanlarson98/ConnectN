//
//  main.cpp
//  connect_n_project
//
//  Created by Brendan Larson on 2/20/22.
//

#include <iostream>
#include "Connect_Board.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include <string>

using namespace std;

int main(){
    int n = 3;
    bool good_input = false;
    char X = 'X';
    char O = 'O';

    while (!good_input){
        cout << "How big (max size of 10) would you like your game to be? " << endl;
        cin >> n;
        if (n > 2 && n < 11){
            good_input = true;
        }
        else{
            cout << "Invalid input, please pick a number between 3 and 10." << endl;
        }
    }
    
    
    SmartPlayer comp(X);
    HumanPlayer hum(O);
    Game game(n,comp,hum);
    game.play();
//
    return 0;
}
