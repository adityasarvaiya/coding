import crio.ds.Tree.TreeNode;
import java.util.*;

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
    public static void dfs(TreeNode vertex, List<Long> inOrder) {
        if (vertex == null)
            return;
        dfs(vertex.left, inOrder);
        inOrder.add(vertex.val);
        dfs(vertex.right, inOrder);
    }

    public static List<Long> inorderTraversal(TreeNode root) {
        List<Long> inOrder = new ArrayList<Long>();
        dfs(root, inOrder);
        return inOrder;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    public int kthSmallestElementInABst(TreeNode root, int k) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        List<Long> inOrder = inorderTraversal(root);
        return Math.toIntExact(inOrder.get(k - 1));
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}
