#include <bits/stdc++.h>
using namespace std;

class PowxN {
  public:
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    long long exponentMod(long long A, long long B, long long C) {
        if (B == 0)
            return 1;
        long long y = 1;
        A = A % C;
        y = exponentMod(A, B / 2, C);
        y = (y * y) % C;
        if (B % 2 == 1)
            y = (y * A) % C;

        return y;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    long long  myPow(long long x, long long y) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        return exponentMod(x, y, 1000000007);
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main(){
    long long x, n;
    cin >> x >> n;
    long long result = PowxN().myPow(x, n);
    cout << result;
    return 0;
}
