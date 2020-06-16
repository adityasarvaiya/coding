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

  public static boolean isPalindrome( ListNode head) {

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    Stack<Integer> st = new Stack<Integer> ();
    ListNode temp = head;

    while (temp != null) {
      st. push(temp.val);
      temp = temp.next;
    }

    while (!st.empty()) {
      Integer top = (Integer) st.pop();
      if ( top != head.val) {
        return false;
      }
      head = head.next;
    }
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    return true;
  }

}
