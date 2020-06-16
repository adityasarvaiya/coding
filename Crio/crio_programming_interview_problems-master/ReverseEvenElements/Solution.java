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
	ListNode ansListHead=null;

	private void reverseList(ListNode start,ListNode end,ListNode prev)
	{
		if(start!=null && end!=null)
		{
			ListNode node=start,temp1=end.next,temp2=null,constantEnd=end.next;
			while(node!=constantEnd)
			{
				temp2=node.next;
				node.next=temp1;
				temp1=node;
				node=temp2;
			}
			if(prev==null)
				ansListHead=end;
			else
				prev.next=end;
		}
	}
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

	public ListNode reverseEvenElements(ListNode head)
	{
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		Vector<Integer> l=new Vector<Integer>();
		Vector<Integer> r=new Vector<Integer>();
		int prevEvenCount=0;
		ListNode startHead=null,endHead=null,node=head,prev=null;
		while(node!=null)
		{
			if(node.val%2==0 && prevEvenCount==0)
			{
				prevEvenCount++;
				startHead=node;
				endHead=node;
			}
			else if(node.val%2==0 && prevEvenCount>0)
			{
				prevEvenCount++;
				endHead=node;
			}
			else
			{
				reverseList(startHead,endHead,prev);
				prevEvenCount=0;
				startHead=null;
				endHead=null;
				prev=node;
			}
			if(node.val%2==0 && node.next==null)
			{
				reverseList(startHead,endHead,prev);
				break;
			}
			node=node.next;
		}
		if(ansListHead==null)
			ansListHead=head;

		return ansListHead;
		//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
}