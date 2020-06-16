#include <bits/stdc++.h>
#define ll long long
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
int gcd(int a, int b)
{
    int temp = 0;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int maxPointsOnALine(int n, vector<vector<int>> &points)
{
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x = points[i][0];
        int y = points[i][1];
        int curr = 0;
        unordered_map<ll, int> m;
        int col = 0;
        for (int j = 0; j < n; j++)
        {
            if (x == points[j][0] && y == points[j][1])
            {
                col++;
                continue;
            }
            int slopex = points[j][0] - x;
            int slopey = points[j][1] - y;
            int val = gcd(slopex, slopey);
            if (val != 0)
            {
                slopex /= val;
                slopey /= val;
            }
            ll p = (ll)slopex * 100000 + (ll)slopey;
            m[p]++;
            curr = max(curr, m[p]);
        }
        ans = max(ans, curr + col);
    }
    return ans;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> points;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    int ans = maxPointsOnALine(n, points);
    cout << ans << endl;
}