#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,tmp;
    cin >> n >> x;

    unordered_map <int, int> h;

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (h.find(tmp) == h.end()) {
            h[tmp] = 1;
        } else {
            h[tmp] += 1;
        }
    }

    while () {
        
    }
}