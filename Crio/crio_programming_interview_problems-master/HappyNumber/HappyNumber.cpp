#include <bits/stdc++.h>

using namespace std;

class HappyNumber {
    public:
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int sq(int n) {
            int res = 0;
            while(n>0) {
                int x = n%10;
                res += x*x;
                n/=10;
            }
            return res;
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        string happyNumber(int n) {
            // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            n = abs(n);
            map<int,int> mp;
            while(!mp[n] && n!=1) {
                mp[n]=1;
                n = sq(n);
            }
            if(n==1) return "true";
            return "false";
            // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        }
};

int main() {
    int n;
    cin >> n;
    string result = HappyNumber().happyNumber(n);
    cout << result;
    return 0;
}
