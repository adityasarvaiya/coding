#include <bits/stdc++.h>
using namespace std;

void findCombinations(vector <vector<int>> &ans, vector <int> combinations, vector<int> candidates, int target, int starting_i) 
    {
        
        if (target == 0) {
            ans.push_back(combinations);
            return;
        }
        
        for (int i = starting_i; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                break;
            }
            
            combinations.push_back(candidates[i]);
            findCombinations(ans, combinations, candidates, target-candidates[i], i+1);
            combinations.erase(combinations.begin() + combinations.size());      
        }    
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,i,j,tmp,B; 
    cin >> t;
     
    while (t--) {
        cin >> n;
        vector <int> A;

        for (i = 0; i < n; ++i) {
            cin >> tmp;
            A.push_back(tmp);
        }

        cin >> B;

        if (A.size() == 0 || B == 0) {return 0;}
        
        sort(A.begin(), A.end());
        
        vector <vector<int>> ans;
        vector <int> combinations;
        findCombinations(ans, combinations, A, B, 0);
        
        for (i = 0; i < ans.size(); ++i) {
            cout << "(";
            for (j = 0; j < ans[i].size(); ++j) {
                if (j == 0) {cout << ans[i][j];}
                else {cout << " " << ans[i][j];}
            }
            cout << ")";
        }

        cout << endl;

    } 
     
    return 0;
}