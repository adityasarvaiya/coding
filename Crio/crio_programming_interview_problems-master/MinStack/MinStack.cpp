#include <bits/stdc++.h>
using namespace std;
stack<int> S , minstack;

void push( int x) {

    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    S.push(x);
    if (minstack.empty() || minstack.top() >= x) {
        minstack.push(x);
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

void pop() {

    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if ( !minstack.empty() && S.top() == minstack.top() ) {
        minstack.pop();
    }
    if ( !S.empty()) S.pop();
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int findMin() {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if (S.empty() || minstack.empty()) return -1;
    return minstack.top();
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    int n, m, t;
    cin >> t;
    while (t--) {
        int ch;
        cin >> ch;
        if ( ch  == 1) {
            cin >> n;
            push(n);
        }
        else if ( ch == 2)
            pop();
        else
            cout << findMin() << endl;
    }

}






