#include <bits/stdc++.h>
using namespace std;

int CuttingPalin(int n,string str)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<int > C(n);
    vector<vector<bool > > P(n,vector<bool>(n));
    int i, j, k, L;
    for(i=0;i<n;i++)  
        P[i][i] = true;
    for(L=2;L<=n;L++) {
        for (i=0;i<n-L+1;i++) { 
            j = i+ L -1;
            if (L == 2) 
                P[i][j] = (str[i] == str[j]); 
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1]; 
        } 
    }
    for (i = 0; i < n; i++) { 
        if (P[0][i] == true) 
            C[i] = 0; 
        else { 
            C[i] = 1e9; 
            for (j = 0; j < i; j++) { 
                if (P[j + 1][i] == true && C[j] < C[i] - 1) 
                    C[i] = C[j]+1; 
            } 
        } 
    }
    return C[n - 1]; 
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int result = CuttingPalin(n,s);
    cout<<result<<"\n";
    return 0;
}
