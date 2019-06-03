// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0

#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int t;
    cin >> t;
    
    while (t--) {
        string st;
        cin >> st;
        
        sort(st.begin(), st.end());
        
        do {
           cout << st << " "; 
        } while (next_permutation(st.begin(), st.end()));
        
        cout << endl;
    }
	
	return 0;
}