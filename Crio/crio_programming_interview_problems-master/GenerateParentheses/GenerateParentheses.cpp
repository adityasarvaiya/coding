#include <bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
void paren(vector<string> &ans,int left,int right,string curr){
    if(left>right){
        return;
    }
    if(left==0&&right==0){
        ans.push_back(curr);
        return;
    }

    if(left>0){
        string new_curr = curr;
        new_curr.push_back('(');
        paren(ans,left-1,right,new_curr);
    }
    if(right>0){
        string new_curr = curr;
        new_curr.push_back(')');
        paren(ans,left,right-1,new_curr);
    }
}
// CRIO_SOLUTION_END_MODULE_L2_PROBLEMS


vector<string> generateParentheses(int n){    
    // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
    vector<string> ans;
    paren(ans,n,n,"");
    return ans;
    // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

}

int main(){
    int n;cin>>n;

    vector<string> ans = generateParentheses(n);
    for(auto parentheses: ans ){
        cout<<parentheses<<endl;
    }
}