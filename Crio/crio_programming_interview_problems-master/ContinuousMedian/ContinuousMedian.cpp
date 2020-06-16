#include<bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
int heapMax=0,heapMin=0;
int maxHeap[500003]={0},minHeap[500003]={0};

void heapifyDown(int node,int bitset)
{
	if(bitset==0)
	{
		if(maxHeap[node]<max(maxHeap[node*2],maxHeap[(node*2)+1]))
		{
			int temp=maxHeap[node];
			maxHeap[node]=max(maxHeap[node*2],maxHeap[(node*2)+1]);
			if(maxHeap[node*2]>maxHeap[(node*2)+1])
			{
				maxHeap[node*2]=temp;
				heapifyDown(node*2,bitset);
			}
			else
			{
				maxHeap[(node*2)+1]=temp;
				heapifyDown((node*2)+1,bitset);
			}
		}
	}
	if(bitset==1)
	{
		if(minHeap[node]>min(minHeap[node*2],minHeap[(node*2)+1]))
		{
			int temp=minHeap[node];
			minHeap[node]=min(minHeap[node*2],minHeap[(node*2)+1]);
			if(minHeap[node*2]<minHeap[(node*2)+1])
			{
				minHeap[node*2]=temp;
				heapifyDown(node*2,bitset);
			}
			else
			{
				minHeap[(node*2)+1]=temp;
				heapifyDown((node*2)+1,bitset);
			}
		}
	}
}
void heapifyUp(int node,int bitset)
{
	if(bitset==0)
	{
		while(node!=1)
		{
			if(maxHeap[node]>=maxHeap[node/2])
			{
				int temp=maxHeap[node];
				maxHeap[node]=maxHeap[node/2];
				maxHeap[node/2]=temp;
				node/=2;
			}
			else
				break;
		}
	}
	if(bitset==1)
	{
		while(node!=1)
		{
			if(minHeap[node]<=minHeap[node/2])
			{
				int temp=minHeap[node];
				minHeap[node]=minHeap[node/2];
				minHeap[node/2]=temp;
				node/=2;
			}
			else
				break;
		}
	}
}
void push(int val,int bitset)
{
	if(bitset==1)
	{
		minHeap[heapMin]=val;
		heapifyUp(heapMin,bitset);
	}
	else
	{
		maxHeap[heapMax]=val;
		heapifyUp(heapMax,bitset);
	}
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

vector<int> continuousMedian(int ar[],int n)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	vector<int> ans;
	memset(maxHeap,-1,sizeof maxHeap);
	for(int i=1;i<=500000;i++)
		minHeap[i]=(int)(1e9+100);

	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			maxHeap[1]=ar[i];
			heapMax++;
			cout<<maxHeap[1]<<"\n";
			continue;
		}
		if(heapMax==heapMin)
		{
			if(ar[i]>minHeap[1])
			{
				int temp1=minHeap[1];
				minHeap[1]=ar[i];
				heapifyDown(1,1);
				heapMax++;
				push(temp1,0);
			}
			else
			{
				heapMax++;
				push(ar[i],0);
			}

		}
		else if(heapMax>heapMin)
		{
			if(ar[i]<maxHeap[1])
			{
				int temp1=maxHeap[1];
				maxHeap[1]=ar[i];
				heapifyDown(1,0);
				heapMin++;
				push(temp1,1);
			}
			else
			{
				heapMin++;
				push(ar[i],1);
			}
		}
		if(i == 0 || i%2 == 1) // 0 based indexing
		{
			ans.push_back((minHeap[1]+maxHeap[1])/2);
		}
		else
		{
			ans.push_back(maxHeap[1]);
		}
	}
	return ans;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
	int n;
	cin>>n;
	int ar[n+9];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	vector<int> answer=continuousMedian(ar,n);
	for (auto it:answer)
	{
		cout<<it<<"\n";
	}
}
