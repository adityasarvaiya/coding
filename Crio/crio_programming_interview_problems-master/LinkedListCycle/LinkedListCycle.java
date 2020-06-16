/*
public class ListNode {
   public int val; 
   public ListNode next;
   public ListNode(int x) { val = x; next = null; }
}
*/
import crio.ds.List.ListNode;
import java.io.*;
import java.util.*;

public class LinkedListCycle {
    // Implement your solution by completing the below function
    public boolean hasCycle(ListNode head) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (head == null || head.next == null) {
            return false;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return false;
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] list = in.readLine().trim().split(" ");
        int pos = Integer.parseInt(in.readLine().trim());

        ListNode inputLinkedListHead = ListNode.generateLinkedListWithCycle(list, pos);
        boolean result = new LinkedListCycle().hasCycle(inputLinkedListHead);

        System.out.print(String.valueOf(result));
    }
}