// https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0
// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/


#include <bits/stdc++.h>
using namespace std;

 
int find_index(int nums[], int t, int n) 
{
    int l=0, h=n-1, mid;
    
    if (n==0) {
        return -1;
    }
    
    while (l < h) {
        mid = (l+h) / 2;
        
        if (t == nums[mid]) {
            return mid;
        }
        
        if (nums[l] <= nums[mid]) {
            if (t < nums[mid] && t >= nums[l]) {
                h = mid-1;
            } else {
                l = mid+1; 
            }
        } else {
            if (t > nums[mid] && t <= nums[h]) {
                l=mid+1;
            } else {
                h=mid-1;
            }
        }
    }
    
    if (t == nums[l]) {
        return l;
    } else {
        return -1;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,i, target;
        cin >> n;
        int a[n];

        for (i=0; i<n; ++i) {
            cin >> a[i];
        }

        cin >> target;

        find_index(a,target, n);
    }
    return 0;
}