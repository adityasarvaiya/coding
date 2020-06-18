#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"

using namespace std;

class ReverseInteger {
    public:
        int reverse(int x) {
            // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            if(x==INT_MIN) return 0;
            bool sign = x < 0;
            int ans = 0;
            x = abs(x);
            while(x>0) {
                int y = x%10;
                if((INT_MAX - y)/10 >= ans)
                {ans = ans*10 + y;
                    x /= 10;}
                else return 0;
            }
            if(sign) ans = -ans;
            return ans;
            // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    int result = ReverseInteger().reverse(n);
    cout << result;
    return 0;
}
