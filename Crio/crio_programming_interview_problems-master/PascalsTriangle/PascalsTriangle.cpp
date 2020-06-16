#include <bits/stdc++.h>

using namespace std;

class PascalsTriangle {
public:
    vector<vector<int>> pascalsTriangle(int numRows) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        vector<vector<int>> v;
        int n = numRows;
        if(n == 0) return v;
        vector<int> temp(1,1);
        v.push_back(temp);
        for(int i = 2; i <= n; i++) {
            temp.clear();
            temp.resize(i);
            temp[0] = 1;
            temp[i-1] = 1;
            for(int j = 1; j < i-1; j++) {
                temp[j] = v[i-2][j-1] + v[i-2][j];
            }
            v.push_back(temp);
        }
        return v;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> result = PascalsTriangle().pascalsTriangle(n);
	for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}
