#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"

using namespace std;

class RemoveDuplicatesFromSortedArray {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,ans = 0;
        set<int> unique_element;
        
        for(i=0;i<nums.size();i++) {
         unique_element.insert(nums[i]);
        }
        ans=(int)unique_element.size();
        
        return ans;
    }
};

int main() {
	FastIO();
    int n;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n, nums);
    int result = RemoveDuplicatesFromSortedArray().removeDuplicates(nums);
    cout << result;
	return 0;
}
