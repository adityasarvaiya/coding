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
    public TreeNode makeBstFromArray(int low , int high , int treeArray[]) {
        if(low > high) {
            return null;
        }
        int mid = (low + high)/2;
        TreeNode midNode = new TreeNode(treeArray[mid]);
        midNode.left = makeBstFromArray(low, mid-1, treeArray);
        midNode.right = makeBstFromArray(mid+1, high, treeArray);
        return midNode;
    }
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    public TreeNode findMinimalTree(int treeArray[]) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        return makeBstFromArray(0, treeArray.length-1 , treeArray);
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}