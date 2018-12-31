#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,sum=0;
		cin>>n;
		if(n!=0)
		{
			int a[n],b[n],c[n];
			
			for(int i=0;i<n;i++)
			cin>>a[i];
			
			for(int i=0;i<n;i++)
			cin>>b[i];

			sort(a, a+n);
			sort(b, b+n);
			
			for(int i=0;i<n;i++)
			{
				if(a[i]>=0 && a[i]<=10 &&b[i]>=0 && b[i]<=10)
					c[i]=a[i]*b[i];
				sum=sum+c[i];
			}
			
			cout<<sum<<endl;
		}		
	}
}
