// https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x/0 

#include <bits/stdc++.h>
using namespace std;

void find_pairs(vector<int> a, vector<int> b, int X) 
{   
    int a_size = a.size(), b_size = b.size(),i,f=0;
    unordered_map <int,int> hash;

    for (i = 0; i < b_size; ++i) {
        hash[b[i]] = b[i];
    }

    sort(a.begin(), a.end());

    for (i = 0; i < a_size; ++i) {
        if (hash.find(X-a[i]) != hash.end()) {
            if (f == 0) {
                cout << a[i] << " " << hash[X-a[i]];
                f=1;
            } else {
                cout << ", " << a[i] << " " << hash[X-a[i]];
            }
        }
    }

    if (f==0) {
        cout << -1;
    }
    cout << endl;

    return;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;

    while (t--) {
        int N,M,X,i,curr;
        cin >> N >> M >> X;
        vector <int> a,b;

        for (i = 0; i < N; i++) {
            cin >> curr;
            a.push_back(curr);
        }

        for (i = 0; i < M; i++) {
            cin >> curr;
            b.push_back(curr);
        }

        find_pairs(a,b,X);
    }

    return 0;
}