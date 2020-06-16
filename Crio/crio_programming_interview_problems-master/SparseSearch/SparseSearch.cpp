#include<bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
using namespace std;

vector<int> sparseSearch(vector<string> &sparseArray, vector<string> &queries) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    map<string, int> position;

    for(int i = 0 ; i < sparseArray.size(); ++i) {
        if(sparseArray[i] != "") {
            position[sparseArray[i]] = i;
        }
    }

    vector<int> result(queries.size());
    for(int i = 0 ; i < queries.size() ; ++i) {
        string target = queries[i];
        result[i] = ((position.find(target) == position.end()) ? -1: position[target]);
    }

    return result;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<string> sparseArray(n);
    for(int i = 0; i < n ; ++i) {
        string s;
        cin >> s;
        if(s == "$") {
            s = "";
        }
        sparseArray[i] = s;
    }
    int q;
    cin >> q;
    vector<string> queries(q);
    for(int i = 0 ; i < q ; ++i) {
        cin >> queries[i];
    }
    vector<int> result = sparseSearch(sparseArray, queries);
    for(int i = 0 ; i < result.size(); ++i) {
        cout << result[i] << "\n";
    }
}
