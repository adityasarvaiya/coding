#include<bits/stdc++.h>
#define MAX 10000

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int n, N, i2, i3, i5;
    i2 = i3 = i5 = 0;

    long int dp[MAX];
    dp[0] = 1;
    long int dp_index = 1;

    cin >> n;
    while (n--) {
        cin >> N;
        
        if (N >= dp_index) {
            for (long int i = dp_index; i < N; i++) {
                long int next_mul_2 = dp[i2]*2;
                long int next_mul_3 = dp[i3]*3;
                long int next_mul_5 = dp[i5]*5;

                long int next_num = min({next_mul_2, next_mul_3, next_mul_5});
                // cout << "Next min " << next_num << endl;

                if (next_num == next_mul_2) {
                    i2++;
                }

                if (next_num == next_mul_3) {
                    i3++;
                }

                if (next_num == next_mul_5) {
                    i5++;
                }

                if (dp[dp_index-1] != next_num) {
                    dp[dp_index] = next_num;
                    dp_index++;
                }
            }
        }

        cout << dp[N-1] << endl;

        // for (long int i = 0; i < N; i++) {
        //     cout << i << " " << dp[i] << endl;
        // }
    }

    return 0;
}
