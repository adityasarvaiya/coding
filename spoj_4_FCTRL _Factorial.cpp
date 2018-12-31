#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    //for faster io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned int n,x,t;
    cin >> n;


    while(n--) {

        t = 0;
        cin >> x;

        while (x >= 5) {
            x = x / 5;
            t += x;
        }

        cout << t << endl;
    }    

    return 0;
}
