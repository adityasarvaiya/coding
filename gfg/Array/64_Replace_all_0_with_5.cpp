// https://practice.geeksforgeeks.org/problems/replace-all-0s-with-5/1
// Basic

#include<bits/stdc++.h>
using namespace std;
int convertFive(int n);
 
// Driver program to test above function
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	cout<<convertFive(n)<<endl;
    }
}

int convertFive(int n)
{
    string st = to_string(n);
    int len = st.length(), i;
    
    for (i = 0; i < len; ++i) {
        if (st[i] == '0') {
            st[i] = '5';
        }
    }
    
    return stoi(st); 
//Your code here
}