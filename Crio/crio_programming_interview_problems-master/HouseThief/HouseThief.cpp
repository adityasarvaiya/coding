#include <bits/stdc++.h>
using namespace std;

int houseThief(int n,vector<int> &wealth){
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<int> loot(n,0);
    loot[0]=wealth[0];
    loot[1]=max(wealth[0],wealth[1]);

    for(int i=2;i<n;i++){
        loot[i]=max(loot[i-1],loot[i-2]+wealth[i]);
    }

    return loot[n-1];
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main() {

   int n;cin>>n;
   vector<int> wealth(n,0);
   vector<int> houses;
   for(int i =0;i<n;i++){
        cin>>wealth[i];
   }

   int ans = houseThief(n,wealth);
   cout<<ans<<endl;
}
