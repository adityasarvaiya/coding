#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,cap, index; 
    cin >> t;
     
    while (t--) {
        cin >> n;
        int A[n];
    
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        cin >> cap;
        
        unordered_set <int> s;
        unordered_map <int, int> h;
        int pagefaults = 0;

        for (int i = 0; i < n; ++i) {
            
            if (s.size() < cap) {
                
                if (s.find(A[i]) == s.end()) {
                    pagefaults++;
                    s.insert(A[i]);
                }

            } else {

                if (s.find(A[i]) == s.end()) {
                    
                    int lru = INT_MAX, val;
                    for (auto it = s.begin(); it != s.end(); it++) {
                        if (h[*it] < lru) { 
                            lru = h[*it];
                            val = *it;
                        }
                    }

                    s.erase(val);
                    s.insert(A[i]);
                    pagefaults++;
                }

            }

            h[A[i]] = i;
        
        }

        cout << pagefaults << endl;

    }
     
    return 0;
}