import java.util.*;
import crio.ds.Tree.TreeNode;
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
class InorderSuccessor{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		Vector<TreeNode> nodes=TreeNode.readTreeReturnAllNodes(sc);
		int q=sc.nextInt();
		for(int i=0;i<q;i++)
		{	
			int index=sc.nextInt();
			Solution so=new Solution();
			System.out.println(so.inorderSuccessor(nodes.get(0),nodes.get(index)));
		}
	}
}