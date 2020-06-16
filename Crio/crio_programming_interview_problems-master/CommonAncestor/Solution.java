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
    TreeNode commonAncestor(TreeNode root, TreeNode p , TreeNode q) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS	    
        if ( root == null) {
            return null;
        }
        if (root.val == p.val ||  root.val == q.val) {
            return root;
        }
        TreeNode l = commonAncestor(root.left, p, q);
        TreeNode r = commonAncestor(root.right , p, q);
        if (l != null && r != null) {
            return root;
        }
        if ( l != null) {
            return l;
        }
        if(r != null) {
            return r;
        }
        return null;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS	    
    }
}
