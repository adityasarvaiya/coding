/*
public class ListNode {
   public int val; 
   public ListNode next;
   public ListNode(int x) { val = x; next = null; }
}
*/
import java.util.*;
import java.io.*;

import crio.ds.List.ListNode;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class ReturnKthToLast {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i = 0 ; i < n ; ++i) {
            int x = scanner.nextInt();
            list.add(x);
        }
        int k = scanner.nextInt();
        scanner.close();

        ListNode head = ListNode.createList(list);
        Solution so=new Solution();
        ListNode ans=so.returnKthToLast(head,k);
        System.out.println(ans.val);
    }
}
