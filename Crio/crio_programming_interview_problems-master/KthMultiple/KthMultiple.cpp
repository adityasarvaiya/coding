#include <bits/stdc++.h>
using namespace std;

long long kthMultiple(long long k) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    long long a = 3, b = 5, c = 7, x = 1;
    queue<long long>q3, q5, q7;
    long long inf = 10000000000000000;
    for (long long i = 1; i < k; i++)
    {
        q3.push(x * 3);
        q5.push(x * 5);
        q7.push(x * 7);
        x = min(q3.front(), min(q5.front(), q7.front()));

        if (x == q3.front())
        {
            q3.pop();
        }
        if (x == q5.front())
        {
            q5.pop();
        }
        if (x == q7.front())
        {
            q7.pop();
        }
    }
    return x;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    long long k = 10;
    cin >> k;
    long long x = kthMultiple(k);
    cout << x << endl;
    return 0;
}