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
  public static ListNode sumLists1( ListNode head1 , ListNode head2) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    ListNode ans = new ListNode(0);
    ListNode ansHead = ans;
    int sizeOfFirst = 0 , sizeOfSecond = 0;
    ListNode temp = head1;
    while (temp != null) {
      sizeOfFirst++;
      temp = temp.next;
    }
    temp = head2;
    while (temp != null) {
      sizeOfSecond++;
      temp = temp.next;
    }
    boolean flag = false;
    int carry = 0;
    int minSize = Math.min(sizeOfFirst, sizeOfSecond);
    for ( int i = 0; i < minSize; ++i) {
      int x = head1.val + head2.val;
      if ( flag == false) {
        ans.val = x % 10;
        carry = x / 10; flag = true;
        head1 = head1.next;
        head2 = head2.next;
        continue;
      }
      int rem = (carry + x % 10) % 10;
      ans.next = new ListNode(rem);
      ans = ans.next;
      carry = (carry + x ) / 10;
      head1 = head1.next;
      head2 = head2.next;
    }
    while (head1 != null) {
      int x = head1.val;
      int rem = (carry + x % 10) % 10;
      carry = (carry + x  ) / 10;
      ans.next = new ListNode(rem);
      ans = ans.next;
      head1 = head1.next;
    }

    while (head2 != null) {
      int x = head2.val;
      int rem = (carry + x % 10) % 10;
      carry = (carry + x  ) / 10;
      ans.next = new ListNode(rem);
      ans = ans.next;
      head2 = head2.next;
    }
    if ( carry > 0) {
      ans.next = new ListNode(carry);
    }
    temp = ansHead;
    // while (temp != null) {
    //   System.out.print( temp.val + " ");
    //   temp = temp.next;
    // }
    // System.out.println(" ");
    return ansHead;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
  }
}
