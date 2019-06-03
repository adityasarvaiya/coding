#include <bits/stdc++.h>
using namespace std;
 
void find_combinations(int n, vector<int> A, int sum, 
int curr_i, int B, vector<int> curr_ele, int *h) 
{
    if (sum+A[curr_i] > B || curr_i >= n) {
        return;
    }

    if (sum+A[curr_i] == B) {
        curr_ele.push_back(curr_i);
        int f=0;
        for (int i = 0; i < curr_ele.size(); ++i) {
            if (h[curr_ele[i]] == 0) {
                f = 1; 
            } 
                
            h[curr_ele[i]] = 1;
        } 

        // if (!f) {return ;}

        cout << "(" ;
        for (int i = 0; i < curr_ele.size(); ++i) {
            if (i==0) {cout << A[curr_ele[i]];}
            else {cout << " " <<  A[curr_ele[i]];} 
        }
        cout << ")";
        // return;
    }

    sum = sum+A[curr_i];
    curr_ele.push_back(curr_i);

    for (int i = curr_i+1; i < n; ++i) {
        find_combinations(n, A, sum, i, B, curr_ele, h);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,i,tmp,B; 
    cin >> t;
     
    while (t--) {
        cin >> n;
        vector <int> A;

        for (i = 0; i < n; ++i) {
            cin >> tmp;
            A.push_back(tmp);
        }

        cin >> B;

        sort(A.begin(), A.end());
        vector<int> cur;

        // for (i = 0; i < n; ++i) {
        //     int h[n] = {0};
        //     find_combinations(n, A, 0, i, B, cur,h);
        // }

        int h[n] = {0};
        find_combinations(n, A, 0, 0, B, cur,h);

        cout << endl;

    } 
     
    return 0;
}