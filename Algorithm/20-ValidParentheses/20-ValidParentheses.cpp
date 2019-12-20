#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool flag = true;
        int l = s.length();
        stack <char> stk;
        char temp = NULL;
        for (int i = 0; i < l; i++) {
            switch (s[i]) {
                //左括号入栈
                case '(':
                case '{':
                case '[':
                    stk.push(s[i]);
                    break;
                //右括号匹配
                case ')':
                case '}':
                case ']':
                    //先检测栈是否为空
                    if (!stk.empty()) {
                        temp = stk.top();
                    }
                    else{
                        flag = false;
                        break;
                    }
                    //匹配失败的情况
                    if (!(s[i] == ')' && temp == '(' || s[i] == '}' && temp == '{' || s[i] == ']' && temp == '[')) {
                        flag = false;
                    }
                    stk.pop();
                    break;
                //出现其它情况默认失败
                default:
                    flag = false;
                    break;
            }
            if (flag == false)  //如果出现匹配失败，即刻退出匹配过程
                break;
        }
        if (flag == true) {
            if (!stk.empty()) { //退出匹配过程后，检测栈是否为空
                flag = false;
            }
        }
        return flag;
    }
};

//测试函数
/*
int main() {
    string s;
    Solution solution;
    while (s!="#") {
        cin >> s;
        if (solution.isValid(s)) {
            cout << "True" << endl;
        }
        else {
            cout << "False" << endl;
        }
    }
    
}
*/
/*
题目
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
    Output : true
    Example 2 :

    Input : "()[]{}"
    Output : true
    Example 3 :

    Input : "(]"
    Output : false
    Example 4 :

    Input : "([)]"
    Output : false
    Example 5 :

    Input : "{[]}"
    Output : true
*/
