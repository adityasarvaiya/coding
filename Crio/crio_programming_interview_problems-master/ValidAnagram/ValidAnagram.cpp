#include <bits/stdc++.h>
#include "FastIO.hpp"

using namespace std;

class ValidAnagram {
    public:
        bool isAnagram(string s, string t) {
            // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            map<char,int> mp,mp2;
            for(auto i:s) mp[i]++;
            for(auto i:t) mp2[i]++;
            for(auto i:mp)
            {
                if(mp[i.first] != mp2[i.first]) return false;
            }
            for(auto i:mp2)
            {
                if(mp[i.first] != mp2[i.first]) return false;
            }
            return true;
            // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        }
};

int main() {
    FastIO();
    string s, t;
    getline(cin, s);
    getline(cin, t);
    bool result = ValidAnagram().isAnagram(s, t);
    cout<< boolalpha << result;
    return 0;
}
