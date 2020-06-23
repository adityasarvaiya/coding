#include <bits/stdc++.h>
using namespace std;

class ValidParenthesis {
public:
	string isValid(string s) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		stack<char> st;
		map<char, char> m;
		m[']'] = '[';
		m[')'] = '(';
		m['}'] = '{';
		int n = s.size();
		for (int i = 0; i < n; i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				st.push(s[i]);
			else {
				if (!st.empty() && st.top() == m[s[i]]) st.pop();
				else return "false";
			}
		}
		if (st.empty()) return "true";
		else return "false";
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
};

int main() {

	string s;
	getline(cin, s);
	string result = ValidParenthesis().isValid(s);
	cout << result;
	return 0;
}
