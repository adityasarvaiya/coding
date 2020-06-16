import java.util.*;
import crio.ds.Tree.TreeNode;

/*
// Definition of TreeNode
public class TreeNode {
    public long val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode (long x) {
        val = x;
        left = null;
        right = null;
    }
}
*/


public class Solution {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS	
    public boolean isValidBST(TreeNode root , long low ,long high) {
        if(root == null) {
            return true;
        }
        if(root.val > high || root.val < low) {
            return false;
        }
        boolean leftValid = isValidBST(root.left, low, root.val);
        boolean rightValid = isValidBST(root.right, root.val, high);

        return (leftValid && rightValid);
    }
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS	
    boolean validateBinarySearchTree(TreeNode root) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS	
        long min = -1000000000000l;
        long max = 1000000000000l;
        boolean answer = isValidBST(root, min, max);
        return answer;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS	
    }
}
