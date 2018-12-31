#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, n3, m;
    cin >> n1 >> n2 >> n3;

    while (!((n1 == n2) &&  ((n2 == n3) && (n3 == 0)))) {

        if ((n2 - n1) == (n3 - n2)) {
            m = n3 + n2 - n1;
            cout << "AP " << m << endl; 
        } else {
            m = n2 * n3 / n1;
            cout << "GP " << m << endl;
        }

        cin >> n1 >> n2 >> n3;
    } 


    return 0;
}
