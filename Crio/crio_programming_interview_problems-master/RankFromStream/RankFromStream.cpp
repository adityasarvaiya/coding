#include<bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
using namespace std;
#include "Solution.cpp"

int main() {
    FastIO();
    int q;
    cin >> q;
    Solution solution;

    for(int _q = 0 ; _q < q ; ++_q) {
        char ch;
        int x;
        cin >> ch >> x;
        if(ch == '+') {
            solution.track(x);
        } else {
            cout << solution.getRankOfNumber(x) << "\n";
        }
    }
}
