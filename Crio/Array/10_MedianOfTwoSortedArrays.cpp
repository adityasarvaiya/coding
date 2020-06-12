#include<bits/stdc++.h>
using namespace std;

// Implement your solution here
// Solution based on binary search
// TC : O( log(min(size1,size2)))
// SC : O( 1 )

double findMedianOfTwoSortedArrays(vector<int>& nums1, vector<int>& nums2, int size1, int size2) { 
    
        // checking the edge test cases
        if(size1 > nums1.size() || size2 > nums2.size()) return 0.0;
        
        // we will always make the first array have the lesser no of elements to reduce the no of steps in the 
        // binary search solution
        if(size1 > size2) {
            return findMedianOfTwoSortedArrays(nums2, nums1, size2, size1);
        }
        
        // median variable will store the final answer 
        double median = 0.0;

        // the total size of the left array
        long int sizeoflefttotal = (size1 + size2 + 1) / 2;
        
        // the starting point for the left array
        long int lowptr = 0;

        // the ending point of for the left array
        long int highptr = size1;

        while(lowptr <= highptr) {
            
            // the size of the left portion from the first array
            long int sizeleftA = (highptr + lowptr) / 2;

            // the size of the left portion from the second array
            long int sizeleftB = sizeoflefttotal - sizeleftA;

            // the minimum of the right portion from the the first array
            long int minrightA = (sizeleftA == size1)? INT_MAX : nums1[sizeleftA];
            
            // the minimum of the right portion from the the second array
            long int minrightB = (sizeleftB == size2)? INT_MAX : nums2[sizeleftB];
            
            // the maximum of the left portion from the the first array
            long int maxleftA = (sizeleftA == 0)? INT_MIN : nums1[sizeleftA - 1];
            
            // the maximum of the left portion from the the second array
            long int maxleftB = (sizeleftB == 0)? INT_MIN : nums2[sizeleftB - 1];
            
            // checking whether the present size of the left portion of the first array satisfies the conditions  
            if(maxleftA <= minrightB && maxleftB <= minrightA){
                
                // if the no of elements is even
                if((size1 + size2) % 2 == 0) {
                   median = min(minrightA, minrightB) + max(maxleftA, maxleftB);
                   median = median / 2.0;
                   return median;
                }
                // if the no of elements is odd
                else {
                   median = max(maxleftA, maxleftB);
                   return median;
                }
            } 
            // if the size of the left portion of the first array needs to be reduced
            else if (maxleftA > minrightB) {
                highptr = sizeleftA - 1;
            } 
            // if the size of the left portion of the first array needs to be increased
            else {
                lowptr = sizeleftA + 1;
            }
        }
        // return 0.0 as the median since we could not find any median from above
        return 0.0;
}

int main()
{
	int m, n, q, size1, size2;
	cin >> m;
	vector<int>nums1(m);
	for(int i = 0 ; i < m ; i++) {
		cin >> nums1[i];
	}
	cin >> n;
	vector<int>nums2(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> nums2[i];
	}
	cin >> q;
        for (int i = 0; i < q ; i++) {
	    cin >> size1;
	    cin >> size2;
	    double answer = findMedianOfTwoSortedArrays(nums1, nums2, size1, size2);
	    cout << fixed << setprecision(1) << answer << "\n";
	}
	return 0;
}