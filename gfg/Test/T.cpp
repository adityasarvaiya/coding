#include <bits/stdc++.h>
using namespace std;
 
void f(vector <int> arr) { 
  stack < int > s; 
  
  int n = arr.size();
  s.push(arr[0]); 
  
  for (int i = 1; i < n; i++) { 
  
    if (s.empty()) { 
      s.push(arr[i]); 
      continue; 
    } 
  
    while (s.empty() == false && s.top() < arr[i]) 
    {          
        // cout << s.top() << " --> " << arr[i] << endl; 
        cout << arr[i] << " "; 
        s.pop(); 
    } 
  
    s.push(arr[i]); 
  } 
  
  while (!s.empty()) { 
    // cout << s.top() << " --> " << -1 << endl; 
    cout << -1 << " "; 
    s.pop(); 
  } 

  cout << endl;
} 


int main()
{
    int n;
    cin >> n;

    vector <int> A(n);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    f(A);
    return 0;
}