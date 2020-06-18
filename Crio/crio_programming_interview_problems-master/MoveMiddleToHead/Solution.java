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
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	public int findSizeOfList(ListNode head)
	{
		int size=0;
		while(head!=null)
		{
			head=head.next;
			size++;
		}
		return size;
	}
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	
	public ListNode moveMiddleToHead(ListNode head)
	{
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int sizeOfList=findSizeOfList(head);
		int middleNode=(int)Math.floor(sizeOfList/2)+(int)1;
		if(sizeOfList ==0 || sizeOfList ==1)
			return head;
		int i=1,val;
		ListNode prev=head,node=head;
		while(true)
		{
			if(i==middleNode)
			{
				prev.next=node.next;
				val=node.val;
				break;
			}
			else
			{
				prev=node;
				node=node.next;
				i++;
			}
		}
		ListNode start=new ListNode(val);
		start.next=head;
		return start;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
}