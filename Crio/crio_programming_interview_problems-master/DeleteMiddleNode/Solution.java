/*
public class ListNode {
   public int val; 
   public ListNode next;
   public ListNode(int x) { val = x; next = null; }
}
*/
import java.util.*;

import crio.ds.List.ListNode;

class Solution {
    public static void deleteMiddleNode(ListNode node) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    	ListNode next=node.next;
		node.val=next.val;
		node.next=next.next;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}
