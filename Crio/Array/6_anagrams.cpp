#include<bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    unordered_map <char, int> hash;
    int match = 0;

    if (s.size() == 0 || p.size() > s.size()) {
        return ans;
    }

    for (int i = 0; i < p.size(); ++i) {
        if (hash.find(p[i]) == hash.end()) {
            hash[p[i]] = 1;
        } else {
            hash[p[i]] += 1;
        }
    }   

    for (int i = 0; i < s.size(); ++i) {
        if (hash.find(s[i]) != hash.end()) {
            hash[s[i]] -= 1;

            if (hash[s[i]] == 0) {
                match++;
            }
        }

        if (i >= p.size()) {
            if (hash.find(s[i-p.size()]) != hash.end()) {
                hash[s[i-p.size()]] += 1;

                if (hash[s[i-p.size()]] == 1) {
                    match--;
                }
            }
        }

        if (match == hash.size()) {
            ans.push_back(i - p.size() + 1);
        }
    }

    return ans;
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
