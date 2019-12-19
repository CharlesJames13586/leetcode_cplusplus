#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		int length = digits.length();
		vector<string> result;
		int len = result.size();
		vector<string> stringofDigits= { "",
						  "",    "abc", "def",
						  "ghi", "jkl", "mno",
						  "pqrs","tuv","wxyz" };
		for (int i = 0; i < length; i++) {
			result = this->add(result, stringofDigits[digits[i] - '0']);
			
		}
		return result;
	}
	vector<string> add(vector<string> temp, string stringsofDigit) {
		int vLen = temp.size();        //vLen向量temp的大小
		int sLen = stringsofDigit.length();      //sLen字符串strinfofDigit的长度
		vector<string> result;
		string stemp = "";
		if (vLen == 0) {
			for (int j = 0; j < sLen; j++) {
				stemp = "";
				stemp = stringsofDigit[j];
				result.push_back(stemp);
			}
		}
		else {
			for (int i = 0; i < vLen; i++) {
				for (int j = 0; j < sLen; j++) {
					stemp = "";
					stemp = temp[i] + stringsofDigit[j];
					result.push_back(stemp);
				}
			}
		}
		return result;
	}
};
/*
int main() {
	string digits;
	Solution solution;
	//输入数字
	int digit = 0;
	cin >> digit;
	digits = to_string(digit);
	vector<string> result;
	result = solution.letterCombinations(digits);
	int len = result.size();
	for (int i = 0; i < len; i++) {
		cout << result[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
