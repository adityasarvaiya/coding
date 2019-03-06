// https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/
// unsubmitted

#include <bits/stdc++.h>
using namespace std;

void find_pairs(vector <int> nums, int target)
{   
    int i=0, j, n = nums.size(), a,b,c,d,curr;
    vector <pair<int, pair<int, int>>>  hash;
    vector <pair<int, pair<int, int>>>  :: iterator it;
    vector <int> :: iterator it1;

    for (it1 = nums.begin(); it1 != nums.end(); ++it1) {
        cout << i++ << " " << *it1 << endl;
    }

    cout << endl << endl;

    // unordered_map <int, pair<int, int>> h;
    // unordered_map <int, pair<int, int>> :: iterator it;

    for (i = 0; i < n-1; ++i) {
        for (j = i+1; j < n; ++j) {
            hash.push_back(make_pair(nums[i] + nums[j], make_pair(i,j)));
            // h[nums[i] + nums[j]] = make_pair(i,j);
        }
    }

    sort(hash.begin(), hash.end());

    for (it = hash.begin(); it != hash.end(); ++it) {
        cout << (*it).second.first << " " <<(*it).second.second << " " << (*it).first <<  endl;     
    }

    cout << endl << endl;

    n = hash.size();
    i = 0;
    j = n - 1;

    while (i < j) {
        curr = hash[i].first + hash[j].first;

        if (curr == target) {
            a = hash[i].second.first;
            b = hash[i].second.second;
            c = hash[j].second.first;
            d = hash[j].second.second;
            
            if ((a != c && a != d) && (b != c && b != d)) {
                cout << nums[a] << " " <<  nums[b] << " " <<  nums[c] << " " <<  nums[d] << endl;
            }
            i++;
        } else if (curr > target) {
            --j;
        } else {
            ++i;
        }
    }



    // for (it = h.begin(); it != h.end(); ++it) {
    //     cout << (*it).second.first << " " <<(*it).second.second << " " << (*it).first <<  endl;

    //     // if (h.find(target - (*it).first) != h.end()) {
    //     //     a = h[(*it).first].first;
    //     //     b = h[(*it).first].second;
    //     //     c = h[target - (*it).first].first;
    //     //     d = h[target - (*it).first].second;

    //     //     if (((a != c) && a != d) && (b != c && b != d)) {
    //     //         cout << a << " " << b << " " << c << " " << d << endl;
    //     //     }
    //     // }
    // }

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,curr,n,target;
    cin >> t;

    while (t--) {
        int i;
        cin >> n;
        vector <int> nums;

        for (i=0; i<n; ++i) {
            cin >> curr;
            nums.push_back(curr);
        }

        cin >> target;

        find_pairs(nums, target);
    }
    return 0;
}