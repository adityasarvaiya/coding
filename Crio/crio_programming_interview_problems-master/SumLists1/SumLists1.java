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

class SumLists1 {

  public static void  main (String args []) {
    Scanner sc =  new  Scanner (System.in);

    int n1 = sc.nextInt();
    ArrayList <Integer> list1 = new ArrayList<Integer> ();
    int x;
    for ( int i = 0 ; i < n1; i++) {
      x = sc.nextInt();
      list1.add(x);
    }
    ListNode head1 = ListNode.createList(list1);
    int n2 = sc.nextInt();
    ArrayList <Integer> list2 = new ArrayList<Integer> ();

    for ( int i = 0 ; i < n2; i++) {
      x = sc.nextInt();
      list2.add(x);
    }
    ListNode head2 = ListNode.createList(list2);
    ListNode head = Solution.sumLists1(head1, head2);
    List<Integer> nums = ListNode.extractList(head);

    for ( int i = 0; i < nums.size() ; i++) {
      System.out.print(nums.get(i)  + " ");
    }

  }

}
