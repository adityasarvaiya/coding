#include <bits/stdc++.h>
using namespace std;
#include "Solution.cpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r, c;
    cin >> r >> c;
    vector<vector<long long>  > matrix(r, vector<long long >(c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];
    }
    int q;
    cin >> q;
    while (q--)
    {
        long long target;
        cin >> target;
        bool result  =  answer(matrix, target);
        if (result)
            cout << "true" << "\n";
        else
            cout << "false\n";
    }
    return 0;
}
