#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int> , null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
    ordered_set container;
    int sz;
public:
    Solution() {
        sz = 0;
    }

    void track(int x) {
        container.insert({x, sz++});
    }

    int getRankOfNumber(int x) {
        return container.order_of_key({x + 1 , -1});
    }
};
