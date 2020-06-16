#include <bits/stdc++.h>
using namespace std;

long long evaluateExpression(long long n, vector<string > expression)
{
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    stack<long long > stac;
    for( int i=0; i< n;i++)
    {
        string s = expression[i];
        if(s != "+" && s != "-" && s != "*" && s != "/")
            stac.push(stoll(expression[i]));
        else
        {
            long long number2 = stac.top(),result =0;
            stac.pop();
            long long number1 = stac.top();
            stac.pop();
            if( s == "+")
                result = number1 + number2;
            else if(s == "-")
                result = number1 - number2;
            else if(s == "/")
                result = number1 / number2;
            else if(s == "*")
                result = number1 * number2;
            stac.push(result);
        }
    }
    assert(stac.size()==1);
    return stac.top();
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    long long n;
    cin>>n;
    vector<string > expression(n);
    for(int i=0;i<n;i++)
        cin>>expression[i];
    long long result = evaluateExpression(n,expression);
    cout<<result<<"\n";
    return 0;
}
