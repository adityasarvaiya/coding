#include <bits/stdc++.h>

using namespace std;

class LongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int i,j,mini=INT_MAX;
        for(i=0;i<int(strs.size());i++){
            int n=strs[i].size();
            mini=min(mini,n);}
        string ans="";
        if(mini==INT_MAX)
            mini=0;
        for(j=0;j<mini;j++)
        {
            bool flag=true;
            char d=strs[0][j];
            for(i=1;i<int(strs.size());i++)
                if(strs[i][j]!=d)
                {
                    flag=false;
                    break;
                }
            if(flag)
                ans+=d;
            else
                break;
        }
        return ans;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
	string s, word;

	getline(cin, s);
	vector<string> strs;
	stringstream Str(s);
	while(getline(Str, word, ' ')) {
		strs.push_back(word);
	}

	string result = LongestCommonPrefix().longestCommonPrefix(strs);
	cout << result;
	return 0;
}
