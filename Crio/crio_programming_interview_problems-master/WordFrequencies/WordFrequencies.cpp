#include <bits/stdc++.h>
using namespace std;
vector< pair<string , int > > count( vector<string> &words) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    map<string, int> WordCount;
    for ( auto word : words) {
        WordCount[word]++;
    }
    vector<pair<string , int> > ans;
    for ( auto it : WordCount) {
        ans.push_back({it.first, it.second});
    }
    return ans;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
    int t, m;
    cin >> t;
    map<string , int> M;
    vector<string> words;
    while (t--) {
        string s;
        cin >> s;
        words.push_back(s);
    }
    vector<pair<string , int > > Freq = count(words);
    for ( auto it : Freq) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}






