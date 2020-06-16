/*
// Definition for TreeNode
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
*/
class InputSequencesForBst {
public:
    vector<vector<int> > inputSequencesForBst(TreeNode *root)
    {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (root == NULL) {
            vector<int> seq;
            vector<vector<int> > v;
            v.push_back(seq);
            return v;
        }


        if (root -> left == NULL && root -> right == NULL) {
            vector<int> seq;
            seq.push_back(root -> val);
            vector<vector<int> > v;
            v.push_back(seq);
            return v;
        }

        vector<vector<int> > results, left, right;
        left  = inputSequencesForBst(root -> left);
        right = inputSequencesForBst(root -> right);
        int size = left[0].size() + right[0].size() + 1;

        vector<bool> flags(left[0].size(), 0);

        for (int k = 0; k < right[0].size(); k++)
            flags.push_back(1);

        for (int i = 0; i < left.size(); i++) {
            for (int j = 0; j < right.size(); j++) {
                do {
                    vector<int> tmp(size);
                    tmp[0] = root -> val;
                    int l = 0, r = 0;
                    for (int k = 0; k < flags.size(); k++) {
                        tmp[k + 1] = (flags[k]) ? right[j][r++] : left[i][l++];
                    }
                    results.push_back(tmp);
                } while (next_permutation(flags.begin(), flags.end()));
            }
        }

        return results;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};