#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int left = 0, right = nums.size() - 1, mid = (left + right) / 2;
        if(right < 0){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        while(left <= right){
            if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] == target){
                break;
            }else if(nums[mid] < target){
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        if(nums[mid] == target){
            left = mid;
            right = mid;
            while(left > 0 && nums[left - 1] == target){
                left--;
            }
            while(right < nums.size() - 1 && nums[right + 1] == target){
                right++;
            }
        }else{
            left = -1;
            right = -1;
        }
        result.push_back(left);
        result.push_back(right);
        return result;
    }
};

int main(){

    return 0;
}