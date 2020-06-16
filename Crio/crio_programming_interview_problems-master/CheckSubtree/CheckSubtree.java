import java.util.*;
import crio.ds.Tree.TreeNode;
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
public class CheckSubtree {
	public TreeNode makeTreeFromParentArray(int parent[] , int value[] , int n) {
		TreeMap<Integer, TreeNode> nodeByIndex  = new TreeMap<Integer, TreeNode>();
		TreeNode root = null;
		for (int i = 0; i < n; i++) {
			nodeByIndex.put(i, new TreeNode(value[i]));
		}
		for (int i = 0 ; i < n ; i++) {
			if (parent[i] == -1)
				root = nodeByIndex.get(i);
			else {
				TreeNode ptr = nodeByIndex.get(parent[i]);
				if (ptr.left != null) {
					ptr.right = nodeByIndex.get(i);
				} else {
					ptr.left = nodeByIndex.get(i);
				}
			}
		}
		return root;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int p = 0 ; p < t ; p++) {
			TreeNode rootLarge = TreeNode.readTreeReturnRoot(sc);
			TreeNode rootSmall = TreeNode.readTreeReturnRoot(sc);
			boolean answer = new Solution().checkSubtree(rootLarge, rootSmall);
			if (answer) {
				System.out.println("Yes");
			} else {
				System.out.println("No");
			}
		}
	}
}
