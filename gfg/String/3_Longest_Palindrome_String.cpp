// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

#include <bits/stdc++.h>
using namespace std;

int expand(int l, int r, int n, string s) {
    int start = 0, end = n-1;
    
    while (l >= 0 && r <= n-1) {
        if (s[l] == s[r]) {
            --l;
            ++r;
        } else {
            break;
        }
    }
    
    return (r - l - 1);
}

string longestPalindrome(string s) {
    int i, n = s.length(), l1, l2, l, start = 0, end = -1;
    
    if (n < 1) {
        return "";
    }
    
    for (i = 0; i <= n-1; ++i) {
        l1 = expand(i, i, n, s);
        l2 = expand(i, i+1, n, s);
        l = max(l1, l2);
        
        if (l > end - start + 1) {
            start = i - (l - 1) / 2;
            end = i + l / 2;
        }
    }
    
    
    return s.substr(start, end - start + 1);
}

int main () {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        cout << longestPalindrome(s) << endl;
    }
    return 0;
}