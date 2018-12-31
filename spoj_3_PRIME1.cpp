#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long int i, j, x, y;
    int flag;

    while (n--) {
        flag = 0;
        cin >> x;
        cin >> y;

        bool p[y + 1];

        memset(p, true, sizeof(p));
        p[0] = false;
        p[1] = false;
        
        for (i = 2; i <= sqrt(y); ++i) {
            if (p[i]) {
                for (j = i*i; j <= y; j+=i) {
                    p[j] = false;
                }
            }            
        }

        for (i = x; i <= y; ++i) {
            if (p[i] == true) {
                cout << i << endl;
            }
        }

        cout << endl;
    }

    return 0;
}