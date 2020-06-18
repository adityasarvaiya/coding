// Definition of ListNode
class ListNode {
    public int val;
    public ListNode next;
    public ListNode(int x) {
        val = x; next = null;
    }
}

public class Solution {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    // helper function to get most significant digit in number
    private ListNode getLastNodeOfList(ListNode head) {
        ListNode endPointerNode = head;
        while (endPointerNode.next != null) {
            endPointerNode = endPointerNode.next;
        }
        return endPointerNode;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int carryOnValue = 0;
        ListNode result = null;

        // iterate through until number of fewer digits is completed
        while (l1 != null && l2 != null) {
            int sum = l1.val + l2.val + carryOnValue;
            ListNode tempRes = new ListNode(sum % 10);
            if (sum > 9) {
                carryOnValue = sum / 10;
            } else {
                carryOnValue = 0;
            }

            if (result == null) {
                result = tempRes;
            } else {
                ListNode endPointerNode = getLastNodeOfList(result);
                endPointerNode.next = tempRes;
            }

            // update to point to next set of digits with same order
            l1 = l1.next;
            l2 = l2.next;

        }

        // handle numbers with different number of digits
        ListNode pendingNode = null;
        if (l1 != null && l2 == null) {
            pendingNode = l1;
        }

        if (l1 == null && l2 != null) {
            pendingNode = l2;
        }

        while (pendingNode != null) {
            int sum = (pendingNode.val + carryOnValue);
            ListNode tempRes = new ListNode(sum % 10);
            if (sum > 9) {
                carryOnValue = sum / 10;
            } else {
                carryOnValue = 0;
            }
            ListNode endPointerNode = getLastNodeOfList(result);
            endPointerNode.next = tempRes;
            pendingNode = pendingNode.next;
        }

        // add carryOn created by addition of largest significant digit
        if (carryOnValue > 0) {
            ListNode tempRes = new ListNode(carryOnValue);
            ListNode endPointerNode = getLastNodeOfList(result);
            endPointerNode.next = tempRes;
        }

        return result;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}