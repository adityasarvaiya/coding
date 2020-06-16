#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"

/*
Definition for TreeNode
class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
}
*/

// CRIO_SOLUTION_START_MODULE_TREE_PATH_SUM
map<TreeNode *, map<int64_t, int64_t>> tbl;

void update_sums(TreeNode * root)
{ 
    if (!root)
       return;

    map<int64_t, int64_t> d;
    if (root->left) {
       update_sums(root->left);
       map<int64_t, int64_t> left = tbl[root->left];
       for (auto it = left.begin(); it != left.end(); ++it) {
           int64_t key = it->first + root->val;
           if (d.find(key) == d.end()) {
              d[key] = 0;
           }
           d[key] += it->second;
       }
    }
    if (root->right) {
       update_sums(root->right);
       map<int64_t, int64_t> right = tbl[root->right];
       for (auto it = right.begin(); it != right.end(); ++it) {
           int64_t key = it->first + root->val;
           if (d.find(key) == d.end()) {
              d[key] = 0;
           }
           d[key] += it->second;
       }
    }
    if (d.find(root->val) == d.end()) {
       d[root->val] = 0;
    }
    d[root->val] += 1;  
    tbl[root] = d;
#if 0
    printf("update sum = %d : ", root->val);
    for (auto it = d.begin(); it != d.end(); ++it) {
        printf("[key = %d val = %d] ", it->first, it->second); 
    }
    printf("\n");
#endif
}

void count_rec(TreeNode * root, int64_t k, uint64_t & total)
{
     if (!root) {
         return;
     }
#if 0
     printf("@node = %x root = %d\n", root, root->val);     
#endif
     map<int64_t, int64_t> left;
     map<int64_t, int64_t> right;

     if (root->left) {
	 left = tbl[root->left];
     }
     if (root->right) {
	 right = tbl[root->right];
     }
     if (root->val == k)
	 total += 1;

     for (auto it = right.begin(); it != right.end(); ++it) {
	 int64_t key = it->first;
	 if (root->val + key == k) {
	     total += it->second;
	 }
     } 
     for (auto it = left.begin(); it != left.end(); ++it) {
	 int64_t key = it->first;
	 if (root->val + key == k) {
	     total += it->second;
	 }
     }

     for (auto it = left.begin(); it != left.end(); ++it) {
	 int64_t diff = k - it->first - root->val;
	 if (right.find(diff) != right.end()) {
	     total += it->second * right[diff]; 
	 }
     } 

     if (root->left)
         count_rec(root->left, k, total);

     if (root->right)
         count_rec(root->right, k, total);
     
}
// CRIO_SOLUTION_END_MODULE_TREE_PATH_SUM

int64_t CountTreePathSumToK(TreeNode * root, int64_t k)
{
// CRIO_SOLUTION_START_MODULE_TREE_PATH_SUM
    tbl.clear();
    update_sums(root);
    uint64_t total = 0;
    count_rec(root, k, total);

    return total;
// CRIO_SOLUTION_END_MODULE_TREE_PATH_SUM
}
