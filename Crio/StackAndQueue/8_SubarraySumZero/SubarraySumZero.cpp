#include <bits/stdc++.h>
using namespace std;

string subArrayExists(int n , vector<int> arr) 
{ 
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int cursum = 0;
    unordered_set<int> sumSet;
    for (int i=0;i<n;i++) 
    { 
        cursum += arr[i];
        if (cursum == 0 || sumSet.find(cursum) != sumSet.end()) 
            return "Yes"; 
  
        sumSet.insert(cursum); 
    } 
    return "No"; 
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
} 

int main()
{
    int tests;
    cin>>tests;
    while(tests--)
    {
        int n;
        cin>>n;
        vector<int > arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        string answer = subArrayExists(n,arr);
        cout<<answer<<"\n";
    }
    return 0;
}
