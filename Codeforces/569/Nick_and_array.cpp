#include <bits/stdc++.h>
using namespace std;
 
void util(vector <int> A, int n) {
    int numofneg = 0;
    int maxposindex = -1, maxpos = INT_MIN; 

    vector <int> B(n);

    for(int i = 0; i < n; ++i) {
        B[i] = abs(-1*A[i] - 1) > abs(A[i]) ? -1*A[i] - 1 : A[i];

        if (B[i] < 0) {
            numofneg++;
            if (-1*A[i] - 1 >= 0 && maxpos < -1*A[i] - 1) {
                maxpos = -1*A[i] - 1;
                maxposindex = i;
            } else if (A[i] >= 0) {
                maxpos = A[i];
                maxposindex = i;
            }

        }
    }

    if (numofneg % 2 == 1) {
        B[maxposindex] = maxpos;
    }

    for (int i = 0; i < n; ++i) {
        cout << B[i] << " ";
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int n; 
    cin >> n;
    
    vector <int> A(n);

    for (int i = 0; i < n; ++i) { 
        cin >> A[i];
    }

    util(A, n);
    
    return 0;
}