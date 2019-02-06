// https://practice.geeksforgeeks.org/problems/maximum-tip-calculator/0

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, x, y, c1, c2, tip=0, i, j;
        cin >> n >> x >> y;
        int a[n], b[n], hash[n];
        vector <pair <int, int>> dist1;
        vector <pair <int, int>> dist2;
        vector <pair <int, int>> same;
        vector <pair <int, int>> :: iterator it;

        for (i = 0; i < n; ++i) {
            hash[i] = 0;
            cin >> c1 >> c2;
            a[i] = c1;
            b[i] = c2;

            if (c1 == c2) {
                same.push_back(make_pair(c1,i));
            } else {
                dist1.push_back(make_pair(c1,i));
                dist2.push_back(make_pair(c1,i));
            }
        }
        
        for (it = same.begin(); it != same.end(); ++it) {
            tip += (*it).first;
        }

        sort(dist1.begin(), dist1.end());
        sort(dist2.begin(), dist2.end());

        i = 0;
        j = 0;
        int l = dist1.size();

        while (i < l || j < l) {
            while (i < l && hash[dist1[i].second] == 1) {
                i++;
            }
            
            while (j < l && hash[dist2[j].second] == 1) {
                j++;
            }
            
            if (i == l && j == l) {
                break;
            }

            if (dist1[i].first > dist2[j].first) {
                if (x > 0) {
                    tip += dist1[i].first;
                    hash[dist1[i].second] = 1;
                    x--;
                } else {
                    tip += b[dist1[i].second];
                    hash[dist1[i].second] = 1;
                    y--;
                }
            } else if (dist1[i].first < dist2[j].first) {
                if (y > 0) {
                    tip += dist2[j].first;
                    hash[dist2[j].second] = 1;
                    y--;
                } else {
                    tip += a[dist2[j].second];
                    hash[dist2[j].second] = 1;
                    x--;
                }
            } else {
                if (x > 0 && x > y) {
                    tip += dist1[i].first;
                    hash[dist1[i].second] = 1;
                    x--;
                } else {
                    tip += dist2[j].first;
                    hash[dist2[j].second] = 1;
                    y--;
                }
            }

            // cout << i << " " << j  << " " << tip << " ";
        }

        cout << tip << endl;

    }

    return 0;
}
