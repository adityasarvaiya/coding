#include<bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& tree) {
	unordered_map <int, int> hash;
	int start = 0, end, ans = 0;

	for (int i = 0; i < tree.size(); ++i) {
		end = i;

		if (hash.find(tree[i]) == hash.end()) {
			hash[tree[i]] = 1;
		} else {
			hash[tree[i]] += 1;
		}

		
		while (hash.size() > 2) {
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

int main()
{
	int n;
	cin >> n;
	vector<int>tree(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> tree[i];
	}
	int answer = totalFruit(tree);
	cout << answer;
	return 0;
}


class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n=tree.size();
        int size=0, same_count=0, a=0, b=0, cur=0;
        int res=0;  // final answer
        
        for(int i=0;i<n;i++){
            int cur=tree[i];
            if(cur==b){
                size++;
                same_count++;
            }
            else if(cur==a){
                size++;
                same_count=1;
                a=b;
                b=cur;
            }
            else{
                size=same_count+1;
                same_count=1;
                a=b;
                b=cur;
            }
            res=max(res,size);
        }
        return res;
        
    }
};
