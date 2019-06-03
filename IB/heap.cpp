#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,i,l; 
    cin >> t;
     
    while (t--) {
        priority_queue <pair<int, char>> q;
        // priority_queue <pair<int, char>, vector <pair<int, char>>, greater<pair<int, char>>> p;

        cin >> n;
        string st;

        while (n--)
        {
            unordered_map <char, int> map;
            cin >> st;
            l = st.length();
            for (i = 0; i < l; i++) {
                if (map.find(st[i]) == map.end()) {
                    map[st[i]] = 1;
                } else {
                    map[st[i]] = map[st[i]] + 1;
                }
            }

            for (auto x : map) {
                q.push(make_pair(x.second, x.first));
                // p.push(make_pair(x.second, x.first));
            }
        }

        if (q.top().first > ((n/2)+1)) {
            return 0;
        } else {
            return 1;
        }

        // while (!q.empty()) {
        //     cout << q.top().first << " " << q.top().second << " " << endl;
        //     q.pop();
        // }

        // cout << endl;

        // while (!p.empty()) {
        //     cout << p.top().first << " " << p.top().second << endl;
        //     p.pop();
        // }

        cout << endl;

    }
     
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
 
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
     
//     int t,n,i,l; 

//     cin >> n;
//     string st;

//     while (n--)
//     {
//         priority_queue <pair<int, char>> q;
//         unordered_map <char, int> map;
//         cin >> st;
//         l = st.length();
//         for (i = 0; i < l; i++) {
//             if (map.find(st[i]) == map.end()) {
//                 map[st[i]] = 1;
//             } else {
//                 map[st[i]] = map[st[i]] + 1;
//             }
//         }

//         for (auto x : map) {
//             q.push(make_pair(x.second, x.first));
//         }

//         if (q.top().first > (((l-1)/2)+1)) {
//             cout << 0;
//         } else {
//             cout << 1;
//         }
    
//         cout << endl;


//     }


     
//     return 0;
// }
