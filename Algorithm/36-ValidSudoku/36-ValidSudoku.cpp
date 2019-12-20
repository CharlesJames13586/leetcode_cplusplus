#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool isValid = true;
        int digits[10] = {0};          //用来检验数独板合法性的辅助数组
        int digit = 0;  
        //判断行的合法性     
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] != '.'){
                    digit = board[i][j]-'0';
                    if(digits[digit] == 0){      //判断该次循环是否出现过数字digit
                        digits[digit] = digit;
                    }else{
                        isValid = false;
                        return isValid;
                    }  
                }
            }
            resetArray(digits, 0);     //数组名称是第一个变量的地址
        }
        //判断列的合法性
        for(int j = 0; j<9; j++){
            for(int i = 0; i<9; i++){
                if(board[i][j] != '.'){
                    digit = board[i][j]-'0';
                    if(digits[digit] == 0){      //判断该次循环是否出现过数字digit
                        digits[digit] = digit;
                    }else{
                        isValid = false;
                        return isValid;
                    }  
                }
            }
            resetArray(digits, 0);
        }
        //判断3*3小方格的合法性
        for(int i=1; i<9; i=i+3){      //定位到3*3小方格中心所在的行
            for(int j=1; j<9; j=j+3){  //定位到3*3小方格中心所在的列
                //扫描3*3小方格
                for(int k=-1; k<2; k++){
                    for(int l=-1; l<2; l++){
                        if(board[i+k][j+l] != '.'){
                            digit = board[i+k][j+l]-'0';
                            if(digits[digit] == 0){      //判断该次循环是否出现过数字digit
                                digits[digit] = digit;
                            }else{
                                isValid = false;
                                return isValid;
                            }  
                        }
                    }
                }
                resetArray(digits, 0);
            }
        }
        return isValid;
    }
    void resetArray(int* digits, int target){
        for(int i = 0; i<10; i++){
            *(digits+i) = target;
        }
    }
};

//用来测试的主函数
int main(){
    //由于9*9的数组输入过于麻烦，直接在leetcode上进行了测试并且通过了
    return 0;
}