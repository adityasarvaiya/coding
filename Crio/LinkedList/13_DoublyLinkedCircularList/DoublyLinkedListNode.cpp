// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class DoublyLinkedListNode {
public:
    int val;
    DoublyLinkedListNode *prev;
    DoublyLinkedListNode *next;

    DoublyLinkedListNode(int x, DoublyLinkedListNode* p=NULL, DoublyLinkedListNode* n=NULL) {
        val = x;
        prev = p;
        next = n;
    }
};