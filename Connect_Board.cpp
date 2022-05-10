//
//  Connect_Board.cpp
//  connect_n_project
//
//  Created by Brendan Larson on 2/20/22.
//

#include "Connect_Board.hpp"
#include <iostream>
#include <string>

using namespace std;

Connect_Board::Connect_Board(int input_columns, int input_rows, int n){
    if(input_columns <= 0){
        cerr << "Invalid column input" << endl;
        exit(1);
    }
    else if(input_rows <= 0){
        cerr << "Invalid row input" << endl;
        exit(1);
    }

    nColumns = input_columns;
    nRows = input_rows;
    empty = nRows * nColumns;                    // we start completely empty, then can edit
    N = n;

    for(int i = 0; i < nColumns * 2 + 1; i++){
        if(i % 2 == 0){
            a[0][i] = '+';
        }
        else{
            a[0][i] = '-';
        }
    }

    for(int j = 1; j < nRows + 1; j++){
        for(int k = 0; k < nRows * 2 + 1; k++){
            if(k % 2 == 0){
                a[j][k] = '|';
            }
            else{
                a[j][k] = ' ';
            }
        }
    }
}

int Connect_Board::cols() const{
    return nColumns;
    }

int Connect_Board::rows() const{
    return nRows;
}

int Connect_Board::num_empty() const{
    return empty;
}

int Connect_Board::checker_at(int column, int row) const{
    if(a[row][column] == 'X'){
        return 1;
    }
    else if(a[row][column] == 'O'){
        return -1;
    }
    else{
        return 0;
    }
}

void Connect_Board::display() const{
    for(int j = nRows; j >= 0; j--){
        for(int k = 0; k < nColumns * 2 + 1; k++){
            cout << a[j][k];
        }
        cout << endl;
    }
}

void Connect_Board::make_move(int column, char checker){
    int col = column * 2 - 1;
    for(int i = 1; i < nRows + 1; i++){
        if(checker_at(col, i) == 0){
            a[i][col] = checker;
            empty--;
            moves_row.push(i);
            moves_column.push(col);
            return;
        }
    }
}

void Connect_Board::undo_move(){
    if(moves_row.size() > 0){
        a[moves_row.top()][moves_column.top()] = ' ';
        moves_column.pop();
        moves_row.pop();
    }
    empty++;
}

int Connect_Board::completed(){
    int col, row, token;
    if(moves_column.empty()){
        return 0;
    }
        
    col = moves_column.top();
    row = moves_row.top();
    token = checker_at(col, row);
    char piece;

    if(token == 1){
        piece = 'X';
    }
    else if(token == -1){
        piece = 'O';
    }
    else{
        piece = ' ';
    }

    if(completed_row(piece, col, row) == N){
        return token;
    }
    else if(completed_col(piece, col, row) == N){
        return token;
    }
    else if(completed_diag_1(piece, col, row) == N){
        return token;
    }
    else if(completed_diag_2(piece, col, row) == N){
        return token;
    }

    return 0;
}


int Connect_Board::completed_row(char token, int col, int row){
    int counter = 1;
    int i = row - 1;

    while(token == a[i][col]){
        counter++;
        i -= 1;
    }

    i = row + 1;
    while(token == a[i][col]){
        counter++;
        i += 1;
    }
    return counter;
}

int Connect_Board::completed_col(char token, int col, int row){
    int counter = 1;
    int total_cols = nColumns * 2 + 1;
    int i = col - 2;
    
    if(i > 0){
        while(token == a[row][i]){
            counter++;
            i -= 2;
        }
    }
    
    i = col + 2;
    if(i < total_cols){
        while(token == a[row][i]){
            counter++;
            i += 2;
        }
    }

    return counter;
}

int Connect_Board::completed_diag_1(char token, int col, int row){
    int counter = 1;
    int i = col - 2;
    int j = row - 1;
    while(token == a[j][i]){
        counter++;
        i -= 2;
        j -= 1;
    }

    i = col + 2;
    j = row + 1;
    while(token == a[j][i]){
        counter++;
        i += 2;
        j += 1;
    }

    return counter;
}

int Connect_Board::completed_diag_2(char token, int col, int row){
    int counter = 1;
    int i = col - 2;
    int j = row + 1;
    while(token == a[j][i]){
        counter++;
        i -= 2;
        j += 1;
    }

    i = col + 2;
    j = row - 1;
    while(token == a[j][i]){
        counter++;
        i += 2;
        j -= 1;
    }

    return counter;
}
