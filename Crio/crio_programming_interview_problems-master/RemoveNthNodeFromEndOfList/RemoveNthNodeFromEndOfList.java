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

class RemoveNthNodeFromEndOfList {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        ListNode hd = head;

        int count = 0;
        while (hd != null) {
            hd = hd.next;
            ++count;
        }

        if (count < n)
            return head;

        if (count == n) {
            ListNode rest = head.next;
            head = null;
            return rest;
        }

        ListNode node = head;
        for (int i = 1; i < count - n; ++i) {
            node = node.next;
        }

        ListNode removed = node.next;
        node.next = removed.next;

        removed = null;

        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
        return head;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        List<Integer> numbers = new ArrayList<Integer>();

        for (int i = 0; i < n; ++i) {
            numbers.add(in.nextInt());
        }

        ListNode list = ListNode.createList(numbers);
        ListNode result = new RemoveNthNodeFromEndOfList().removeNthFromEnd(list, k);

        List<Integer> res = ListNode.extractList(result);

        for (int i = 0; i < res.size(); ++i) {
            System.out.printf("%d ", res.get(i));
        }
        in.close();
    }

}
