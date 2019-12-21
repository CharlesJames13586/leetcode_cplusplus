#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();    //记录数组的长度，遍历数组时会用到
        int index = -1; //记录数组从后往前数第一个不符合降序排列的下标
        for(int i = len - 1; i > 0; i--){
            if(nums[i - 1] < nums[i]){
                index = i - 1;
                break;
            }
        }
        //交换nums[index]和下标大于index中元素最小的
        if(index >= 0){
            int minNumIndex = index + 1;
            int i = index + 1;
            while(nums[i] > nums[index]){
                minNumIndex = i;
                i++;
                if(i >= len){
                    break;
                }
            }
            int temp = nums[index];
            nums[index] = nums[minNumIndex];
            nums[minNumIndex] = temp;
        }
        //对index后的数字进行升序排列，因为只能原地排列就使用插入排序吧
        for(int i = index + 1; i < len; i++){
            for(int j = i + 1; j < len && j > index + 1; j--){
                if(nums[j] < nums[j - 1]){
                    int temp = nums[j];
                    nums[j] = nums[j - 1];
                    nums[j - 1] = temp;
                }
            }
        }
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    for(int j = 0; j < 24; j++){  //24是4个不同元素全排列的个数
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << ',';
        }
        cout << "→";
        s.nextPermutation(nums);
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << ',';
        }
        cout<<endl;
    }
    return 0;
}