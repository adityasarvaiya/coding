
#include<bits/stdc++.h>
using namespace std;

bool isOneAway(string &a , string &b) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	int sizea = a.size();
	int sizeb = b.size();
	if(abs(sizeb - sizea) > 1) {
		return false;
	}
	int i = 0 , j = 0 , count = 0;
	while(i < sizea && j < sizeb) {
		if(a[i] != b[j]) {
			count++;
			if(count > 1) {
				return false;
			}
			if(sizea == sizeb) {
				i++;
				j++;			
			}
			if(sizea < sizeb) {
				j++;
			}
			if(sizea > sizeb) {
				i++;
			}
		}
		else {
			i++;
			j++;
		}
	}
	return true;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		string a,b;
		cin >> a >> b;
		bool answer = isOneAway(a,b);
		if(answer) {
			cout << "True\n";
		} else {
			cout << "False\n";
		}
	}
	return 0;
}
