// Simple C++ program to print 
// next greater elements in a 
// given array 
#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
  
/* prints element and NGE pair  
for all elements of arr[] of size n */
void printNGE(vector <int> arr, int n) 
{ 
    int next, i, j; 
    for (i = 0; i < n; i++) 
    { 
        next = -1; 
        for (j = i + 1; j < n; j++) 
        { 
            if (arr[i] < arr[j]) 
            { 
                next = arr[j]; 
                break; 
            } 
        } 
        cout << next << " "; 
    }
    
    cout << endl;
} 
  
// Driver Code 
int main() 
{ 
    int n;
    
    cin >> n;
    
    vector <int> A(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
     
    printNGE(A, n); 
    return 0; 
} 