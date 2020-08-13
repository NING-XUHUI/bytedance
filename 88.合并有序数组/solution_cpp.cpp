/**
 *          从后往前比较并排序
 */ 
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void merge(vector<int>& nums1,int m,vector<int>& nums2,int n){
        int i = nums1.size() - 1;
        m--;
        n--;
        while(n>=0){
            if(m>=0 && nums1[m] >= nums2[n]){
                swap(nums1[i--],nums1[m--]);
            }else{
                swap(nums1[i--],nums2[n--]);
            }
        }
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

