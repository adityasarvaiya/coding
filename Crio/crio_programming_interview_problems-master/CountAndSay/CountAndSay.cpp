#include <bits/stdc++.h>
using namespace std;

class CountAndSay {
public:
    string countAndSay(int n) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        string arr[30];
        arr[0] = "1";
        for (int i = 1; i < n; i++) {
            string str = "";
            int x = arr[i - 1].size();
            for (int j = 0; j < x;) {
                char ch = arr[i - 1][j];
                int count = 1;
                j++;
                while (j < x && arr[i - 1][j] == ch) count++, j++;
                str += '0' + count;
                str += ch;
            }
            arr[i] = str;
        }
        return arr[n - 1];
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {

    int n;
    cin >> n;
    string result = CountAndSay().countAndSay(n);
    cout << result;
    return 0;
}
