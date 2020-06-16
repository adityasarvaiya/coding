import crio.ds.List.ListNode;
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */


class Solution {
    public ListNode sortList(ListNode head) {

        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int count = 0;
        ListNode hd = head;
        while (hd != null) {
            hd = hd.next;
            ++count;
        }

        if (count < 2) {
            return head;
        }

        int half = count/2;

        ListNode node = head;
        for (int i = 1; i < half; ++i) {
            node = node.next;
        }

        ListNode half2 = node.next;
        node.next = null;

        ListNode l1 = sortList(head);
        ListNode l2 = sortList(half2);

        ListNode newHead = null;
        ListNode newNode = null;

        if (l1.val < l2.val) {
            newHead = l1;
            ListNode rest = l1.next;
            l1.next = null;
            l1 = rest;
        } else {
            newHead = l2;
            ListNode rest = l2.next;
            l2.next = null;
            l2 = rest;
        }

        newNode = newHead;
        while ((l1 != null) && (l2 != null)) {
            if (l1.val < l2.val) {
                newNode.next = l1;
                ListNode rst = l1.next;
                l1.next = null;
                l1 = rst;
                newNode = newNode.next;
            } else {
                newNode.next = l2;
                ListNode rst = l2.next;
                l2.next = null;
                l2 = rst;
                newNode = newNode.next;
            }
        }


        if (l1 != null) {
            newNode.next = l1;
        }

        if (l2 != null) {
            newNode.next = l2;
        }

        return newHead;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}
