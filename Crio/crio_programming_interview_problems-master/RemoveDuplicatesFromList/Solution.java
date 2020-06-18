import java.io.*;
import java.util.*;
import crio.ds.List.ListNode;
/*
// Definition for ListNode
public class ListNode {

    public int val;
    public ListNode next;
    ListNode() {}
    ListNode(int x) {
        val = x;
        next = null;
    }
};
*/
class Solution {

	public static ListNode removeDuplicatesFromList(ListNode head) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	    ListNode dummy = new ListNode(0); 
	    dummy.next = head;
	    ListNode prev = dummy; 
	    ListNode curr = head; 
	  
	    while(curr != null) 
	    { 
		while(curr.next != null && 
		      prev.next.val == curr.next.val)
		    curr = curr.next; 
	  
		if (prev.next == curr) 
		    prev = prev.next; 
		else
		    prev.next = curr.next; 
	  
		curr = curr.next; 
	    } 
	    head = dummy.next; 
	    return head;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
  	}
}

