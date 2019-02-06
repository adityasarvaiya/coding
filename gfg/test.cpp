#include <bits/stdc++.h>

using namespace std;

int main () {
    deque<int> i = {3,2,4,60,6,5};
    deque <int> :: iterator it;

    for (it = i.begin(); it!= i.end(); it++) {
        cout << *it << endl;

    }


    return 0;
}