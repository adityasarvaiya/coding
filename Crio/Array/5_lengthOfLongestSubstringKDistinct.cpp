#include<bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstringKDistinct(string tree, int k) {
	unordered_map <char, int> hash;
	int start = 0, end, ans = 0;

	for (int i = 0; i < tree.size(); ++i) {
		end = i;

		if (hash.find(tree[i]) == hash.end()) {
			hash[tree[i]] = 1;
		} else {
			hash[tree[i]] += 1;
		}

		
		while (hash.size() > k) {
			hash[tree[start]] -= 1;
			
			if (hash[tree[start]] == 0) {
				hash.erase(tree[start]);
			}

			start++;
		}

		ans = max(ans, end-start+1);
	}

	return ans;
}

int main() {
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int answer = lengthOfLongestSubstringKDistinct(s,k);
	cout <<  answer;
	return 0;
}
