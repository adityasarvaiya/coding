#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        /* 
        n = num of elements in array
        sum = required sum from subarray
        start end = pointers to starting and ending of subarray
        */
       
        int n,sum,start, end=0, curr_sum;
        cin >> n >> sum;
        int ar[n];

        //take all input
        for (int i = 0; i < n; i++ ) {
            cin >> ar[i];
        }

        start = 0;  
        curr_sum = 0;

        //actual processing
        for (end = 0; end < n; end++) {
            curr_sum = curr_sum + ar[end];

            while(curr_sum > sum && start < end){
                curr_sum = curr_sum - ar[start];
                start++;
            }
        
            if (curr_sum == sum) {
                break;
            }
        }

        if (curr_sum != sum) {
            cout << "-1" << endl;
        } else {
            cout << start+1 << " " << end+1  << endl;
        }
    }

    return 0;
}