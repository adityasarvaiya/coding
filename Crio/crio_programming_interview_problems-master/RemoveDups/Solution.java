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
	public static void removeDuplicates(ListNode head)
	{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		Map<Integer,Integer> map=new HashMap<Integer,Integer>();
		ListNode node,prev=head;
		if(head!=null)
		{	
			node=head.next;
			map.put(head.val,(Integer)1);
			prev.next=null;
			while(node!=null)
			{
				if(map.get(node.val)==null)
				{
					map.put(node.val,(Integer)1);
					prev.next=node;
					prev=prev.next;
					node=node.next;
					prev.next=null;
				}
				else
					node=node.next;
			}
		}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
}
