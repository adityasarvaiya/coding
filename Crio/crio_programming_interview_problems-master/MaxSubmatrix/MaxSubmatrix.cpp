#include<bits/stdc++.h> 
using namespace std; 
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
int kadane(int* arr, int* start, 
		int* finish, int n) 
{ 
	int sum = 0, maxSum = INT_MIN, i; 

	*finish = -1; 
	int local_start = 0; 

	for (i = 0; i < n; ++i) 
	{ 
		sum += arr[i]; 
		if (sum < 0) 
		{ 
			sum = 0; 
			local_start = i + 1; 
		} 
		else if (sum > maxSum) 
		{ 
			maxSum = sum; 
			*start = local_start; 
			*finish = i; 
		} 
	} 

	if (*finish != -1) 
		return maxSum; 

	maxSum = arr[0]; 
	*start = *finish = 0; 

	for (i = 1; i < n; i++) 
	{ 
		if (arr[i] > maxSum) 
		{ 
			maxSum = arr[i]; 
			*start = *finish = i; 
		} 
	} 
	return maxSum; 
} 
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
int maxSubmatrix(vector<vector<int> > M,int row,int col) 
{ 
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	int maxSum = INT_MIN, finalLeft, finalRight, 
						finalTop, finalBottom; 

	int left, right, i; 
	int temp[row], sum, start, finish; 

	for (left = 0; left < col; ++left) 
	{ 
		memset(temp, 0, sizeof(temp)); 
 
		for (right = left; right < col; ++right) 
		{ 
			
			for (i = 0; i < row; ++i) 
				temp[i] += M[i][right]; 

			sum = kadane(temp, &start, &finish, row); 

			if (sum > maxSum) 
			{ 
				maxSum = sum; 
				finalLeft = left; 
				finalRight = right; 
				finalTop = start; 
				finalBottom = finish; 
			} 
		} 
	} 

	return maxSum; 
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
} 

int main() 
{ 
	int row,col;
	cin>>row>>col;
	vector< vector<int> > M(row, vector<int> (col));
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			cin>>M[i][j];
	}
	cout<<maxSubmatrix(M,row,col); 
} 
