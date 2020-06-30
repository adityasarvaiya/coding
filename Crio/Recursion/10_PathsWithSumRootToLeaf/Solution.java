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
    long answer = 0;
    void countPaths(TreeNode root, long  sum, long  k) {
        if(root == null) {
            return ;
        }
        if(root.left == null && root.right == null) {
            if((sum + root.val) == k) {
                answer++;
            }
        }
        countPaths(root.left, sum + root.val , k);
        countPaths(root.right, sum + root.val , k );
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    long pathsWithSumRootToLeaf(TreeNode root, long k) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        countPaths(root,0,k);
        return answer;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}
