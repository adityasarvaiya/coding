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
	public static ListNode deleteKthToLast(ListNode head, int k) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

		if (head == null || k == 0) return head;
		int size = sizeofListNode(head);
		ListNode temp = head;
		ListNode prev = null;
		int deletefromFirst = size - k;
		if (deletefromFirst == 0) {
			temp = temp.next;
			return temp;
		}

		while (deletefromFirst > 0) {
			deletefromFirst--;
			prev = temp;
			temp = temp.next;
		}
		prev.next = temp.next;
		return head;

		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
}

