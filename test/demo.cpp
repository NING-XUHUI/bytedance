#include <iostream>
#include <string>
using namespace std;
class Solution{
public:
    int titleToNumber(string s){
        if(s.length()==1)
            return s[0]-64;
    }
};

int main()
{
    Solution s1;
    cout << s1.titleToNumber(string("A")) << endl;

    return 0;
}

