#include "FastIO.hpp"
#include "ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class WordBreak {
  public:
    bool wordBreak(string s, vector<string> wordDict) {
        // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
        // Your implementation goes here
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS

        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
        return true;
    }
};

int main() {
    FastIO();
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> wordDict;
    ReadMatrix<string>().OneDMatrix(n, wordDict);
    bool result = WordBreak().wordBreak(s, wordDict);
    cout << boolalpha << result;
    return 0;
}
