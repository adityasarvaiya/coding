// https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0

#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t;
	cin >> t;

    while (t--) {
	    string s,pat;
	    cin >> s >> pat;
	   
	    int n1 = s.length(), n2 = pat.length();
	   
	    if (n1 != n2 || n1 == 0 || n2 == 0) {
	        cout << 0 << endl;
	    }
	   
        if (n1 == 1) {
	        if (s == pat) 
	            cout << 1 << endl;
	        cout << 0 << endl;
	    }
	   
	   string res = s+s;   
	   string s1 = res.substr(2,n1), s2 = res.substr(n1 - 2, n1);
	   
	   if (pat == s1 || pat == s2) {
	       cout << 1 << endl;
	   } else {
	       cout << 0 << endl;
	   }
	   
	}
	
	return 0;
}