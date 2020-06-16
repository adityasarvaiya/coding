#include <bits/stdc++.h>
#include "FastIO.hpp"

using namespace std;

class SqrtX {
public:
    int mySqrt(int x) {
    	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if(x==0 || x==1) return x;
        long long lo=1,hi=x/2;
        long long ans;
        while(lo<hi)
        {
            long long mid=lo+(hi-lo)/2;
            ans=mid*mid;
            if(ans==x) return mid;
            else if(ans>x) hi=mid-1;
            else lo=mid+1;
        }
        if(lo*lo>x) return lo-1;
        return lo;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
	FastIO();
	int n;
	cin >> n;
	int result = SqrtX().mySqrt(n);
	cout << result;
	return 0;
}
