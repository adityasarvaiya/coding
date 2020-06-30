// Definition of TreeNode
class TreeNode {
    public long val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode (long x) {
        val = x;
        left = null;
        right = null;
    }
}

public class Solution {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int indexPre = 0;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    public TreeNode constructBinaryTreeFromPreorderAndInorderTraversal(int[] preorder, int[] inorder) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS  
        int  n = preorder.length;
        TreeNode answer = build(preorder , inorder , 0 , n-1);
        return answer;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS  
    public TreeNode build(int[] preorder , int[] inorder , int low , int high) {
        if(high < low) {
            return null;
        }
        int rootVal = preorder[indexPre];
        indexPre++;
        TreeNode temp = new TreeNode(rootVal);
        int indexIn = -1;
        for(int i = low ; i <= high ; i++) {
            if(rootVal == inorder[i]) {
                indexIn = i;
                break;
            }    
        }
        temp.left = build(preorder , inorder , low , indexIn - 1);
        temp.right = build(preorder , inorder , indexIn + 1 , high);
        return temp;    
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
