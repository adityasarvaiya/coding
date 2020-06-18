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

	public ListNode rotateList(ListNode head,int k)
	{
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int sizeOfList=findSizeOfList(head);
		if(sizeOfList<=0)
			return head;
		int rotation=k%sizeOfList;
		if(rotation==0)
			return head;
		int i=0;
		ListNode node=head,prev=null,ans=null;
		while(sizeOfList-i!=rotation)
		{
			prev=node;
			node=node.next;
			i++;
		}
		if(prev!=null)
			prev.next=null;
		ans=node;
		while(true)
		{
			if(node.next!=null)
				node=node.next;
			else
			{
				node.next=head;
				break;
			}
		}
		return ans;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
}