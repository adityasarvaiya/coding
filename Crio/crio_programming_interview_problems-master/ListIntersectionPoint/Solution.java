import java.io.*;
import java.util.*;
import crio.ds.List.ListNode;
/*
// Definition for ListNode
public class ListNode {

    public int val;
    public ListNode next;
    ListNode() {}
    ListNode(int x) {
        val = x;
        next = null;
    }
};
*/
class Solution {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	public static int sizeofListNode(ListNode head) {
		int size = 0;
		while (head != null) {
			head = head.next;
			size++;
		}
		return size;
	}
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	public static ListNode listIntersectionPoint(ListNode head1, ListNode head2) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

		int size1 = sizeofListNode(head1);
		int size2 = sizeofListNode(head2);

		while (size1 > size2) {
			head1 = head1.next;
			size1--;
		}
		while (size2 > size1) {
			head2 = head2.next;
			size2--;
		}
		while (head1 != null && head1.val != head2.val) {
			head1 = head1.next;
			head2 = head2.next;
		}
		return head1;

		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
}

