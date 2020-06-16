/*
public class ListNode {
   public int val; 
   public ListNode next;
   public ListNode(int x) { val = x; next = null; }
}
*/
import java.util.*;

import crio.ds.List.ListNode;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class RemoveDups{
	public static void main(String [] args)
	{
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i = 0 ; i < n ; ++i) {
            list.add(sc.nextInt());
        }
        sc.close();
        ListNode head = ListNode.createList(list);
        Solution.removeDuplicates(head);
        List<Integer> res = ListNode.extractList(head);
        for(int element: res) {
            System.out.print(element + " ");
        }
        System.out.println();
	}
}
