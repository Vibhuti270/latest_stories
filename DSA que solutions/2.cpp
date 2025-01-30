#include <bits/stdc++.h>
using namespace std;

bool isValidRow(vector<vector<int>>& board, int row) {
    unordered_set<int> rowSet;
    for (int j=0; j<9; j++) {
        if (rowSet.count(board[row][j])){ 
            cout<<row+1<<"row is not valid"<<endl;
            return false;
        }
        rowSet.insert(board[row][j]);
    }
    cout<<row+1<<"row is Valid"<<endl;
    return true;
}

bool isValidColumn(vector<vector<int>>& board, int col) {
    unordered_set<int> colSet;
    for (int i=0; i<9; i++) {
        if (colSet.count(board[i][col])) {
            cout<<col+1<<"col is not Valid"<<endl;
            return false;}
        colSet.insert(board[i][col]);
    }
    cout<<col+1<<"col is Valid"<<endl;
    return true;
}

bool isValidBox(vector<vector<int>>& board, int startRow, int startCol) {
    unordered_set<int> boxSet;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            int num = board[startRow+i][startCol+j];
            if (boxSet.count(num)) {
                cout<<startRow/3<< ","<<startCol/3<<" is not valid" << endl;
                return false;
            } 
            boxSet.insert(num);
        }
    }
    cout<<startRow/3<<","<<startCol/3<<" box is Valid"<<endl;
    return true;
}

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
                return false;
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
    {5, 1, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 1, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9},
};
    for(int i=0;i<9;i++){
        isValidRow(sudoku_board,i);
    }
    for(int i=0;i<9;i++){
        isValidColumn(sudoku_board,i);
    }
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            isValidBox(sudoku_board,i,j);
        }
    }
    if(isValidSudoku(sudoku_board)){
        cout<<"Sudoku is valid"<<endl;
    } 
    else{
        cout<<"Sudoku is not valid"<<endl;
    }

    return 0;
}