#include<bits/stdc++.h>
using namespace std;
#include "Solution.cpp"
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; ++i) {
        cin >> arr[i];
    }
    vector<int> result = Solution().peaksAndValleys(arr);
    for(int x: result) {
        cout << x << " ";
    }
    cout << "\n";
}
