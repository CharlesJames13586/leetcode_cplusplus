#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printResult(vector<vector<int>> &result);

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		//判断nums的大小是否大于等于4
		int len = nums.size();
		vector<vector<int>> result;    //保存结果
		if (len < 4) {
			return result;
		}
		//首先对nums进行排序，使用<algorithm>的sort()函数
		sort(nums.begin(), nums.end());
		
		int left = 0, right = 0;       //左右指针
		int temp = 0;        //保存中间要进行判断的和
		vector<int> temps;
		//两层循环加双指针
		for (int i = 0; i < len-3; i++) {
			//防止重复
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			for (int j = i + 1; j < len-2; j++) {
				if (j > i + 1 && nums[j] == nums[j-1]) {
					continue;
				}
				left = j + 1;
				right = len-1;
				while (left < right) {
					//开始判断是否和target相等
					temp = nums[i] + nums[j] + nums[left] + nums[right];
					if (temp == target) {
						temps.clear();
						temps.push_back(nums[i]);
						temps.push_back(nums[j]);
						temps.push_back(nums[left]);
						temps.push_back(nums[right]);
						result.push_back(temps);
						//cout << nums[i] << ',' << nums[j] << ',' << nums[left] << ',' << nums[right] << endl;
						//两个do-while语句依旧是去重
						//注意判断left和right的合法性，避免过度增大或减小
						do {
							left++;
						} while (left<len && nums[left] == nums[left - 1]);
						do {
							right--;
						} while (right>j && nums[right] == nums[right + 1]);
					}
					else if (temp < target) {
						left++;
					}
					else if (temp > target) {
						right--;
					}
				}
			}
		}
		return result;
	}
};

//用于测试的主函数
int main() {
	vector<int> nums;
	int n = 0;
	cout << "请输入向量nums的个数：";
	cin >> n;
	cout << endl;
	int num = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		nums.push_back(num);
	}
	cout << "nums已输入完毕！" << endl;
	int target = 0;
	cout << "请输入target的值：";
	cin >> target;
	cout << endl;
	vector<vector<int>> result;
	Solution solution;
	result = solution.fourSum(nums, target);
	printResult(result);

	return 0;
}

void printResult(vector<vector<int>> &result) {
	cout << "A solution set is:" << endl;
	cout << "[" << endl;
	int len = result.size();
	for (int i = 0; i < len; i++) {
		cout << "[";
		int len_son = result[i].size();
		for (int j = 0; j < len_son; j++) {
			if (j == len_son - 1) {
				cout << result[i][j] << ' ';
			}
			else {
				cout << result[i][j] << ',' << ' ';
			}
		}
		if (i == len - 1) {
			cout << "]" << endl;
		}
		else {
			cout << "]" << ',' << endl;
		}
	}
	cout << "]" << endl;
}