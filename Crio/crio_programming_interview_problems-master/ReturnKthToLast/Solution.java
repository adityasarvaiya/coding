/*
public class ListNode {
   public int val; 
   public ListNode next;
   public ListNode(int x) { val = x; next = null; }
}
*/
import java.util.*;

import crio.ds.List.ListNode;

class Solution{
	public ListNode returnKthToLast(ListNode head,int k)
	{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int sizeOfList=0;
		ListNode node=head;
		while(node.next!=null)
		{
			sizeOfList++;
			node=node.next;
		}
		node=head;
		for(int i=1;i<=sizeOfList-k+1;i++)
		{
			node=node.next;
		}
		return node;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
}
