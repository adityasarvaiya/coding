#include <bits/stdc++.h>
#define ll long long

using namespace std;

int cheapestFlights(int n, vector<vector<int>>& flights, int src, int dst, int K) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        vector<vector<pair<int, int> > > adjList(n,vector<pair<int,int> >());
        for( auto f : flights )
            adjList[f[0]].push_back( { f[1], f[2] } );
        
        
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > minHeap;
        minHeap.push( { 0, src, K+1 } ); // cost, vertex, hops
        
        while( !minHeap.empty() ) {
            auto t = minHeap.top(); minHeap.pop();
        
            int cost = t[0];
            int curr = t[1];
            int stop = t[2];
            if( curr == dst)
                return cost;

            if( stop > 0 ) {
                for( auto next : adjList[curr] ) {
                    minHeap.push( { cost+next.second, next.first, stop-1 } );
                }
            }
        }
        return -1;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }


int main() {

    int n;cin>>n;

    int m;cin>>m;

    vector<vector<int> > flights;

    for(int i=0;i<m;i++){
        vector<int> b(3,0);
        cin>>b[0]>>b[1]>>b[2];
        b[0]--;
        b[1]--;
        flights.push_back(b);
    }
    int src,dst;
    cin>>src>>dst;
    src--;dst--;
    int k;cin>>k;
    int ans = cheapestFlights(n,flights,src,dst,k);
    cout<<ans<<endl;
}
