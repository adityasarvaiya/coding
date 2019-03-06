#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    unordered_map <int, string > units;
    unordered_map <int, string > tens;
    unordered_map <int, string > teens;

    units[0] = "";
    units[1] = "One ";
    units[2] = "Two ";
    units[3] = "Three ";
    units[4] = "Four ";
    units[5] = "Five ";
    units[6] = "Six ";
    units[7] = "Seven ";
    units[8] = "Eight ";
    units[9] = "Nine ";

    tens[0] = "";      
    tens[2] = "Twenty ";   
    tens[3] = "Thirty ";   
    tens[4] = "Forty ";   
    tens[5] = "Fifty ";   
    tens[6] = "Sixty ";   
    tens[7] = "Seventy ";   
    tens[8] = "Eighty ";   
    tens[9] = "Ninety ";   

    teens[0] = "Ten";
    teens[1] = "Eleven";
    teens[2] = "Twelve";
    teens[3] = "Thirteen";
    teens[4] = "Forteen";
    teens[5] = "Fifteen";
    teens[6] = "Sixteen";
    teens[7] = "Seventeen";
    teens[8] = "Eighteen";
    teens[9] = "Nineteen";

    while (t--) {
        string n;
        int i, digits, len;
        vector <string> out;

        cin >> n;
        len = n.size();

        for (i = len-1; i >= 0; --i) {
            if (len-1-i == 0) {
                out.push_back(units[ n[i] - '0' ]);
            } else if (len-1-i == 1) {
                if (n[i] - '0' == 1) {
                    out.pop_back();
                    out.push_back(teens[ n[i+1] - '0']);
                } else {
                    out.push_back(tens[ n[i] - '0' ]);
                }
            } else if (len-1-i == 2) {
                // if (n[i+1] - '0' != 0 | n[i+2] - '0' != 0) {
                //     out.push_back("And ");
                // }
                if (n[i] - '0' != 0) {
                    out.push_back("Hundred ");
                }
                out.push_back(units[ n[i] - '0']);
            } else if (len-1-i == 3){
                out.push_back("Thousand ");
                out.push_back(units[ n[i] - '0']);
            } else if (len-1-i == 4){
                if (n[i] - '0' == 1) {
                    out.pop_back();
                    out.push_back(teens[ n[i+1] - '0']);
                } else {
                    out.push_back(tens[ n[i] - '0' ]);
                }
            } else if (len-1-i == 5){
                out.push_back("Hundred ");
                out.push_back(units[ n[i] - '0']);
            } else if (len-1-i == 6) {
                out.push_back("Million ");
                out.push_back(units[ n[i] - '0']);
            }
        }

        vector <string> :: reverse_iterator it;

        for (it = out.rbegin(); it != out.rend(); ++it) {
            cout << *it;
        }   

        cout << endl;

    }
    return 0;
}