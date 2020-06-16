#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include <bits/stdc++.h>
#include "Solution.cpp"

using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n, nums);
    ListNode* list = ListNode().createList(nums);
    SortList obj;
    ListNode* sortedList = obj.sortList(list);
    vector<int> result = ListNode().extractList(sortedList);
    PrintMatrix<int>().OneDMatrix(result, " ");
    return 0;
}
