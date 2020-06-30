#include<bits/stdc++.h> 
using namespace std; 

int tribonacci(int n) 
{ 
	//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	if (n <= 1) 
		return n;
	else if(n<=2)
		return 1; 
	return tribonacci(n-1) + tribonacci(n-2)+ tribonacci(n-3); 
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main () 
{ 
	int n;
	cin>>n;
	cout << tribonacci(n); 
}
