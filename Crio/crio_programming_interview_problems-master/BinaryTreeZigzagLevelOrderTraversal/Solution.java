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

    public List<List<Long>>  zigzagLevelOrder(TreeNode root) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        List<List<Long>> answer = new ArrayList<List<Long>>();
        Queue<TreeNode> q = new  LinkedList<TreeNode>();
        if (root == null)
            return answer;
        q.add(root);
        int level = 0;
        while (!q.isEmpty()) {
            List<Long> atThisLevel = new ArrayList<Long>();
            int size = q.size();
            while (size > 0) {
                size--;
                TreeNode temp = q.peek();
                q.remove();
                if (temp.left != null) {
                    q.add(temp.left);
                }
                if (temp.right != null) {
                    q.add(temp.right);
                }
                atThisLevel.add(temp.val);
            }
            level++;
            if (level % 2 == 0) {
                Collections.reverse(atThisLevel);
            }
            answer.add(atThisLevel);
        }
        return answer;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    }
}