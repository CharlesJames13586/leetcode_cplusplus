#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0){   //nums数组为空，返回-1
            return -1;
        }
        int left = 0, right = len - 1;
        int mid = (left + right) / 2;
        //找出前后两截在数组中从哪块分开
        while(left < right){
            if(nums[left] < nums[right]){   //说明没有旋转
                mid = right;
                break;
            }else if(mid == left){
                while(mid < len - 1 && nums[mid] < nums[mid + 1]){
                    mid++;
                }
                break;
            }else if(nums[mid] > nums[left] && nums[mid] > nums[right]){  //说明分开的部分还要靠右
                left = mid;
            }else if(nums[mid] < nums[right] && nums[mid] < nums[left]){  //说明分开的部分还要靠左
                right = mid;
            }
            mid = (left + right) / 2;
            //cout << mid <<endl;
        }
        //将target和nums[0]和nums[len-1]做比较，判断target在前半截还是后半截
        if(target < nums[0]){     //后半截
            left = mid + 1;
            right = len - 1;
        }else{     //前半截
            left = 0;
            right = mid;
        }
        mid = (left + right) / 2;
        //二分法寻找target
        while(left < right){
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] == target){
                //return mid;
                break;
            }
            mid = (left + right) / 2;
        }
        if(nums[mid] == target)
            return mid;
        else  //未找到返回-1
            return -1;
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int target = 7;
    for(int i = 0; i < 7; i++){
        target = nums[i];
        Solution s;
        cout << s.search(nums, target) << " ";
    }
    return 0;
}