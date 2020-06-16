

#include <bits/stdc++.h>
using namespace std;
// CRIO_SOLUTION_AND_STUB_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_AND_STUB_END_MODULE_L1_PROBLEMS

class TreeNode {

public:
    long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode* parent;

    TreeNode() {}

    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
        parent = NULL;
    }
    TreeNode *makeTreeFromParentArray(vector<int> parent)
    {
        int n = parent.size();
        unordered_map<int, TreeNode*> map;
        for (int i = 0; i < n; i++)
            map[i] = new TreeNode(i);
        TreeNode *root = NULL;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == -1)
                root = map[i];
            else
            {
                TreeNode *ptr = map[parent[i]];
                map[i]->parent = ptr;
                if (ptr->left)
                    ptr->right = map[i];
                else
                    ptr->left = map[i];
            }
        }
        return root;
    }
    vector<TreeNode*> getTreeFromEdges(int n,vector<int>& value, vector<vector<int> >& edges)
    {
        vector<TreeNode* > nodes;
        for(int i=0;i<n;i++)
        {
            TreeNode* temp = new TreeNode(value[i+1]);
            nodes.push_back(temp);
        }
        for(auto edge: edges)
        {
            int parent = edge[0];
            int leftchild = edge[1];
            int rightchild = edge[2];
            if(leftchild != -1)
                nodes[parent - 1]->left = nodes[leftchild - 1];
            if(rightchild != -1)
                nodes[parent - 1]->right = nodes[rightchild - 1]; 
        }
        return nodes;
    }
    vector<TreeNode*> readTree()
    {
        // IO 
        int n,a,b,x;
        cin >> n;
        if(n==0)
        {
            vector<TreeNode*> answer;
            return answer;
        }
        vector<int > value(n+1,0);
        for (int i = 1; i <= n; i++) 
            cin>>value[i];
        vector<vector<int> > edges;
        for(int i=0;i<n;i++)
        {
            cin>>x>>a>>b;
            edges.push_back({x,a,b});
        }
        return getTreeFromEdges(n,value,edges);
    }
    vector<TreeNode*> readTreeReturnAllNodes()
    {
        vector<TreeNode*> nodes = readTree();
        return nodes;
    }

    TreeNode* readTreeReturnRoot()
    {
        vector<TreeNode*> nodes = readTree();
        TreeNode* root = nodes[0];
        return root;
    }
    bool validNode(TreeNode* node,int lower,int upper)
    {
        if(node == NULL)
            return true;
        int val = node->val;
        if(val <= lower or val >= upper)
            return false;
        if(!validNode(node->right,val,upper))
            return false;
        if(!validNode(node->left,lower,val))
            return false;
        return true;
    }
    bool isValidateBST(TreeNode* root)
    {
        return validNode(root,-1e9,1e9);
    }
    TreeNode* makeTreeFromArray(int idx, vector<string> tree, TreeNode* root) {
        if (idx >= int(tree.size()))
            return NULL;

        if (tree[idx] == "null")
            return NULL;

        long x = stoi(tree[idx]);
        root = new TreeNode(x);
        root->left = makeTreeFromArray(2 * idx + 1 , tree, root->left);
        root->right = makeTreeFromArray(2 * idx + 2, tree, root->right);
        return root;
    }

    vector<vector<string>> makeLevelOrderFromTree(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<string>> answer;
        if (root == NULL) {
            return answer;
        }
        q.push(root);
        while (!q.empty()) {
            vector<string> atThisLevel;
            int size = q.size();
            while (size > 0) {
                size--;
                TreeNode* temp = q.front();
                q.pop();
                if (temp == NULL) {
                    atThisLevel.push_back("null");
                    continue;
                } else {
                    q.push(temp->left);
                    q.push(temp->right);
                    atThisLevel.push_back(to_string(temp->val));
                }
            }
            answer.push_back(atThisLevel);
        }
        return answer;
    }

    void makePreOrderFromTree(TreeNode* root, vector<int>& preOrder) {
        if (root == NULL) {
            return ;
        }
        preOrder.push_back(root->val);
        makePreOrderFromTree(root->left, preOrder);
        makePreOrderFromTree(root->right, preOrder);
    }

    void makeInOrderFromTree(TreeNode* root, vector<int>& inOrder) {
        if (root == NULL) {
            return ;
        }
        makeInOrderFromTree(root->left, inOrder);
        inOrder.push_back(root->val);
        makeInOrderFromTree(root->right, inOrder);
    }

    vector<string> makeNextPointersFromTree(TreeNode* root, vector<string>& nextArray) {
        queue<TreeNode*> q;
        if (root == NULL)
            return nextArray;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0 ; i < size ; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
                if (temp->next == NULL) {
                    nextArray.push_back("null");
                }
                else {
                    nextArray.push_back(to_string(temp->next->val));
                }
            }
        }
        return nextArray;
    }

    string treeNodeToString(TreeNode* root) {
        vector<vector<string>> arr = makeLevelOrderFromTree(root);
        string str = "";
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < int(arr[i].size()); j++) {
                str += arr[i][j];
                str += " ";
            }
        }
        return str;
    }
};
