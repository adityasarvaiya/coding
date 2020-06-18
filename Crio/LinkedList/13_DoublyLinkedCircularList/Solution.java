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
	public static class DoublyLinkedListNode {
		int val;
		public DoublyLinkedListNode  prev;
		public DoublyLinkedListNode  next;
	
		DoublyLinkedListNode(int x, DoublyLinkedListNode p , DoublyLinkedListNode  n ) {
			val = x;
			prev = p;
			next = n;
		}
	}

	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	public static DoublyLinkedListNode  convertToDoublyLinkedList(ListNode head) {

		DoublyLinkedListNode  result = null;
		DoublyLinkedListNode  current = null;
		if (head == null) {
			return result;
		}
		while (head != null) {
			if (result == null) {
				result = new DoublyLinkedListNode(head.val, null, null);
				current = result;
			} else {
				current.next =  new DoublyLinkedListNode(head.val, current, null);
				current = current.next;
			}
			head = head.next;
		}
		current.next = result;
		result.prev = current;
		return result;
	}
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

	public static DoublyLinkedListNode doublyLinkedCircularList(ListNode head) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		DoublyLinkedListNode  result = convertToDoublyLinkedList(head);
		return result;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
}

