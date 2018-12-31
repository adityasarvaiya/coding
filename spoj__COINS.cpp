#include <bits/stdc++.h>
using namespace std;

int exchange(long int n) 
{
    long int sum = 0, flag = 0;

    if (n / 4 > 1) {
        sum = sum + exchange(n/4);
        flag = 1;
    }

    if (n / 3 > 1) {
        sum = sum + exchange(n/3);
        flag = 1;
    }

    if (n / 2 > 1) {
        sum = sum + exchange(n/2);
        flag = 1;
    }

    if (flag == 0) {
        return n;
    } else {
        if (n > sum) {
            return n;
        } else {
            return sum;
        }
    }
}

int main() 
{
    long int n;
    cin >> n;

    long int coins = exchange(n);

    cout << coins << endl;

    return 0;
}