#include <bits/stdc++.h>
using namespace std;

long long connectRopes(vector<long long > arr)
{
    if(arr.size() == 0 or arr.size() == 1){ // case where there is an empty arr
        return 0;
    }
    long long total = 0;
    priority_queue < long long , vector<long long>, greater <long long> > pq;
    for (int i = 0; i < arr.size(); i++){
        pq.push(arr[i]);    // this will have the shortest length at the top
    }
    // the idea is to keep on adding the two smallest lengths to minimize the cost 
    // we use heaps to keep track of the smallest element all the time 
    while(pq.size() != 1){
        long long f_min = pq.top();
        pq.pop();
        long long s_min = pq.top();
        pq.pop();
        long long sum = f_min + s_min;
        pq.push(sum);  // add it back into the min heap as it needs to be added with the other lengths as well.
        total += sum;
    }
    return total;
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
