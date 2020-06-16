#include<bits/stdc++.h>
using namespace std;

vector<string> fizzBuzz(int n) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	vector<string>ans;
	for(int i = 1 ; i <= n ; i++) {
		if(i%15 == 0) {
			ans.push_back("FizzBuzz");
			continue;
		}
		if(i%3 == 0) {
			ans.push_back("Fizz");
			continue;	
		}
		if(i%5 == 0) {
			ans.push_back("Buzz");
			continue;
		}
		ans.push_back(to_string(i));
	}
	return ans;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
	int n;
	cin >> n;
	vector<string> answer = fizzBuzz(n);
	for(int i = 0 ;i < answer.size() ; i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}
