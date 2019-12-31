#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string say = countAndSay(n-1);
        int len = say.length();
        string result = "";
        int i = 0;
        int count = 1;
        while(i < len){
            if(i > 0){
                if(say[i] == say[i-1]){
                    count++;
                }else{
                    result += to_string(count) + to_string(say[i-1] - '0');
                    count = 1;
                }
            }
            i++;
        }
        result += to_string(count) + to_string(say[i-1] - '0');
        return result;
    }
};

int main(){
    Solution s;
    for(int i = 1; i < 11; i++){
        cout << s.countAndSay(i) << endl;
    }
    return 0;
}