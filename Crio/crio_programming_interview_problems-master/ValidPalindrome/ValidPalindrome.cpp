#include <bits/stdc++.h>
using namespace std;

class ValidPalindrome {
    public:
        string isPalindrome(string s) {
            // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            string t = "";
            for(auto i:s) {
                if((i>='a' && i<= 'z') || (i>='0' && i<='9'))
                    t+=i;
            }
            int n = t.size();
            for(int i = 0; i < n/2; i++) {
                if(t[i] != t[n-1-i])
                    return "false";
            }
            return "true";
            // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        }
};

int main() {
    string s;
    getline(cin, s);
    string result = ValidPalindrome().isPalindrome(s);
    cout<<result;
    return 0;
}
