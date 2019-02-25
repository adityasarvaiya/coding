// https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1

#include<bits/stdc++.h>
using namespace std;
int max_sum(int A[],int N);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }
        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method*/
int max_sum(int A[],int N)
{
    int i, max_product=0,curr=0, tot_sum=0;

    for (i = 0; i < N; ++i) {
        tot_sum += A[i];
    }
    
    for (i = 0; i < N; ++i) {
        curr += A[i] * i;
    }
    
    max_product = curr;
    
    for (i = 1; i < N; ++i) {
        curr = curr - (tot_sum - A[i-1]) + A[i-1]*(N-1);
        max_product = max(max_product, curr);
    }
    

    return max_product;
}