//
//  Player.cpp
//  connect_n_project
//
//  Created by Brendan Larson on 2/20/22.
//

#include "Player.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

void Player::undo_move(Connect_Board *board){
    board->undo_move();
}

void SmartPlayer::make_move(Connect_Board *board){
    int columns = board->cols();
    int best_score = inf * -1; // get the minimum score possible, so we can obtain the best score possible later.
    int best_move = 0;
    int score;
    for(int i = 1; i < columns+1; i++){
        if(board->checker_at(i * 2 - 1, columns) != 0){
            continue;
        }
        board->make_move(i, this->m_token); // make a move in each column.
        score = make_best_decision(board, max_depth, -1); // minimax algorithm, getting best decision recursively
        board->undo_move(); // undo the move previously made.
        if(score > best_score){
            best_score = score; // if our score is higher than the one previously set, set best score now.
            best_move = i; // default 0, set the best move to this column.
        }
    }
    
    board->make_move(best_move, this->m_token); // once we know best move, make it.
}

int SmartPlayer::make_best_decision(Connect_Board *board, int depth, int player_num){
    int score; // Player num for computer: 1, for human, -1
    int best_value = inf * player_num * -1; // get best value for current player
    int n = board->cols();
    char token;
    
    int check_winner = board->completed(); // check to see if someone won.
    if(depth <= 0 || (check_winner != 0)){
        return check_winner; // if we reached recursion depth or won, return our "winner"
    }
    if(player_num == 1){
        token = 'X';
    }
    else{
        token = 'O';
    }
    --depth;
    for(int i = 1; i < n+1; i++){
        if(board->checker_at(i * 2 - 1, n) != 0){
            continue;
        }
        board->make_move(i, token); // for each column, make move
        score = make_best_decision(board, depth, player_num * -1); // recursively call  our minimax algorithm, obtaining best decision for opponent.
        board->undo_move(); // undo move.
        if(player_num > 0){
            best_value = std::max(score, best_value); // if our computer, we want to obtain maximum
        }
        else{
            best_value = std::min(score, best_value); // for human, obtain minimum score.
        }
    }

    return best_value;
}

void HumanPlayer::make_move(Connect_Board *board){
    int col = 0, n = board->cols();
    bool state = false;
    while (!state){
        std::cout << "In which column (1 - " << n << ") would you like to play? ";
        std::cin >> col;
        if(board->checker_at(col * 2 - 1, n) == 0 && col > 0 && col <= n){
            state = true;
        }
        else{
            std::cout << "Please pick a non-full column between 1 and " << n << std::endl;
        }
    }
    
    board->make_move(col, this->m_token);
}
