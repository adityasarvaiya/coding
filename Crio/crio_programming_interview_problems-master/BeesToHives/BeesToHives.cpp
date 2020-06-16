#include<bits/stdc++.h>
using namespace std;
int beesToHives(vector<int>bees, vector<int>hives){
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int ans = 0;
    sort(bees.begin(),bees.end());
    sort(hives.begin(),hives.end());
    int n = bees.size();
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, abs(bees[i]-hives[i]));
    }
    return ans;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main(){
    int n;
    cin>>n;
    vector<int>bees(n),hives(n);
    for (int i = 0; i < n; i++)
    {
        cin>>bees[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>hives[i];
    }
    int ans = beesToHives(bees,hives);
    cout<<ans;
}