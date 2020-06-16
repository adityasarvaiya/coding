#include "../crio/cpp/io/FastIO.hpp"
#include <bits/stdc++.h>
using namespace std;

class LongestSubstringWithoutRepeatingCharacter {
  public:
    int lengthOfLongestSubstring(string s) {
        int longestSubstring = 0;
        // Your implementation goes here
        
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            unordered_set<char> marked;
            int right = i;
            while (right < n && marked.find(s[right]) == marked.end()) {
                marked.insert(s[right]);
                right++;
            }
            longestSubstring = max(longestSubstring, right - i);
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        return longestSubstring;
    }
};

int main() {
    FastIO();
    string s;
    getline(cin, s);
    int result =
        LongestSubstringWithoutRepeatingCharacter().lengthOfLongestSubstring(s);
    cout << result;
    return 0;
}
