//https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
#define MAX 501
int getId(int M[MAX][MAX],int n);
int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;
    }
}


int getId(int M[MAX][MAX], int n)
{
    int j, i, f=0, celeb = -1;
    for (i = 0; i < n; ++i) {
        f = 0;
        for (j = 0; j < n; ++j) {
            if (i!=j && M[i][j] == 1) {
                f = 1;
            }
        }
        
        if (f == 0) {
            if (celeb == -1) {
                celeb = i;
            } else {
                return -1;
            }
        }
    }
    
    if (celeb == -1) {
         return celeb;
    }
    
    for (i = 0; i < n; ++i) {
        if (i != celeb && M[i][celeb] == 0) {
            return -1;
        }
    }
    
    return celeb;
}