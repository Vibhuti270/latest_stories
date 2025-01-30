#include <bits/stdc++.h>
using namespace std;
//set use kr skte h unique store krne hai to ek row ka ek col ka ek box ka

bool isValidSudoku(vector<vector<int>> &board){
    for(int i=0;i<9;i++){
        unordered_set<int> rowSet,colSet,boxSet;
        for(int j=0;j<9;j++){
            if(rowSet.count(board[i][j])){ 
                return false;
            }
            rowSet.insert(board[i][j]);
            
            if(colSet.count(board[j][i])){ 
                return false;
            }
            colSet.insert(board[j][i]);
            
            int boxRowIndex = 3*(i/3) + j/3;
            int boxColIndex = 3*(i%3) + j%3;
            
            if(boxSet.count(board[boxRowIndex][boxColIndex])){ 
                //cout"Box is not valid"<<endl;
                return false;
            } else{
                //cout"Box is valid"<<endl;
            }
            boxSet.insert(board[boxRowIndex][boxColIndex]);
        }
        
    }
    return true;
}

int main() {
    // Write C++ code here
    vector<vector<int>> sudoku_board = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 7, 2, 8, 6, 1, 7, 9},
};
    if(isValidSudoku(sudoku_board)){
        cout<<"Sudoku is valid"<<endl;
    } 
    else{
        cout<<"Sudoku is not valid"<<endl;
    }

    return 0;
}