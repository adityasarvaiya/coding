// https://www.codechef.com/submit/ASTRING
// https://www.codechef.com/problems/ASTRING
// https://discuss.codechef.com/t/astring-editorial/12597
// https://s3.amazonaws.com/codechef_shared/download/Solutions/LTIME36/Tester/ASTRING_subtask3.cpp

#include <bits/stdc++.h>
using namespace std;

void util(string s, long long k) {
    set < pair<char, long long> > h;
    long long i, n = s.length();
    
    for (i = 0; i < n-k+1; ++i) {
        h.insert({s[i], i});
    }
    
    // string ans = "";
    int start, deleted_till = 0;
    
    for (; i < n; ++i) {
        // ans = ans + (*h.begin()).first;
        cout << (*h.begin()).first;
        start = (*h.begin()).second;
        
        while (deleted_till <= start) {
            h.erase({s[deleted_till], deleted_till});
            deleted_till++;
        }
        
        h.insert({s[i], i});
    }
    
    // ans = ans + (*h.begin()).first;
    cout << (*h.begin()).first << endl;
    // return ans;
}

int main() {
    long long  t, k;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s >> k;
        
        util(s,k);
        // cout << util(s,k) << endl;
    }

	return 0;
}
