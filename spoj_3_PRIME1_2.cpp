#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int x) 
{
    int i, last = sqrt(x);
    for (i = 2; i <= last; i++) {
        if (x % i == 0) {
            return 0;
        }
    }

    return 1;
}

bool process(int x, int p[], int n)
{
    int i, last = sqrt(x);

    for (i = 0; i < n && p[i] <= last; i++) {
        if (x % p[i] == 0) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char const *argv[])
{
    int x,y,t,n,i,index;
    int prime[32000];

    cin >> n;
    index = 0;

    for (i = 2; i < 32000; i++) {
        if (is_prime(i)) {
            prime[index++] = i;
        }
    }


    while (n--) {
        cin >> x >> y;

        if (x == 0 || x == 1) {
            x = 2;
        }

        while (x <= y) {
            if (process(x, prime, index)) {
                cout << x << endl;
            }
            x++;
        }

        cout << endl;
    }

    return 0;
}
