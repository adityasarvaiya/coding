import java.io.*;
import java.util.*;
import crio.ds.List.ListNode;

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        ListNode head = new ListNode(-1);
        ListNode prev = head;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }
            prev = prev.next;
        }

        prev.next = l1 == null ? l2 : l1;
        return head.next;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}

