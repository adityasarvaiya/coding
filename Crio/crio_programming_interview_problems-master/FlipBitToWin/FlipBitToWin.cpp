#include<bits/stdc++.h>
using namespace std;

int flipBitToWin(long long x) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	int answer = 0 , bits;
	if(x != 0) {
		bits = log2(x) + 1;
	}
	else {
		bits = 1;
	}
	for(int i = 0 ; i < bits ; i++) {

		long long temp = x | (1LL << i);
		int count = 0;
		for(int j = 0 ; j < bits ;j ++) {
			if(((temp >> j) & 1)) {
				count++;
				answer = max(answer,count);
			} else {
				count = 0;
			}
		}
	}
	return answer;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
	long long x;
	cin >> x;
	int result = flipBitToWin(x);
	cout << result;
	return 0;	
}
