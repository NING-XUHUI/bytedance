#include <iostream>
#include <string>
using namespace std;
class Solution{
public:
    int titleToNumber(string s){
       int res = 0;
       for (unsigned int i = 0;i < s.length(); i++){
           int num = s[i] - 'A' + 1;
           res = res * 26 + num;
       }
       return res;
    }
};

int main()
{
    Solution s1;
    cout << s1.titleToNumber(string("AAS")) << endl;
    return 0;
}

