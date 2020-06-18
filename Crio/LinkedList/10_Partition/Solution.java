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
  public static ListNode partition( ListNode head , int x) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

    ListNode smallerHead = null, smallerLast = null;
    ListNode greaterLast = null, greaterHead = null;
    ListNode equalHead = null, equalLast = null;


    while (head != null) {

      if (head.val == x) {
        if (equalHead == null)
          equalHead = equalLast = head;
        else {
          equalLast.next = head;
          equalLast = equalLast.next;
        }
      }

      else if (head.val < x) {
        if (smallerHead == null)
          smallerLast = smallerHead = head;
        else {
          smallerLast.next = head;
          smallerLast = head;
        }
      } else {
        if (greaterHead == null)
          greaterLast = greaterHead = head;
        else {
          greaterLast.next = head;
          greaterLast = head;
        }
      }
      head = head.next;
    }


    if (greaterLast != null)
      greaterLast.next = null;


    if (smallerHead == null) {
      if (equalHead == null)
        return greaterHead;
      equalLast.next = greaterHead;
      return equalHead;
    }


    if (equalHead == null) {
      smallerLast.next = greaterHead;
      return smallerHead;
    }


    smallerLast.next = equalHead;
    equalLast.next = greaterHead;
    return smallerHead;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
  }
}
