/*
public class ListNode {
   public int val;
   public ListNode next;
   public ListNode(int x) { val = x; next = null; }
}
*/
import crio.ds.List.*;
import java.io.*;
import java.util.*;

public class LinkedListCycle {

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

    }
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    public static ListNode generateLinkedListWithCycle(ArrayList<Integer> nums, int pos) {
        ListNode list = ListNode.createList(nums);
        if (pos == -1) {
            return list;
        }
        ListNode head = list;
        ListNode tail = list;
        while (pos > 0) {
            pos--;
            head = head.next;
        }
        while (tail.next != null) {
            tail = tail.next;
        }
        tail.next = head;
        return list;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<Integer> ();
        while (sc.hasNextInt()) {
            list.add(sc.nextInt());
        }
        int index = list.size() - 1;
        int pos = list.get(index);
        list.remove(index);

        ListNode inputLinkedListHead = generateLinkedListWithCycle(list, pos);
        boolean result = new LinkedListCycle().hasCycle(inputLinkedListHead);

        System.out.print(String.valueOf(result));
    }
}