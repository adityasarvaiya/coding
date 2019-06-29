#include<bits/stdc++.h>

using namespace std;

string add(string s1, string s2) {
    string s3 = "";

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int len1 = s1.length();
    int len2 = s2.length();
    int i, minLen;

    if (len1 < len2) {
        minLen = len1;
    } else {
        minLen = len2;
    }

    int carry = 0;
    for (i = 0; i < minLen; i++) {
        int temp = (s1[i] - '0') + (s2[i] - '0') + carry; 
        s3.push_back((temp%10) + '0');
        carry = temp / 10;
    }

    if (len1 < len2) {
        for (i = minLen; i < len2; i++) {
            int temp = s2[i] - '0' + carry;
            s3.push_back((temp%10) + '0');
            carry = temp/10;
        }
    } else {
        for (i = minLen; i < len1; i++) {
            int temp = s1[i] - '0' + carry;
            s3.push_back((temp%10) + '0');
            carry = temp/10;
            
        }
    }

    if (carry > 0) {
        s3.push_back(carry + '0');
    }

    reverse(s3.begin(), s3.end());

    return s3;
}

int main(int argc, char const *argv[])
{

    int n;
    cin >> n;

    string dp[101];
    dp[0] = 1;
    int dp_index = 1;

    while (n--) {
        int N, i, j;
        cin >> N;

        if (N >= dp_index) {
            for (i = dp_index; i <= N; i++) {
                string sum;
                for (j = 0; j < i; j++) {
                    sum += dp[j] * dp[(i-1) - j];
                }

                dp[i] = sum;
            }
        }

        cout << dp[N] << endl;

        // for (i = 0; i < N; i++) {
        //     cout << dp[i] << " " ;
        // }
    }    

    return 0;
}
