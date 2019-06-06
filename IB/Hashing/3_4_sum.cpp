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


vector<vector<int>> total;
int n = nums.size();
if(n<4)  return total;
sort(nums.begin(),nums.end());
for(int i=0;i<n-3;i++)
{
    if(i>0&&nums[i]==nums[i-1]) continue;
    if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
    if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
    
    for(int j=i+1;j<n-2;j++)
    {
        if(j>i+1&&nums[j]==nums[j-1]) continue;
        if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
        if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
        int left=j+1,right=n-1;
        while(left<right){
            int sum=nums[left]+nums[right]+nums[i]+nums[j];
            if(sum<target) left++;
            else if(sum>target) right--;
            else{
                total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                do{left++;}while(nums[left]==nums[left-1]&&left<right);
                do{right--;}while(nums[right]==nums[right+1]&&left<right);
            }
        }
    }
}
return total;