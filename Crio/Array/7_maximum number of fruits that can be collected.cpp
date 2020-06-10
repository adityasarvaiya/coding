#include<bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& tree) {
    unordered_map<int,int> m;
    int n=tree.size();
    int l=0,r=0,ma=0,ct=0;
    while(r<n){
        if(m[tree[r]]==0) ct++;
        m[tree[r]]++;
        r++;
        while(l<r && ct>2){
            m[tree[l]]--;
            if(m[tree[l]]==0) ct--;
            l++;
        }
        ma=max(ma,r-l);
    }
    return ma;
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