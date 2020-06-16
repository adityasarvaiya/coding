#include <bits/stdc++.h>
using namespace std;

class FractionToRecurringDecimal {
  public:
    string fractionToRecurringDecimal(int numerator, int denominator) {
        string res = "";
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        bool isNegative = false;
        if (numerator > 0 && denominator < 0) {
            isNegative = true;
        } else if (numerator < 0 && denominator > 0) {
            isNegative = true;
        }
        long num = numerator;
        num = abs(num);

        long den = denominator;
        den = abs(den);

        long beforeDecimal = num / den;
        res = to_string(beforeDecimal);
        long rem = num % den;
        map<long, int> remainders;
        vector<long> afterDecimal;

        while (rem > 0 && remainders[rem] == 0) {
            remainders[rem] = int(afterDecimal.size()) + 1;

            rem = rem * 10;
            afterDecimal.push_back(rem / den);
            rem %= den;
        }
        if (afterDecimal.size() > 0) {
            res += ".";
            if (rem == 0) {
                for (int i = 0; i < int(afterDecimal.size()); ++i) {
                    res += to_string(afterDecimal[i]);
                }
            } else {
                for (int i = 0; i < remainders[rem] - 1; ++i) {
                    res += to_string(afterDecimal[i]);
                }
                res += "(";

                for (int i = remainders[rem] - 1; i < int(afterDecimal.size());
                     ++i) {
                    res += to_string(afterDecimal[i]);
                }
                res += ")";
            }
        }
        if (isNegative) {
            res = "-" + res;
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        return res;
    }
};

int main() {
    int numerator, denominator;
    cin >> numerator >> denominator;
    string result =
        FractionToRecurringDecimal().fractionToRecurringDecimal(numerator, denominator);
    cout << result;
    return 0;
}
