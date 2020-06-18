#include <bits/stdc++.h>

using namespace std;

class ExcelSheetColumnNumber {
public:
    int titleToNumber(string s) {
    	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int n = s.size();
        long long int z = 1, ans = 0;
        for(int i = n-1; i >= 0; i--) {
            int y = s[i] - 'A' + 1;
            ans += y*z;
            z*=26;
        }
        return ans;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
	string s;
	cin >> s;
	int result = ExcelSheetColumnNumber().titleToNumber(s);
	cout << result;
	return 0;
}
