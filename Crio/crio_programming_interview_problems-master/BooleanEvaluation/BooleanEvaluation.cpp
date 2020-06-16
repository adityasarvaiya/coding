#include<bits/stdc++.h>
using namespace std;

//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
long long mod=1e9+7;
long long dp[1001][1001][3];
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

long long booleanEvaluation(string expression,bool result)
{
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    long long i,j,k,n=expression.length();
    for(k=1;k<=n;k+=2)
    {
        for(i=0;i<n;i+=2)
        {
            if(k==1)
            {
                if(expression[i]=='1')
                {
                    dp[i][i][1]=1;
                    dp[i][i][0]=0;
                }
                else
                {
                    dp[i][i][1]=0;
                    dp[i][i][0]=1;                }
            }
            else
            {
                for(j=i;j<i+k;j+=2)
                {
                    if(expression[j+1]=='&')
                    {
                        dp[i][i+k-1][0]=(dp[i][i+k-1][0]%mod + ((dp[i][j][0]%mod)*((dp[j+2][i+k-1][0]+dp[j+2][i+k-1][1])%mod))%mod + ((dp[i][j][1]%mod)*(dp[j+2][i+k-1][0]%mod))%mod)%mod;
                        dp[i][i+k-1][1]=(dp[i][i+k-1][1]%mod + ((dp[i][j][1]%mod)*(dp[j+2][i+k-1][1]%mod))%mod)%mod;
                    }
                    if(expression[j+1]=='|')
                    {
                        dp[i][i+k-1][0]=(dp[i][i+k-1][0]%mod + ((dp[i][j][0]%mod)*(dp[j+2][i+k-1][0]%mod))%mod)%mod;
                        dp[i][i+k-1][1]=(dp[i][i+k-1][1]%mod + ((dp[i][j][1]%mod)*((dp[j+2][i+k-1][0]+dp[j+2][i+k-1][1])%mod))%mod + ((dp[i][j][0]%mod)*(dp[j+2][i+k-1][1]%mod))%mod)%mod;
                    }
                    if(expression[j+1]=='^')
                    {
                        dp[i][i+k-1][0]=(dp[i][i+k-1][0]%mod + ((dp[i][j][0]%mod)*(dp[j+2][i+k-1][0]%mod))%mod + ((dp[i][j][1]%mod)*(dp[j+2][i+k-1][1]%mod))%mod)%mod ;
                        dp[i][i+k-1][1]=(dp[i][i+k-1][1]%mod + ((dp[i][j][1]%mod)*(dp[j+2][i+k-1][0]%mod))%mod + ((dp[i][j][0]%mod)*(dp[j+2][i+k-1][1]%mod))%mod)%mod;
                    }
                }
            }
        }
    }
    return dp[0][n-1][result]%mod;
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
    string s;
    cin>>s;
    bool result;
    cin>>result;
    cout<<booleanEvaluation(s,result);
}
