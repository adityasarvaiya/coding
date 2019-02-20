// function problem
// https://practice.geeksforgeeks.org/problems/peak-element/1
// https://leetcode.com/problems/find-peak-element/solution/

#include<bits/stdc++.h>
using namespace std;
int peak(int arr[], int n);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peak(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}
	// your code goes here
	return 0;
}

int peak(int nums[], int n)
{
    int i;
    
    int l = 0, r = n-1, mid;
        
        while (l < r) {
            mid = (l+r)/2;
            
            if (nums[mid] > nums[mid+1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
}