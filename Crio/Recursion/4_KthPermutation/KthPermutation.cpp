#include <bits/stdc++.h>
using namespace std;
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
vector<long long> fact;
void factorial(  ) {
    fact.resize(25);
    int n = 20;
    fact[0] = 1;
    for ( long long i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
}

void helperkthPermutation(string &ans, string &s , int index, int k, int m ) {

    if (index >= m) return;
    int n = s.length();
    int div = (k - 1 ) / (fact[n - 1]);
    // trace(s, div, index, k);
    if (k <= 0) {
        ans.push_back(*s.begin());
        s.erase(s.begin());
        helperkthPermutation(ans, s, index + 1, k, m);
    }

    ans.push_back(s[div]);
    s.erase(s.begin() + div );
    helperkthPermutation(ans, s, index + 1, k - div * (fact[n - 1]), m);
}


// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
string kthPermutation(int n , int k) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    factorial();

    string s ;
    for ( int i = 0; i < n; i++)
        s.push_back(i + 'A');
    sort(s.begin(), s.end());
    string ans;

    helperkthPermutation (ans, s, 0, k, s.size());
    return ans;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int  n, k , t;
    cin >> n >> k;

    string ans = kthPermutation(n, k);
    cout << ans << endl;

}






