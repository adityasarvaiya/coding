import java.util.*;
import crio.ds.Tree.TreeNode;
/*
// Definition for TreeNode
public class TreeNode {
    public long val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode next;
    public TreeNode (long x) {
        val = x;
        left = null;
        right = null;
        next = null;
    }
}
*/
public class Solution {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int findHeightAndCheckBalanced(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int heightLeft = findHeightAndCheckBalanced(root.left);
        int heightRight = findHeightAndCheckBalanced(root.right);
        if(Math.abs(heightLeft-heightRight) > 1) {
            return 1000000000;
        }
        return 1 + Math.max(heightLeft, heightRight);
    }
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    boolean checkBalanced(TreeNode root) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int treeHeight = findHeightAndCheckBalanced(root);
        if(treeHeight >= 1000000000) {
            return false;
        }
        return true;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}