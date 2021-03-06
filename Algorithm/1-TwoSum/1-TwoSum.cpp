#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums_map[nums[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (nums_map.find(target - nums[i]) != nums_map.end() &&i!= nums_map[target - nums[i]]) {
                return { i,nums_map[target - nums[i]] };
            }
        }
        return { -1,-1 };
    }
};

/*
int main()
{
    vector<int> nums;
    int target;
    Solution solution;
    nums = {3,2,4};
    target = 6;
    vector<int> answer=solution.twoSum(nums, target);
    cout << answer[0]<<' '<<answer[1]<<endl;
    return 0;
}
*/