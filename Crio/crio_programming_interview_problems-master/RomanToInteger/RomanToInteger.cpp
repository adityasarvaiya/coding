#include <bits/stdc++.h>
#include "FastIO.hpp"

using namespace std;

class RomanToInteger {
public:
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    string fun(char ch) {
        string s(1, ch);
        return s;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    int romanToInt(string s) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        map<string,int> mp;
        mp["I"] = 1;
        mp["V"] = 5;
        mp["X"] = 10;
        mp["L"] = 50;
        mp["C"] = 100;
        mp["D"] = 500;
        mp["M"] = 1000;
        mp["IV"] = 4;
        mp["IX"] = 9;
        mp["XL"] = 40;
        mp["XC"] = 90;
        mp["CD"] = 400;
        mp["CM"] = 900;
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(i+1<n && mp[s.substr(i,2)])
            {
                ans += mp[s.substr(i,2)];
                i++;
            }
            else {
                ans += mp[fun(s[i])];
            }
        }
        return ans;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
	FastIO();
	string s;
	cin >> s;
	int result = RomanToInteger().romanToInt(s);
	cout << result;
	return 0;
}
