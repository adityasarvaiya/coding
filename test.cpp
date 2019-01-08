#include<bits/stdc++.h>

using namespace std;

int main() 
{ 

	int x = 112234;
	int y = 4566;
	string s = to_string(x);
	string s1 = to_string(y);

	s.append(s1);

	cout << s;
    
	return 0; 
}