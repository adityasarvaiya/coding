#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class LetterCombinationsOfPhoneNumber {
  public:
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    void rec(int index, string digits, vector<vector<char>> v,
             vector<string>& res, string str) {
        if (index >= int(digits.size())) {
            res.push_back(str);
            return;
        }
        for (int i = 0; i < int(v[digits[index] - '0'].size()); i++) {
            str[index] = v[digits[index] - '0'][i];
            rec(index + 1, digits, v, res, str);
        }
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    vector<string> letterCombinationsOfPhoneNumber(string digits) {
        vector<string> res;
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        vector<vector<char>> v{{},
                               {},
                               {'a', 'b', 'c'},
                               {'d', 'e', 'f'},
                               {'g', 'h', 'i'},
                               {'j', 'k', 'l'},
                               {'m', 'n', 'o'},
                               {'p', 'q', 'r', 's'},
                               {'t', 'u', 'v'},
                               {'w', 'x', 'y', 'z'}};

        if (digits == "")
            return res;
        string str = digits;
        rec(0, digits, v, res, str);
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        return res;
    }
};

int main() {
    FastIO();
    string digits;
    cin >> digits;
    vector<string> combinations =
        LetterCombinationsOfPhoneNumber().letterCombinationsOfPhoneNumber(digits);
    PrintMatrix<string>().OneDMatrix(combinations, " ");
    return 0;
}