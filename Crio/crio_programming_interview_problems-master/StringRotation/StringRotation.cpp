#include<bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
string getSubString(int l , int r , string s) {
	string ret = "";
	for(int i = l ; i <= r ; i++) {
		ret += s[i];
	}
	return ret;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

bool isRotation(string s1 , string s2) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	if(s1.size() != s2.size()) {
		return false;
	}
	for(int i = s1.size()-1 ; i >= 0 ; i--) {
		if(getSubString(i,s1.size()-1,s1) == getSubString(0,s1.size()-1-i,s2)) {
			if(getSubString(0,i-1,s1) == getSubString(s1.size()-i,s2.size()-1,s2)) {
				return true;	
			}
			
		}
	}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	return false;
}

int main()
{
	string s1 , s2;
	cin >> s1 >> s2; 
	bool answer = isRotation(s1,s2);
	if(answer) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}
