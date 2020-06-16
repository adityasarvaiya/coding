#include <bits/stdc++.h>
using namespace std;

class LongestPalindromicSubstring {
  public:
    string longestPalindromicSubstring(string s) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        string maxString = "";
        int n = s.size();
        if (n <= 1) {
            return s + "\n";
        }

        bool isPalindrome[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i >= j) {
                    isPalindrome[i][j] = 1;
                } else {
                    isPalindrome[i][j] = 0;
                }
            }
        }
        int maxLength = 0;
        int maxLengthPos = 0;

        for (int j = 1; j < n; ++j) {
            for (int i = 0; i + j < n; ++i) {
                isPalindrome[i][i + j] = 0;
                if (s[i] == s[i + j]) {
                    isPalindrome[i][i + j] = isPalindrome[i + 1][i + j - 1];
                }
                if (isPalindrome[i][i + j] == 1) {
                    maxLength = j;
                    maxLengthPos = i;
                }
            }
        }

        for (int i = maxLengthPos; i <= maxLengthPos + maxLength; ++i) {
            maxString += s[i];
        }
        return maxString;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        
    }
};

int main() {
    string s;
    getline(cin, s);
    string result = LongestPalindromicSubstring().longestPalindromicSubstring(s);
    cout << result;
    return 0;
}
