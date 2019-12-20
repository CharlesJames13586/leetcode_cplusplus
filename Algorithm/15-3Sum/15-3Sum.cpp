#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;//保存最终结果的向量
        vector<int> temp;//临时保存符合要求的集合
        sort(nums.begin(), nums.end());      //sort对给定区间的数进行升序排列
        //如果给定的数组长度不超过2，不用进行处理，没有符合要求的答案
        if (nums.size() <= 2) {        
            return result;
        }
        //如果给定的长度大于等于3
        int left = 0, right = 0, target = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                //如果nums[i]与它前面相邻的nums[i-1]相等，则跳过，避免得出重复的集合
                continue;
            }
            left = i + 1;
            right = nums.size() - 1;
            target = 0;
            while (left < right) {
                //对下标为i,left,right的元素进行加和，和0进行判断
                target = nums[i] + nums[left] + nums[right];
                if (target == 0) {
                    //如果等于0，则符合要求，加入result
                    temp = { nums[i],nums[left],nums[right] };
                    result.push_back(temp);
                    //与nums[i]符合要求的可能不止一个，所以还需要
                    //但需要剔除重复的
                    while (left < right && nums[left + 1] == nums[i]) {
                        left++;
                    }
                    while (right > left && nums[right - 1] == nums[right]) {
                        right--;
                    }
                    //继续比较
                    left++;
                    right--;
                }
                else if (target < 0) {
                    //如果小于0，右移left,这样target会变大
                    left++;
                }
                else if (target > 0) {
                    //如果大于0，左移right，这样target会变小
                    right--;
                }
            }
        }
        return result;
    }
};

//用来测试的主函数
int main() {
    vector<int> nums; 
    vector<vector<int>> result;
    int n = 0;        //记录nums向量元素的个数
    int temp = 0;     //用来临时记录输入nums元素的值
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);      //push_back()在vector尾添加一个元素
    }
    Solution solution;
    result = solution.threeSum(nums);
    //输出结果
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << ' ' << result[i][1]<<' '<< result[i][2]  <<endl;
    }

    return 0;
}