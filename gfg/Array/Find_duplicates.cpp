// https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
// not submmited

#include <bits/stdc++.h>
using namespace std;
void printDuplicates(int a[], int n);
int main()
{
  int t;
  cin>>t;
  while(t-- > 0){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		printDuplicates(a, n);
		cout<<endl;
  }
  return 0;
}

void printDuplicates(int a[], int n)
{
    int i, flag = 1;
    for (i = 0; i < n; i++) {
        a[a[i]%n] += n;
    }

    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    for (i = 0; i < n; i++) {
        if (a[a[i]%n] / n >= 2) {
            cout << a[i]%n << " ";
            a[a[i]%n] = a[a[i]%n]%n;
            flag = 0;
        }
    }

    if (flag) {
        cout << "-1";
    }

}