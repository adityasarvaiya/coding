import java.util.*;

import crio.ds.Tree.TreeNode;

class Solution{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	HashMap<Long,Long> map=new HashMap<Long,Long>();
	long result=0;
	private void dfs(TreeNode node,long sum,long k)
	{
		if(node==null)
			return ;
		if(map.containsKey(node.val+sum-k))
		{
			if(map.get(node.val+sum-k)>(long)0)
			{
				result+=map.get(node.val+sum-k);
			}	
		}
		if(map.get(node.val+sum)==null)
		{
			map.put(node.val+sum,(long)1);
		}
		else
		{
			map.replace(node.val+sum,map.get(node.val+sum)+1);
		}
		dfs(node.left,node.val+sum,k);
		dfs(node.right,node.val+sum,k);
		map.replace(node.val+sum,map.get(node.val+sum)-1);
	}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	public long pathWithSum(TreeNode root,int k)
	{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		map.put((long)0,(long)1);
		dfs(root,(long)0,(long)k);
		return result;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
}
