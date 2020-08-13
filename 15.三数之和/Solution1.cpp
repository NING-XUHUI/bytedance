/*
 *              哈希法
 * */
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        //找出a+b+c=0
        //a=nums[i],b=nums[j],c=-(a+b)
        for(int i = 0;i < nums.size();i++){
            //排序之后如果第一个元素已经大于0，则不可能有答案
            if(nums[i] > 0){
                continue;
            }
            if(i > 0 && nums[i] == nums[i - 1]){//三元组元素a去重
                continue;
            }
            unordered_set<int> set;
            for(int j = i+1; j < nums.size();j++){
                if(j > i + 2 && nums[j] == nums[j-1] && nums[j-1] == nums[j-2]){//元素b去重
                    continue;
                }
                int c=0-(nums[i]+nums[j]);
                if(set.find(c) != set.end()){
                    res.push_back({nums[i],nums[j],c});
                    set.erase(c);//元素c去重
                }else{
                    set.insert(nums[j]);
                }
            }
        }
        return res;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

