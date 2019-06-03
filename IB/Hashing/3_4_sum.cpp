// https://www.interviewbit.com/problems/4-sum/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    
    int i,j,k,m, l = A.size();
    unordered_map <long long, int> h;
    long long sum;
    vector <vector<int>> ans;
    set<vector<int>> set1;
    
    for (i = 0; i < l; ++i) {
        h[A[i]] = i;
    }
    
    for (i = 0; i < l; ++i) {
        for (j = i+1; j < l; ++j) {
            for (k = j+1; k < l; ++k) {
                sum = A[i] + A[j] + A[k];
                
                if ((B-sum )< INT_MIN || (B-sum) > INT_MAX) {continue;}
                
                if (h.find(B-sum) != h.end() && h[B-sum] > k) {
                    vector <int> a = {A[i], A[j], A[k], B-sum};
                    sort(a.begin(), a.end());
                    
                    if (set1.find(a) == set1.end()) {
                        ans.push_back(a);
                        set1.insert(a);
                    }
                }
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}
