#include <bits/stdc++.h>
using namespace std;

long long trailingZeros(long long n)
{
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	long long count = 0;
	for (long long i = 5; n / i >= 1; i *= 5)
		count += n / i;
	return count;
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
	long long  n;
	cin >> n;
	cout << trailingZeros(n) << endl;
	return 0;
}






