#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuAndReturn(board);
    }
    bool solveSudokuAndReturn(vector<vector<char>>& board) {
        //尝试暴力求解
        int x = 0;
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){ //如果board[row][col]为空
                    for(int i = 1; i <= 9; i++){
                        board[row][col] = '0' + i;
                        if(isValid(board, row, col)){
                            //cout << "In process..." << endl;
                            if(solveSudokuAndReturn(board)){
                                return true;
                            }else{
                                board[row][col] = '.';
                            }
                        }else{
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }else{
                    x++;
                    if(x == 81){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board, int row, int col){
        //判断在(row,col)处填写的数字合不合法
        //cout << "Testing legitimacy..." << row << ' ' << col << endl;
        for(int i = 0; i < 9; i++){
            if(i != row){
                if(board[i][col] == board[row][col]){
                    return false;
                }
            }
            if(i != col){
                if(board[row][i] == board[row][col]){
                    return false;
                }
            }
        }
        for(int i = row / 3 * 3; i < row / 3 * 3 + 3; i++){
            for(int j = col / 3 * 3; j < col / 3 * 3 + 3; j++){
                if(i != row && j != col){
                    if(board[i][j] == board[row][col]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    vector<vector<char>> board = 
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    s.solveSudoku(board);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}