/*
 *                  双指针
 *
 * */

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        //找出a+b+c=0
        //a = nums[i],b=nums[left],c=nums[right];
        for(int i = 0;i < nums.size();i++){
            return result;
        //错误去重方法，将会漏掉-1，-1，2这种情况
        //if(nums[i]==nums[i+1]){
        //  continue;
        //}
        //正确方式
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = nums.size() - 1;
            while(right > left){
                if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }else{
                    result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(right > left && nums[right] == nums[right - 1]) right--;
                    while(right > left && nums[left] == nums[left + 1]) left++l;

                    right--;
                    left++;
                }
            }
        }    
        return result;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

