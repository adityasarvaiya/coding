#include<bits/stdc++.h>
using namespace std;
#include "Solution.cpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int main() {
    int n;
    cin >> n;
    vector<int> list(n);
    for(int i = 0 ; i < n ; ++i) {
        cin >> list[i];
    }
    int k;
    cin >> k;

    ListNode* head = ListNode().createList(list);

    int result = returnKthToLast(head , k);
    cout << result << "\n";
    return 0;
}
