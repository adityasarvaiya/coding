#include <bits/stdc++.h> 
using namespace std;  
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
int min(int x, int y, int z) 
{ 
	return min(min(x, y), z); 
} 
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
int editDistance(string str1, string str2) 
{ 
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	int m = str1.length();
	int n = str2.length();
	int dp[m + 1][n + 1]; 
	for (int i = 0; i <= m; i++) { 
		for (int j = 0; j <= n; j++) { 
			if (i == 0) 
				dp[i][j] = j;
			else if (j == 0) 
				dp[i][j] = i;
			else if (str1[i - 1] == str2[j - 1]) 
				dp[i][j] = dp[i - 1][j - 1]; 
			else
				dp[i][j] = 1 + min(dp[i][j - 1],dp[i - 1][j],dp[i - 1][j - 1]);
		} 
	} 
	return dp[m][n]; 
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
} 
int main() 
{
	string str1,str2;
	cin>>str1;
	cin>>str2;
	cout << editDistance(str1, str2);
}
