#include<bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class SegmentTree
{
    public:
        int start , end , value;
        SegmentTree *left, *right;
        SegmentTree(int start , int end , int value) {
            this->start = start;
            this->end = end;
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
        int query(int l , int r) {
            if(this->start > r || this->end <  l) {
                return 0;
            }
            if(this->start >= l && this->end <= r) {
                return this->value;
            }
            int leftAns = 0 , rightAns = 0;
            if(this->left != NULL) {
                leftAns = this->left->query(l,r);
            }
            if(this->right != NULL) {
                rightAns = this->right->query(l,r);
            }
            return leftAns + rightAns;
        }
        void update(int index , int val) {
            if(this->start == this->end) {
                this->value += val;
                return ;
            }
            int mid = (this->start + this->end)/2;
            if(this->start + 1 == this->end) {
                mid = start;
            }
            if(index <= mid) {
                if(this->left ==NULL) {
                    this->left = new SegmentTree(this->start,mid,0);
                }
                this->left->update(index,val);
            } else {
                 if(this->right ==NULL) {
                    this->right = new SegmentTree(mid+1,this->end,0);
                }
                this->right->update(index,val);
            }
            this->value = 0;
            if(this->left !=NULL) {
                this->value += this->left->value;
            }
            if(this->right !=NULL) {
                this->value += this->right->value;
            }
        }
};
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
class Solution {
    public :
        vector<int> countSmaller(vector<int> &nums) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            int MIN = -1e9;
            SegmentTree tree(MIN ,-MIN, 0);
            vector<int>result(nums.size(),0);
            for(int i = nums.size()-1 ; i>= 0 ; i--) {
                result[i] = tree.query(MIN,nums[i]-1);
                tree.update(nums[i],1);
            }
            return result;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        }
};
