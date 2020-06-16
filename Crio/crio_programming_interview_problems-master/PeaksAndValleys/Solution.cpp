class Solution {
public:
    vector<int> peaksAndValleys(vector<int> &arr) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        sort(arr.begin() , arr.end());
        for(int i = 0 ; i < arr.size()-1; i += 2) {
            swap(arr[i] , arr[i+1]);
        }
        return arr;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};
