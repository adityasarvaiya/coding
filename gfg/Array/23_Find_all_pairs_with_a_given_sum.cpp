// https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x/0

#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> find_pairs(vector<int> a, vector<int> b, int X) 
{   
    // cout << "1" << endl;

    double MAX_LEN = pow(10,6);
    int i,diff;
    int asize = a.size();
    int bsize = b.size();
    int hash_neg[int(MAX_LEN)];
    int hash_pos[int(MAX_LEN)];
    // cout << "5" << endl;

    vector <pair<int, int>> out;

    // cout << "2" << endl;
    for (i = 0; i <= MAX_LEN; i++) {
        hash_neg[i] = 0;
        hash_pos[i] = 0;
    }

    for (i = 0; i < bsize; i++) {
        if (b[i] < 0) {
            hash_neg[(-1)*b[i]] = 1;
        } else {
            hash_pos[b[i]] = 1;
        }
    }

    // cout << "3" << endl;


    // for (i = 0; i < asize; i++) {
        diff = X - a[i];
        if (diff >= 0) {
            if (hash_pos[diff] == 1) {
                out.push_back(make_pair(a[i], diff));
            // } 
        } else {
            if (hash_neg[(-1)*diff] == 1) {
                out.push_back(make_pair(a[i], diff));
            }
        }

    }

    // cout << "4" << endl;


    return out;
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

        vector<pair<int, int>> out = find_pairs(a,b,X);
        sort(out.begin(), out.end());
        vector<pair<int, int>> :: iterator it;

        if (out.size() == 0) {
            cout << -1 << endl;
        } else {
            for (it = out.begin(); it != out.end(); it++) {
                if (it == out.begin()) {
                    cout << (*it).first << " " << (*it).second;
                } else {
                    cout << ", " << (*it).first << " " << (*it).second;
                }
            }

            cout << endl;
        }

    }

    return 0;
}