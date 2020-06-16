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
class Solution {
	// CRIO_SOLUTION_START_MODULE_TREE_PATH_SUM
	public static Long total = (long)0;
	public static HashMap<TreeNode , HashMap<Long, Long> > M = new HashMap<TreeNode, HashMap<Long, Long> > ();
	public static void update_sums( TreeNode root) {
		if (root == null) return;
		HashMap<Long, Long > d = new HashMap<Long , Long> ();
		if (root.left != null) {
			update_sums(root.left);
			HashMap<Long, Long> left = M.get(root.left);
			for ( Long it : left.keySet()) {
				Long key = it + root.val;
				Long k = d.getOrDefault(key, (long)0);
				d.put(key, k + left.get(it));
			}
		}

		if (root.right != null) {
			update_sums(root.right);
			HashMap<Long, Long> right = M.get(root.right);
			for ( Long it : right.keySet()) {
				Long key = it + root.val;
				Long k = d.getOrDefault(key, (long)0);
				d.put(key, k + right.get(it));
			}
		}
		Long x = d.getOrDefault(root.val, (long)0);
		d.put(root.val, x + 1);
		M.put(root, d);

	}

	public static void count_rec(TreeNode root , int k) {
		if (root == null) return ;

		HashMap<Long, Long> right = new HashMap<Long , Long> ();
		HashMap<Long, Long> left = new HashMap<Long , Long> ();
		if (root.left != null) {
			left = M.get(root.left);
		}
		if (root.right != null) {
			right = M.get(root.right);
		}
		if ( root.val == k) {
			total += 1;
		}
		for (Long it : right.keySet()) {
			Long key = it + root.val;
			if (key == k) {
				total += right.getOrDefault(it, (long) 0);
			}
		}
		for (Long it : left.keySet()) {
			Long key = it + root.val;
			if (key == k) {
				total += left.getOrDefault(it, (long) 0);
			}
		}

		for ( Long it : left.keySet()) {
			Long diff = k - it - root.val;
			if (right.containsKey(diff)) {
				total += left.get(it) * right.get(diff);
			}
		}
		if (root.left != null)
			count_rec(root.left, k);
		if (root.right != null)
			count_rec(root.right, k);

	}
	// CRIO_SOLUTION_END_MODULE_TREE_PATH_SUM

	public static Long CountTreePathSumToK(TreeNode root, int k) {
		// CRIO_SOLUTION_START_MODULE_TREE_PATH_SUM
		update_sums(root);
		count_rec(root, k);
		return total;
		// CRIO_SOLUTION_END_MODULE_TREE_PATH_SUM
	}
}