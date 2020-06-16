#include <bits/stdc++.h>
using namespace std;


long long contigiousSequence( vector<long long > &arr) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	long long mx = INT_MIN, curmx = 0;
	for ( int i = 0; i < arr.size() ; i++) {
		curmx = curmx + arr[i];
		if ( curmx > mx) mx =  curmx;
		if (curmx < 0) curmx = 0;
	}
	return mx;
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
	int n;
	cin >> n;
	vector<long long> arr(n);
	for ( int i = 0; i < n ; i++)  cin >> arr[i];
	long long mx = contigiousSequence(arr);
	cout << mx << endl;
}
