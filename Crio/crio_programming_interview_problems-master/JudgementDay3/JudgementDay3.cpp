#include <bits/stdc++.h>
using namespace std;

int judgementDay3(int n,int m,int a,int b,int c,vector<vector<int> > &roads){
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	int MAX = 2000;
	//Making adjacency Matrix
    vector<vector<vector<int> > > adj;
    for(int i=0;i<n+1;i++){
    	vector<vector<int> > x;
        adj.push_back(x);
    }

    for(auto road:roads){
        adj[road[0]].push_back({road[1],road[2],road[3]});
        adj[road[1]].push_back({road[0],road[2],road[3]});
    }

    //initiating required data structures
    vector<int> timeFromAz(n+1,MAX);    //minimum time taken from Azazel's source to any vertex
    vector<int> pathOfAz;               //Path taken by Azazel
    vector<int> timeToMaster;           //Time taken at every node by Azazel
    vector<int> timeOfSam(n+1,MAX);     //minimum time taken from Sam & Dean's source to every vertex
    priority_queue<vector<int>,vector<vector<int> >, greater<vector<int> > > pq;





    timeFromAz[b]=0;
    //Finding the shortest path for Azazel
    pq.push({0,b,0});
    while(!pq.empty()){
        auto top = pq.top();pq.pop();
        int curr = top[1];

        if(curr==c){
            timeToMaster = top;
            timeToMaster.erase(timeToMaster.begin());       //removing cost and current node, not needed
    		timeToMaster.erase(timeToMaster.begin());
            break;
        }


        for(auto s:adj[curr]){
        	if(timeFromAz[s[0]]>timeFromAz[curr]+s[1]){
        		timeFromAz[s[0]]=timeFromAz[curr]+s[1];
        		vector<int> t;
	            t.push_back(timeFromAz[s[0]]);
	            t.push_back(s[0]);
	            for(int i=2;i<top.size();i++){
	                t.push_back(top[i]);
	            }
	            t.push_back(s[1]);
	            pq.push(t);
        	}
        }
    }

    //If never reached the Master Church print -1
    if(timeToMaster.empty()){
    	return -1;
    }

    //Retracing the edges to get the nodes of Azazel traversal
    int curr = b;
    pathOfAz.push_back(b);
    for(int i=1;i<timeToMaster.size();i++){
        for(auto s:adj[curr]){
            if(s[1]==timeToMaster[i]){
                pathOfAz.push_back(s[0]);
                curr = s[0];
            }
        }

    }

    //Shortest path of Sam to all other nodes
    timeOfSam[a]=0;
    for(int i=0;i<n;i++){
        for(auto road:roads){
            if(timeOfSam[road[0]]!=MAX){
                //adding time of repair if timeofSam till this node<road repair time
                int x = max(0,road[3]-timeOfSam[road[0]]);
                x +=(timeOfSam[road[0]]+road[2]);
                timeOfSam[road[1]] = min(timeOfSam[road[1]],x);
            }
            if(timeOfSam[road[1]]!=MAX){
                //adding time of repair if timeofSam till this node<road repair time
                int x = max(0,road[3]-timeOfSam[road[1]]);
                x +=(timeOfSam[road[1]]+road[2]);
                timeOfSam[road[0]] = min(timeOfSam[road[0]],x);
            }
        }
    }

    //prefix sum of time taken by azazel in his path
    for(int i=1;i<timeToMaster.size();i++){
        timeToMaster[i]+=timeToMaster[i-1];
    }
    int ans = 0;
    for(int i = 0;i<timeToMaster.size();i++){

        if(timeOfSam[pathOfAz[i]]<timeToMaster[i]){
            break;
        }
        if(timeOfSam[pathOfAz[i]]==timeToMaster[i]){
            ans++;
            break;
        }
        ans++;
    }

    return ans;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main(){   

    int n,m,a,b,c;cin>>n>>m>>a>>b>>c;

    vector<vector<int> > roads;
    for(int i=0;i<m;i++){
        int u,v,w,r;
        cin>>u>>v>>w>>r;
        roads.push_back({u,v,w,r});
    }
    int ans = judgementDay3(n,m,a,b,c,roads);
    cout<<ans<<endl;
}