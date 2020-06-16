#include <bits/stdc++.h>
using namespace std;

string regularExpressionMatching(string s, string p)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int m = s.size(), n = p.size();
    string x = "";
    x+=p[0];
    for(int i=1 ;i<n;i++)
    {
        if(x.back() != p[i] or p[i] != '*')
            x+=p[i];
    }
    int pos = 0;
    p = x;
    n = p.size();
    while( pos < n and p[pos] == '*')
        pos+=1;
    
    vector<vector<bool > > dp( m+1 ,vector<bool>(n+1));
    dp[m][n]=true;
    for (int i = m; i >= 0; i--){
        for (int j = n - 1; j >= 0; j--){
            bool first_match = (i < m && (p[j] == s[i] || p[j] == '.'));
            if (j + 1 < n && p[j+1] == '*'){
                dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
            } else {
                dp[i][j] = first_match && dp[i+1][j+1];
            }
        }
    }
    if (dp[0][pos])
        return "true";
    else
        return "false";
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    string s, p;
    cin>>s>>p;
    string result = regularExpressionMatching(s , p);
    cout<<result<<"\n";

    return 0;
}
