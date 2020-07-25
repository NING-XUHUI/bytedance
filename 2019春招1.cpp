#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string s;
    while(n--){
        cin >> s;
        int j = 0;
        for(int i = 0;i < s.size();i++){
            s[j++] = s[i];
            if(j>=3&&s[j-1]==s[j-2]&&s[j-2]==s[j-3])
                j--;
            if(j>=4&&s[j-1]==s[j-2]&&s[j-3]==s[j-4])
                j--;
        }
        s.erase(s.begin()+j,s.end());
        cout << s << endl;
    }
    return 0;
}

