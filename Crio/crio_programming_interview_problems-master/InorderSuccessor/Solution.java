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
class Solution{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	private TreeNode rightJustGreater(TreeNode node) 
	{ 
	    TreeNode current = node; 
	    while (current.left != null) 
	        current = current.left;  
	    return current;
	}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	public int inorderSuccessor(TreeNode root,TreeNode givenNode)
	{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		Vector<TreeNode> parent=new Vector<TreeNode>();
		TreeNode node=root;
		while(node!=givenNode)
		{
			parent.add(node);
			if(givenNode.val>node.val)
				node=node.right;
			else
				node=node.left;
		}
		if( givenNode.right != null ) 
	        return (int)rightJustGreater(givenNode.right).val; 
	    int size=parent.size();
	    int j=size-1;
	    TreeNode par =null;
	    if(j>=0)
	    	par = parent.get(j); 
	    while(j>=0 && givenNode == par.right) 
	    { 
	    	j--;
	    	if(j>=0)
	        {
	       		givenNode = par; 
	        	par = parent.get(j);
	        }
	    } 
	    if(j==-1)
	    	return -1;
	    else
	    	return (int)par.val;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
}