// https://practice.geeksforgeeks.org/problems/tic-tac-toe/0
// https://www.geeksforgeeks.org/validity-of-a-given-tic-tac-toe-board-configuration/

#include <bits/stdc++.h>
using namespace std;

int won(char *a, char pl) 
{
    if (a[0] == pl) {
        if ((a[1] == pl && a[2] == pl) | (a[3] == pl && a[6] == pl) | 
            (a[4] == pl && a[8] == pl) ) {
                return 1;
        }
    }

    if (a[8] == pl) {
        if ((a[7] == pl && a[6] == pl) | (a[5] == pl && a[2] == pl)) {
                return 1;
        }
    }

    if (a[4] == pl) {
        if ((a[1] == pl && a[7] == pl) | (a[3] == pl && a[5] == pl)) {
            return 1;
        }
    }

    if (a[2] == pl && a[4] == pl) {
        if (a[6] == pl) {
            return 1;
        }
    }

    return 0;
}

void check_validity(char *a) 
{
    int i, ex=0, zero=0;
    for (i = 0; i < 9; ++i) {
        if (a[i] == 'X') {
            ex++;
        } else {
            zero++;
        }
    }

    if (zero > 4 | ex > 5) {
        cout << "Invalid" << endl;
        return;
    }

    if ( won(a, 'O') && won(a, 'X') ) {
        cout << "Invalid" << endl;
        return;
    }
    
    if (won(a, 'O') && ex == 5) {
        cout << "Invalid" << endl;
        return;
    }
    
    cout << "Valid" << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        char a[9],i;

        for (i=0; i<9; ++i) {
            cin >> a[i];
        }

        check_validity(a);
    }
    return 0;
}