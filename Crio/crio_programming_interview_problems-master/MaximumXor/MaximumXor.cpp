#include<bits/stdc++.h>
using namespace std;
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
struct TrieNode{
	TrieNode * left=NULL ;
	TrieNode * right= NULL;
};
vector<int> convertToBinary30(int val)
{
	int index = 0;
	vector<int> binary(30,0);
	while(val!=0)
	{
		binary[index]=val%2;
		val/=2;
		index++;
	}
	return binary;
}
long long findMaxXor(int val,TrieNode * start, vector<int> binaryRep)
{
	long long maxXor = 0;
	TrieNode * node = start;
	for(int i=29;i>=0;i--)
	{
		if(binaryRep[i]==0)
		{
			if(node->right!=NULL)
			{
				maxXor += 1<<i; 
				node=node->right;
			}
			else
				node=node->left;
		}
		else
		{
			if(node->left != NULL)
			{
				maxXor += 1<<i;
				node=node->left;
			}
			else
				node=node->right;
		}
	}
	return maxXor;
}
long long addIntoTrie(int val, TrieNode * start)
{
	vector<int> binaryRep = convertToBinary30(val);
	TrieNode * node = start;
	for(int i=29;i>=0;i--)
	{
		if(binaryRep[i]==0)
		{
			if(node->left == NULL)
			{
				node->left = new TrieNode;
			}
			node=node->left;
		}
		else
		{
			if(node->right == NULL)
			{
				node->right = new TrieNode;
			}
			node=node->right;	
		}
	}
	return findMaxXor(val,start,binaryRep);
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
long long maximumXor(vector<int> vec)
{
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	int n= vec.size();
	TrieNode * start = new TrieNode;
	long long maxXor =-1;
	for(int i=0;i<n;i++)
	{
		maxXor=max(maxXor,addIntoTrie(vec[i],start));
	}
	return maxXor;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	cout<<maximumXor(vec);
}
