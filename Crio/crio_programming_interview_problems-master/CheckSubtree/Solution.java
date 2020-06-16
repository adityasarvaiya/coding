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
    TreeMap<TreeNode , Integer> size = new TreeMap<TreeNode , Integer>(new MyNameComp());
    int largeSize , smallSize;
    boolean checkIfEqual(TreeNode rootLarge , TreeNode rootSmall) {
        if(rootLarge == null && rootSmall != null) {
            return false;
        }
        if(rootSmall == null && rootLarge != null) {
            return false;
        }
        if(rootLarge != null && rootSmall != null) {
            if(rootLarge.val != rootSmall.val) {
                return false;
            }
        }
        if(rootLarge == null && rootSmall == null) {
            return true;
        }
        boolean checkLeft = checkIfEqual(rootLarge.left, rootSmall.left);
        boolean checkRight = checkIfEqual(rootLarge.right, rootSmall.right);
        return (checkLeft && checkRight);
    }
    int findSize(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int subTreeSize = 1 + findSize(root.left) + findSize(root.right);
        size.put(root,Integer.valueOf(subTreeSize));
        return subTreeSize;
    }
    boolean traverseLargeAndCheckSubtree(TreeNode rootLarge , TreeNode rootSmall) {
        if(rootLarge == null) {
            return false;
        }
        if(rootLarge.val == rootSmall.val) {
            if(size.get(rootLarge) == smallSize) {
                return checkIfEqual(rootLarge, rootSmall);
            }
        }
        boolean checkLeft = traverseLargeAndCheckSubtree(rootLarge.left, rootSmall);
        boolean checkRight = traverseLargeAndCheckSubtree(rootLarge.right, rootSmall);
        return (checkLeft || checkRight);
    }
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    boolean checkSubtree(TreeNode rootLarge ,TreeNode rootSmall) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if(rootLarge == null && rootSmall == null) {
            return true;
        }
        if(rootLarge == null && rootSmall != null) {
            return false;
        }
        if(rootLarge != null && rootSmall == null) {
            return false;
        }
        largeSize = findSize(rootLarge);
        smallSize = findSize(rootSmall);
        return traverseLargeAndCheckSubtree(rootLarge, rootSmall);
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class MyNameComp implements Comparator<TreeNode> {

    public int compare(TreeNode o1, TreeNode o2) {
        String s1 = o1.toString();
        String s2 = o2.toString();
        return s1.compareTo(s2);
    }

}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS