
#include <bits/stdc++.h>
using namespace std;

class KthLargestElementInAnArray {
public:
    int findKthLargest(vector<int>& nums, int k) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int n = nums.size();
        priority_queue<int  > pq;
        for ( int i = 0; i < n; i++) {
            pq.push(nums[i]);
        }
        int answer = 0;
        while (k > 0) {
            k--;
            answer = pq.top();
            pq.pop();
        }
        return answer;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for ( int i = 0; i < n; i++) cin >> nums[i];
    cin >> k;
    int result = KthLargestElementInAnArray().findKthLargest(nums, k);
    cout << result;
    return 0;
}
