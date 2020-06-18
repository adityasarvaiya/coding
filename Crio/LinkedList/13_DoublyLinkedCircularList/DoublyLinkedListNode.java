// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

public class DoublyLinkedListNode {
	int val;
	public DoublyLinkedListNode  prev;
	public DoublyLinkedListNode  next;

	DoublyLinkedListNode(int x, DoublyLinkedListNode p , DoublyLinkedListNode  n ) {
		val = x;
		prev = p;
		next = n;
	}
};