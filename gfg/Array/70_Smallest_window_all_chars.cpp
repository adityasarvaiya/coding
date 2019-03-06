// https://practice.geeksforgeeks.org/problems/smallest-distant-window/0
// https://www.geeksforgeeks.org/smallest-window-contains-characters-string/ 

#include <bits/stdc++.h>
using namespace std;

// string fing_max_window(string in)
long long fing_max_window(string in)
{
    long long MAX_CHARS = 26;
    long long i, diff_chars=0, n = in.length(); 
    long long hash[MAX_CHARS];
    fill_n(hash, MAX_CHARS, -1);

    for (i = 0; i < n; ++i) {
        if (hash[in[i]-'a'] == -1) {
            hash[in[i]-'a'] = 0;
            ++diff_chars;
        }
    }

    long long curr_chars=0, start=0;
    long long min_window=INT_MAX, start_index=0,window_len;

    for (i = 0; i < n; ++i) {
        ++(hash[in[i]-'a']);

        if (hash[in[i]-'a'] == 1) {
            ++curr_chars;
        }

        if (curr_chars >= diff_chars) {
            
            while (hash[in[start]-'a'] > 1) {
                --(hash[in[start]-'a']);
                start++;
            }

            window_len = i - start + 1;
            if (min_window >= window_len) {
                min_window = window_len;
                start_index = start;
            }
        }

        // cout << "curr_chars :" << curr_chars << "  min_window :" << min_window << "   start : " << start << endl; 
    }

    // return in.substr(start_index, min_window);
    return min_window;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string in;
        cin >> in;

        cout << fing_max_window(in) << endl;
    }
    return 0;
}