#include<bits/stdc++.h>
using namespace std;

int meetingRooms(int n, vector<vector<int>>& time){
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<pair<int,int>>meeting;
    for (auto &&m : time)
    {
        meeting.push_back({m[0],m[1]});
    }
    sort(meeting.begin(), meeting.end());
    priority_queue<int,vector<int>,greater<int>>q;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int start = meeting[i].first;
        int end = meeting[i].second;
        while(q.size()>0 && q.top()<=start){
            q.pop();
        }
        q.push(end);
        ans = max(ans, (int)(q.size()));
    }
    return ans;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>time(n);
    for (int i = 0; i < n; i++)
    {
        int s,e;
        cin>>s>>e;
        time[i].push_back(s);
        time[i].push_back(e);
    }
    int ans = meetingRooms(n,time);
    cout<<ans;
}
