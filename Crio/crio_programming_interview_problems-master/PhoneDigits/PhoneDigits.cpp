#include<bits/stdc++.h>
using namespace std;

void  phoneDigits(vector<string>& ans, vector<int> number, int curr_digit, string output, int n)
{
	//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	static char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl",
	                                "mno", "pqrs", "tuv", "wxyz"
	                               };

	int i;
	if (curr_digit == n)
	{
		ans.push_back(output);
		return ;
	}

	for (i = 0; i < strlen(hashTable[number[curr_digit]]); i++)
	{
		output[curr_digit] = hashTable[number[curr_digit]][i];
		phoneDigits(ans, number, curr_digit + 1, output, n);
		if (number[curr_digit] == 0 || number[curr_digit] == 1)
			return;
	}
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
	int n; cin >> n;
	vector<int> number(n);
	string result ;

	for ( int i = 0; i < n; i++) cin >> number[i];
	for ( int i = 0; i < n; i++) result.push_back(number[i]);
	vector<string> ans ;
	phoneDigits(ans, number, 0, result , n);
	for ( auto it : ans) {
		cout << it << " ";
	}

}