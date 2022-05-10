//
//  Game.cpp
//  connect_n_project
//
//  Created by Brendan Larson on 2/20/22.
//

#include "Game.hpp"
#include <iostream>
#include <string>

// How do I want the game implemented. Establish Players. Establish board.
Game::Game(int n, SmartPlayer x, HumanPlayer o) : m_board(n * 2 + 1, n * 2 + 1, n){
    ex = &x;
    oh = &o;
    N = n;
    turn_count = 0;
}

bool Game::completed(int &winner){
    winner = m_board.completed();
    if(winner != 0){
        return true;
    }

    if(m_board.num_empty() == 0){
        return true;
    }

    return false;
}

void Game::play(){
    while(!completed(winner)){
        take_turn();
    }
    
    m_board.display();
    
    if(winner == 1){
        std::cout << "Computer wins!" << std::endl;
    }
    else if(winner == -1){
        std::cout << "Human wins!" << std::endl;
    }
    else{
        std::cout << "Tie Game!" << std::endl;
    }
}

void Game::take_turn(){
    if(turn_count % 2 == 0){
        turn_count++;
        m_board.display();
        return oh->make_move(&m_board);
    }
    else{
        turn_count++;
        return ex->make_move(&m_board);
    }
}
