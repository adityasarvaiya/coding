#include<bits/stdc++.h>
using namespace std;
int moduloUsingRecursion(int dividend,int divisor)
{
	//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	if(divisor==0)
		return -1;
	else if(dividend<divisor)
		return dividend;
	return moduloUsingRecursion(dividend-divisor,divisor);
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
	int divisor,dividend;
	cin>>dividend>>divisor;
	cout<<moduloUsingRecursion(dividend,divisor);
}
