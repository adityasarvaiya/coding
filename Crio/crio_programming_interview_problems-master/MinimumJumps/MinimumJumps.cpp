#include <bits/stdc++.h> 
using namespace std; 
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
int min(int x, int y) { return (x < y) ? x : y; } 
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int minimumJumps(int arr[], int n) 
{ 
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	if(n==1)
		return 0;
	int* jumps = new int[n]; 
	int i, j; 

	if (n == 0 || arr[0] == 0)
		return -1; 
	jumps[0] = 0; 
	for (i = 1; i < n; i++) { 
		jumps[i] = INT_MAX; 
		for (j = 0; j < i; j++) { 
			if (i <= j + arr[j] && jumps[j] != INT_MAX) { 
				jumps[i] = min(jumps[i], jumps[j] + 1); 
				break; 
			} 
		} 
	} 
	if(jumps[n-1]==INT_MAX)
		return -1;
	else
		return jumps[n - 1]; 
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
} 
int main() 
{ 
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout <<minimumJumps(arr, n); 
} 
