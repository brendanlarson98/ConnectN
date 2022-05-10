//
//  Connect_Board.hpp
//  connect_n_project
//
//  Created by Brendan Larson on 2/20/22.
//

#ifndef Connect_Board_hpp
#define Connect_Board_hpp

#include <stdio.h>
#include <iostream>
#include <utility>
#include <stack>
#include <string>

class Connect_Board{
    public:
        Connect_Board(int input_columns = 9, int input_rows = 9, int n = 4);
        int cols() const;
        int rows() const;
        int num_empty() const;
        int checker_at(int column, int row) const;
        void display() const;
        void make_move(int column, char checker);
        void undo_move();
        int completed();
        int completed_row(char token, int col, int row);
        int completed_col(char token, int col, int row);
        int completed_diag_1(char token, int col, int row);
        int completed_diag_2(char token, int col, int row);

    private:
        int nColumns;
        int nRows;
        std::stack<int> moves_column;
        std::stack<int> moves_row;
        char a[1000][1000];
        int empty;
        int N;
};

#endif /* Connect_Board_hpp */
