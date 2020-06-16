#include<bits/stdc++.h>
using namespace std;
//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
long long mod = 1000000007;
map<string, long long> freq, answer;
map<string, string> dsu;

vector< pair<string, string> > vec;

string findSet(string s)
{
    if (dsu[s] != s)
        dsu[s] = findSet(dsu[s]);
    return dsu[s];
}

void join(string s1, string s2)
{
    if (findSet(s1) < findSet(s2))
        dsu[findSet(s2)] = findSet(s1);
    else
        dsu[findSet(s1)] = findSet(s2);
}
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
vector<pair<string, long long> > babyNames(vector<string> names,vector<int> frequency,vector<pair<string,string> > synonymPair)
{
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        dsu[it->first] = it->first;
    }
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        dsu[it->first] = it->first;
        dsu[it->second] = it->second;
    }
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        join(it->first, it->second);
    }
    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        answer[findSet(it->first)] = ((answer[findSet(it->first)] % mod) + (it->second % mod)) % mod;
    }
    vector<pair<string, long long> > res;
    for (auto it = answer.begin(); it != answer.end(); it++)
    {
        res.push_back(make_pair(it->first, it->second));
    }
    sort(res.begin(), res.end());
    return res;
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    long long n;
    cin >> n;
    vector<string> names;
    vector<int> frequency;
    vector< pair<string,string> > synonymPair;
    for (long long i = 1; i <= n; i++)
    {
        string s;
        long long f;
        cin >> s >> f;
        freq[s] = f;
        names.push_back(s);
        frequency.push_back(f);
    }
    long long m;
    cin >> m;
    for (long long i = 1; i <= m; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        vec.push_back(make_pair(s1, s2));
        synonymPair.push_back(make_pair(s1,s2));
    }
    vector<pair<string, long long> > res=babyNames(names,frequency,synonymPair);
    for (auto it = res.begin(); it != res.end(); it++)
    {
        cout << it->first << " " << it->second << "\n";
    }
}

