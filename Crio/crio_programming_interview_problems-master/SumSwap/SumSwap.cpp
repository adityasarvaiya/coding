#include <bits/stdc++.h>
using namespace std;
string sumSwap( vector<int>&A , vector<int> &B) {

    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int n = A.size() , m = B.size();
    long long sum1 = 0 , sum2 = 0;
    for (int i = 0; i < n; i++) sum1 += A[i];

    for (int i = 0; i < m; i++)  sum2 += B[i];

    long long diff = ( sum1 - sum2) / 2;

    if ( sum1 == sum2) {
        return "ALREADY EQUAL" ;
    }
    map<int, int> M;

    for ( int i = 0; i < m; i++) M[B[i]]++;
    for ( int i = 0; i < n; i++) {
        if (M.find(A[i] - diff) != M.end()) {
            pair<int, int> P;
            P.first = A[i];
            P.second = A[i] - diff;
            return "POSSIBLE";

        }
    }
    return "NOT POSSIBLE";
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    int k, t, a, b, c, d, n, m;

    cin >> n >> m;

    vector<int> A(n);
    long long sum1 = 0 , sum2 = 0;
    for (int i = 0; i < n; i++) cin >> A[i], sum1 += A[i];

    vector<int> B(m);
    for (int i = 0; i < m; i++) cin >> B[i], sum2 += B[i];
    string s = sumSwap(A, B);
    cout << s << endl;


}






