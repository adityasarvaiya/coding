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

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
class LoopDetection {
  public static ListNode getKthElement(ListNode head , int k) {
    if (k == 1)
      return head;
    while (k > 1) {
      head = head.next;
      k--;
    }
    return head;
  }
  public static ListNode addNodeAtEnd(ListNode head , ListNode node) {
    ListNode cur = head;
    while (cur.next != null) {
      cur = cur.next;
    }
    cur.next = node;
    return head;
  }
  public static void  main (String args []) {
    Scanner sc =  new  Scanner (System.in);

    int n = sc.nextInt();
    ArrayList <Integer> list = new ArrayList<Integer> ();

    for ( int i = 0 ; i < n; i++) {
      int x = sc.nextInt();
      list.add(x);
    }

    ListNode head = ListNode.createList(list);
    int k = sc.nextInt();

    ListNode node  = getKthElement(head, k);
    head = addNodeAtEnd(head , node);

    ListNode result = Solution.loopDetection(head);
    System.out.print(result.val);

  }

}
