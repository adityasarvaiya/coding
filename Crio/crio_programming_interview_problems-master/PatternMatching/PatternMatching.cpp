#include <bits/stdc++.h>
using namespace std;
bool isMatch(string str, int n, int i, string pat, int m, int j, unordered_map<char, string>& M)
{
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	if (i == n && j == m)
		return true;

	if (i == n || j == m)
		return false;

	char ch = pat[j];

	if (M.find(ch) != M.end())
	{
		string s = M[ch];
		int len = s.size();
		string subStr = str.substr(i, len);

		if (subStr.compare(s))
			return false;
		return isMatch(str, n, i + len, pat, m, j + 1, M);
	}
	for (int len = 1; len <= n - i; len++)
	{
		M[ch] = str.substr(i, len);
		if (isMatch(str, n, i + len, pat, m, j + 1, M))
			return true;
		M.erase(ch);
	}

	return false;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

bool patternMatching(string str, string pat, int n, int m)
{
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	if (n < m)
		return false;
	unordered_map<char, string> M;
	bool res = isMatch(str, n, 0, pat, m, 0, M);
	return res;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
	int t; cin >> t;
	while (t--) {

		string str , pat ;
		cin >> str >> pat;
		int n = str.size(), m = pat.size();

		if (!patternMatching(str, pat, n, m))
			cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}
