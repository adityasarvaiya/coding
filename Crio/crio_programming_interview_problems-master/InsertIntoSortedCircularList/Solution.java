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
	public ListNode insertIntoSortedCircularList(ListNode head,int insertVal)
	{
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		if(head==null)
		{
			ListNode ans=new ListNode(insertVal);
			ans.next=ans;
			return ans;
		}
		ListNode minn=head,maxx=head,node=head.next;
		while(node!=head)
		{
			if(node.val<minn.val)
			{
				minn=node;
			}
			if(node.val>maxx.val)
			{
				maxx=node;
			}
			node=node.next;
		}
		if(insertVal>maxx.val || insertVal<minn.val)
		{
			ListNode temp=new ListNode(insertVal);
			ListNode holder=maxx.next;
			maxx.next=temp;
			temp.next=holder;
			return head;
		}
		else
		{
			ListNode prev=minn;
			node=minn.next;
			while(node!=minn)
			{
				if(node.val>=insertVal && prev.val<insertVal)
				{
					ListNode temp=new ListNode(insertVal);
					prev.next=temp;
					temp.next=node;
					break;
				}
				prev=node;
				node=node.next;
			}
			return head;
		}
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
}