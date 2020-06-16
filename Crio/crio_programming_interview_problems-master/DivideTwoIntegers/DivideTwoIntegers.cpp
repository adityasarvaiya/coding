#include "FastIO.hpp"
#include <bits/stdc++.h>
using namespace std;

class DivideTwoIntegers {
  public:
    int divide(int dividend, int divisor) {
        // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
        // Your implementation goes here
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        bool flag, is = false;
        if (dividend == INT_MIN) {
            if (divisor == -1)
                return INT_MAX;
            if (divisor == 1)
                return INT_MIN;
            if (divisor == INT_MIN)
                return 1;
            is = true;
            dividend += 1;
        }
        if (divisor == INT_MIN) {
            return 0;
        }
        if ((dividend < 0 && divisor < 0) || (dividend >= 0 && divisor >= 0))
            flag = true;
        else
            flag = false;
        int ans = 0;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (dividend >= divisor) {
            int tmp = divisor, k = 1;
            while (tmp << 1 > 0 && tmp << 1 <= dividend) {
                tmp <<= 1;
                k <<= 1;
            }
            dividend -= tmp;
            ans += k;
        }
        if (is) {
            dividend += 1;
            while (dividend >= divisor) {
                dividend -= divisor;
                ans++;
            }
        }
        if (!flag)
            ans = -ans;
        return ans;
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
    }
};

int main() {
    FastIO();
    int dividend, divisor;
    cin >> dividend >> divisor;
    int result = DivideTwoIntegers().divide(dividend, divisor);
    cout << result;
    return 0;
}