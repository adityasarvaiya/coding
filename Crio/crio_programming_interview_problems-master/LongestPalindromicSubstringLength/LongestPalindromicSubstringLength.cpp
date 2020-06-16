#include<bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
vector<vector<int>>dp;
int rec(string word, int i, int j){
    if(i>j)
        return 0;
    int& ans = dp[i][j];
    if(ans!=-1){
        return ans;
    }
    if(i==j){
        ans = 1;
    }
    else if(word[i]==word[j] && (rec(word,i+1,j-1)==(j-i-1))){
        ans = (j-i-1)+2;
    }
    else{
        ans = max(rec(word,i+1,j), rec(word,i,j-1));
    }
    return ans;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int longestPalindromicSubstringLength(int n, string& word){
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    dp.clear();
    dp.resize(n,vector<int>(n,-1));
    int ans = rec(word,0,n-1);
    return ans;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans = longestPalindromicSubstringLength(n,s);
        cout<<ans<<"\n";    
    }
}