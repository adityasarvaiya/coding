#include <bits/stdc++.h>
#include "FastIO.hpp"
#include "ReadMatrix.hpp"
#include "PrintMatrix.hpp"

using namespace std;

class MergeSortedArray {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int x = nums1.size();
        if(m==1 && x==1) return;
        int p1 = 0, p2 = 0;
        while(p1 < x && p2 < n) {
            if((x-p1) == (n-p2)) {
                nums1[p1++] = nums2[p2++];
            } else if(nums1[p1] <= nums2[p2]) {
                p1++;
            } else {
                for(int i = x - 1; i > p1; i--) {
                    nums1[i] = nums1[i-1];
                }
                nums1[p1] = nums2[p2];
                p2++;
            }
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
	FastIO();
	int m, n;
	cin >> m >> n;
	vector<int> nums1, nums2;
	ReadMatrix<int>().OneDMatrix(m, nums1);
	ReadMatrix<int>().OneDMatrix(n, nums2);
	nums1.resize(m + n);
	MergeSortedArray().merge(nums1, m, nums2, n);
	PrintMatrix<int>().OneDMatrix(nums1, " ");
	return 0;
}
