#include <bits/stdc++.h>
#include "FastIO.hpp"

using namespace std;

class ImplementStrStr {
public:
    int strStr(string haystack, string needle) {
    	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int n = haystack.size(), m = needle.size(), ans = -1;
        if(m == 0) return 0;
        if(n == 0 || m > n) return -1;
        char ch = needle[0];
        for(int j = 0; j < n; j++) {
            if(haystack[j] == ch) {
                ans = j;
                int temp = j + 1;
                for(int i = 1; temp < n && i < m; temp++, i++) {
                    if(haystack[temp] != needle[i]) {
                        break;
                    }
                }
                if((temp - j) == m) return ans;
            }
        }
        return -1;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
	FastIO();
	string haystack, needle;
	getline(cin, haystack);
	getline(cin, needle);
	int result = ImplementStrStr().strStr(haystack, needle);
	cout << result;
	return 0;
}
