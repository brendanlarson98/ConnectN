//
//  Game.hpp
//  connect_n_project
//
//  Created by Brendan Larson on 2/20/22.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Connect_Board.hpp"
#include "Player.hpp"

class Game{
public:
    Game(int n, SmartPlayer x, HumanPlayer o);
    void play();
    bool completed(int &winner);
    void take_turn();
    int checker_at(int c, int r);
    ~Game(){};
      // We prevent a Game object from being copied or assigned by
      // making the copy constructor and assignment operator unavailable.
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
private:
    int N;
    int turn_count;
    int winner;
    Connect_Board m_board;
    SmartPlayer* ex;
    HumanPlayer* oh;
};

#endif /* Game_hpp */
