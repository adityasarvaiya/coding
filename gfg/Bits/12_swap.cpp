#include <bits/stdc++.h>
using namespace std;
 
unsigned int util(unsigned int n)
{
    unsigned int eve, odd;

    eve = 0xAAAAAAAA & n;
    odd = 0x55555555 & n;

    return (eve << 1 | odd >> 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t;
    unsigned int n; 
    cin >> t;
     
    while (t--) {
        cin >> n;

        cout << util(n) << endl;
    }
     
    return 0;
}