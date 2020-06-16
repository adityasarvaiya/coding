/*
public class ListNode {
   public int val; 
   public ListNode next;
   public ListNode(int x) { val = x; next = null; }
}
*/
import java.io.*;
import java.util.*;
import crio.ds.List.ListNode;
class Solution {
  public static ListNode loopDetection( ListNode head) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    ListNode slow = head , fast = head.next;

    while (slow != null && fast != null && fast.next != null && slow != fast) {
      slow = slow.next;
      fast = fast.next.next;
    }
    int length_of_loop = 1;

    while (fast.next != slow) {
      fast = fast.next;
      length_of_loop++;
    }

    fast = head;
    slow = head;

    for ( int i = 0; i < length_of_loop; i++) {
      fast = fast.next;
    }
    while (slow != fast) {

      fast = fast.next;
      slow = slow.next;
    }
    return fast;

// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
  }
}
