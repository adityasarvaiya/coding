#include<bits/stdc++.h>
using namespace std;
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

int updateSegTree(int l,int r,int node,int val,int index,vector<int> &segTree)
{
	if(l == r)
		return segTree[node] = val;
	int mid = (l+r)/2;
	if(index >= l && index <= mid)
		updateSegTree(l,mid,2*node+1,val,index,segTree);
	else
		updateSegTree(mid+1,r,2*node+2,val,index,segTree);	
	return segTree[node] = min(segTree[2*node+1],segTree[2*node+2]);
}
int querySegTree(int l,int r,int node,int start, int end, vector<int> &segTree)
{
	if(r<start || l>end)
		return INT_MAX;
	if(l>=start && r<=end)
		return segTree[node];
	int mid = (l+r)/2;
	return min(querySegTree(l,mid,2*node+1,start,end,segTree),querySegTree(mid+1,r,2*node+2,start,end,segTree));
}
int createSegTree(int l,int r,int node,vector<int> &vec,vector<int> &segTree)
{
	if(l == r)
		return segTree[node] = vec[l];
	int mid = (l+r)/2;
	segTree[2*node+1] = createSegTree(l,mid,2*node+1,vec,segTree);
	segTree[2*node+2] = createSegTree(mid+1,r,2*node+2,vec,segTree);
	return segTree[node] = min(segTree[2*node+1],segTree[2*node+2]);
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

vector<int> lilliput(int n,vector<int> vec,int q,vector< pair<char, pair<int,int> > > query)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

	vector<int> segTree;
	segTree.resize(5*n);
	vector<int> answer;
	createSegTree(0,n-1,0,vec,segTree);
	for(int i=0;i<q;i++)
	{
	 	if(query[i].first == 'u')
	 	{
	 	 	updateSegTree(0,n-1,0,query[i].second.second,query[i].second.first,segTree);
	 	}
	 	else if(query[i].first == 'q')
	 	{
	 		answer.push_back(querySegTree(0,n-1,0,query[i].second.first,query[i].second.second,segTree));
	 	}
	}
	return answer;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{	
	int n,q,l,r;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	
	cin>>q;
	char ch;
	vector<pair<char, pair<int,int> > > query;
	for(int i=0;i<q;i++)
	{
		cin>>ch>>l>>r;
		pair<char,pair<int,int> >  p =make_pair(ch,make_pair(l,r));
		query.push_back(p);
	}
	vector<int> answer = lilliput(n,vec,q,query);
	for(int ans : answer)
	 	cout<<ans<<"\n";
}
