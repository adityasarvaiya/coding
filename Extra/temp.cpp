#include<bits/stdc++.h>
using namespace std;

int main() 
{
    string n = "25114";

    cout << n << endl;
    // n[0] = 0;
    cout << n << endl << n.at(1) << endl;


    if (n[0] < '3') {
        cout << "yes" << endl;
    }

    if (n[0] < '1') {
        cout << "no" << endl;
    }

    return 0;
}