#include <bits/stdc++.h>
using namespace std;

long long connectRopes(vector<long long > arr)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int n= arr.size();
    priority_queue< long long, vector<long long  >,greater<long long > > heap(arr.begin(),arr.end());
    long long cost =0 ;
    while (heap.size() > 1)
    {
        long long max1 = heap.top();
        heap.pop();
        long long max2 = heap.top();
        heap.pop();
        heap.push(max1 + max2);
        cost += max1 + max2;   
    }
    return cost;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    int n;
    cin>>n;
    vector<long long > arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    long long result = connectRopes(arr);
    cout<<result<<"\n";
    return 0;
}
