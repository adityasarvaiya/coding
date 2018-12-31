#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=0;

    while (true) {
        cin >> n;
        if (n < 1) {
            break;
        } else {
            int ar[n];
            int mean, max_cut, i, sum;
            sum = 0;
            mean = 0;
            max_cut = 0;
            
            for (i = 0; i < n; ++i) {
                cin >> (ar[i]);
                sum += (ar[i]);
            }
        
            mean = sum / n;

            // cout << sum << " " << mean << " " << max_cut << endl; 

            for (i = 0; i < n; ++i) {

                if (mean > ar[i]) {
                    max_cut += mean - ar[i];
                }
                // cout << max_cut << " " << ar[i] << endl;
            }


            if (sum % n != 0) {
                cout << -1 << endl;
            } else {
                cout << max_cut << endl;
            }
        }
    }

    return 0;
}
