#include <bits/stdc++.h>

using namespace std;

uint64_t number_of_ways(uint64_t n)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    uint64_t prime_mod = 1000000007;
    vector<uint64_t> table(n + 10, 0);
    table[0] = 1;
    table[1] = 1;
    table[2] = 2;
    for (uint64_t i = 3; i <= n; ++i) {
	table[i] = (table[i-3] + table[i-2] + table[i-1]) % prime_mod;
    }

    return table[n];
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}


int main()
{
    uint64_t n;
    cin >> n;

    cout << number_of_ways(n) << endl;
}
