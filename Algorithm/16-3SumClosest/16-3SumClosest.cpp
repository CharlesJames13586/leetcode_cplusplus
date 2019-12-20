#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        if (nums.size() <= 2) {
            for (int i = 0; i < nums.size(); i++) {
                result = result + nums[i];
            }
            return result;
        }
        
        sort(nums.begin(), nums.end());      //sort对给定区间的数进行升序排列
        result = nums[0] + nums[1] + nums[2];
        int left = 0, right = 0, temp=0;
        for (int i = 0; i < nums.size() - 2; i++) {
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                temp = nums[i] + nums[left] + nums[right];
                if (abs(temp-target) == 0) {
                    //如果相等，返回
                    return temp;
                }
                else if (abs(temp - target) < abs(result - target)) {
                    //如果有更近的，更新
                    result = temp;
                }
                else if (abs(temp - target) > abs(result - target)) {
                    //如果不是更近的，进行下一步
                }

                //更新left,right指针
                if (temp < target) {
                    left++;
                }
                else if (temp > target) {
                    right--;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums;
    cout << "请输入nums向量的大小：";
    int n = 0, temp = 0;     //n记录nums的大小，temp输入时临时记录nums元素的值
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }

    cout << "请输入target的值：";
    int target = 0;
    cin >> target;
    cout << endl;

    Solution solution;
    int result = solution.threeSumClosest(nums, target);

    cout << result;

    return 0;
}