#include<bits/stdc++.h>
using namespace std;
string convertToBinary(double n)
{
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int num=1,flag=0,r;
    double temp=n;
    vector<int> vec;
    string answer;
    while(temp!=0.0)
    {
        if(num==33)
        {
            flag=1;
        }
        temp=temp*2;
        r=floor(temp);
        temp-=(1.0*r);
        vec.push_back(r);
        num++;
    }
    if(flag==0)
    {
        answer=answer+"0.";
        for(int it=0;it<vec.size();it++)
        {
            answer+=vec[it]+'0';
        }
    }
    else
    {
        answer="ERROR";
    }
    return answer;
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
    double n;
    cin>>n;
    cout<<convertToBinary(n)<<"\n";
}
