import java.util.*;
import crio.ds.Tree.TreeNode;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class PathsWithSum{
	public static void main(String [] args)
	{
		Scanner sc= new Scanner(System.in);
        TreeNode root = TreeNode.readTreeReturnRoot(sc);
        int k = sc.nextInt();
		Solution so=new Solution();
		System.out.println(so.pathWithSum(root,k));
	}
}
