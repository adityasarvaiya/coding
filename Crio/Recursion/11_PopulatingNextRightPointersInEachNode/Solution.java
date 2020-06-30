import java.util.*;
import crio.ds.Tree.TreeNode;

/*
// Definition of TreeNode
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
    public TreeNode populatingNextRightPointersInEachNode(TreeNode root) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        Queue<TreeNode> q = new  LinkedList<TreeNode>();
        if (root == null)
            return null;
        q.add(root);
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0 ; i < size ; i++) {
                TreeNode temp = q.peek();
                q.remove();
                if (temp.left != null) {
                    q.add(temp.left);
                }
                if (temp.right != null) {
                    q.add(temp.right);
                }
                if (i == size - 1) {
                    temp.next = null;
                } else {
                    temp.next = q.peek();
                }
            }
        }
        return root;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}
