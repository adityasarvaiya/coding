#include<bits/stdc++.h>
using namespace std;

bool isPermutationPalindrome(string &s) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	int count[55];
	memset(count , 0 , sizeof count);
	for(int i = 0 ; i < s.size() ; i++) {
		if(s[i] <= 'z' && s[i] >= 'a')
			count[s[i] - 'a']++;
	 	if(s[i] <= 'Z' && s[i] >= 'A')
			count[26 + s[i] - 'A']++;
	 	
	}
	int oddCount = 0;
	for(int i = 0 ;i < 55 ; i++) {
		if(count[i]%2 != 0) {
			oddCount++;
		}
	}
	if(oddCount > 1) {
		return false;
	}
	return true;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		bool answer = isPermutationPalindrome(s);
		if(answer) {
			cout << "True\n";
		} else {
			cout << "False\n";
		}
	}
	return 0;
}
