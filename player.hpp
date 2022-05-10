//
//  Player.hpp
//  connect_n_project
//
//  Created by Brendan Larson on 2/20/22.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Connect_Board.hpp"
#include <string>
#include <iostream>

class Player{
protected:
    Player(char token): m_token(token){};
    virtual void undo_move(Connect_Board *board);
    virtual ~Player(){};
private:
    char m_token = 'O';
};

class SmartPlayer: public Player{
public:
    SmartPlayer(char token): Player(token){m_token = token;};
    virtual void make_move(Connect_Board *board);
    int make_best_decision(Connect_Board *board, int depth, int player_num);
    virtual ~SmartPlayer(){};
private:
    char m_token;
    int inf = 2000000;
    int max_depth = 4; // maximum recursion depth of the smart player
};

class HumanPlayer: public Player{
public:
    HumanPlayer(char token): Player(token){m_token = token;};
    virtual void make_move(Connect_Board *board);
    virtual ~HumanPlayer(){};
private:
    char m_token;
};


#endif /* Player_hpp */
