//incomplete/nonsubmited

#include <bits/stdc++.h>
using namespace std;

int Find_Min_Safe_Platforms(int len, int c[][2]) 
{   
    vector <pair<int, int>> all;
    vector <pair<int, int>> :: iterator it1;

    int output[2*len], i=0, max=0;

    for (int j=0; j < len; ++j) {
        if (c[j][0] == c[j][1]) {
            all.push_back(make_pair(c[j][0], 1));
            all.push_back(make_pair(c[j][1], -1));
        } else {
            all.push_back(make_pair(c[j][0], 1));
            all.push_back(make_pair(c[j][1], -1));
        }
    }

    sort(all.begin(), all.end());

    for (it1=all.begin(); it1!=all.end(); ++it1) {
        if (i==0) {
            output[i] = (*it1).second;
        } else {
            output[i] = output[i-1] + (*it1).second;
        }
        if (max < output[i]) {
            max = output[i];
        }
        i++;
    }

    return max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, curr;
        cin >> n;
        int c[n][2];

        for (int i=0; i < n; ++i) {
            cin >> curr;
            c[i][0] = curr;
        }

        for (int i=0; i < n; ++i) {
            cin >> curr;
            c[i][1] = curr;
        }

        cout << Find_Min_Safe_Platforms(n,c) << endl;

    } 

    return 0;
}