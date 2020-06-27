#include<bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	vector<int>ans;
	if(s.size() < p.size()) {
		return ans;
	}
	int cntP[26],cntS[26],left = 0,right = p.size()-1;
	memset(cntS,0,sizeof cntS);
	memset(cntP,0,sizeof cntP);
	for(int i = 0 ; i < p.size() ; i++) {
		cntP[p[i] - 'a']++;
	}
	for(int i = left ; i <= right ; i++) {
		cntS[s[i] - 'a']++;
	}
	while(right < s.size()) {
		bool isValid = true;
		for(int i = 0 ; i < 26 ; i++) {
			if(cntS[i] != cntP[i]) {
				isValid = false;
			}
		}
		if(isValid) {
			ans.push_back(left);
		}
		cntS[s[left] - 'a']--;
		right++;
		left++;
		if(right < s.size()) {
			cntS[s[right]-'a']++;
		}
	}
	return ans;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
	string s,p;
	cin >> s >> p;
	vector<int> answer = findAnagrams(s,p);
	cout << answer.size() << "\n";
	for(int i = 0 ; i < answer.size() ; i++) {
		cout << answer[i] << " ";
	}
	return 0;
}
