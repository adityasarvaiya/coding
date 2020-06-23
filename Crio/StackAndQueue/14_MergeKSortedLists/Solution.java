import java.io.*;
import java.util.*;
import crio.ds.List.ListNode;

/*
public class ListNode {
   public int val; 
   public ListNode next;
   public ListNode(int x) { val = x; next = null; }
}
*/
class Solution {
    public ListNode mergeKSortedLists(ListNode[] lists) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS  
        int low = 0 , high = lists.length;

        ListNode answer = mergeListsRecur(low , high-1 , lists);
        return answer;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS  
    public ListNode mergeListsRecur(int low , int high , ListNode[] lists) {

        if(low  > high) {
            return null;
        }
        if(low == high) {
            return lists[low];
        }
        int mid = (low + high)/2;
        ListNode left = mergeListsRecur(low , mid , lists);
        ListNode right = mergeListsRecur(mid+1 , high , lists);
        ListNode merged = mergeTwoLists(left , right);
        return merged;  
    }
    public ListNode mergeTwoLists(ListNode A , ListNode B) {
        ListNode answer = new ListNode(0);
        answer.next = null;
        ListNode i = A , j = B , temp = answer;
        while(i != null && j != null) {
            if(i.val < j.val) {
                temp.next = i;
                i = i.next;
                temp = temp.next;
            }
            else {
                temp.next = j;
                j = j.next;
                temp = temp.next;
            }
        }
        while(i != null) {
            temp.next = i;
            i = i.next;
            temp = temp.next;
        }
        while(j != null) {
            temp.next = j;
            j = j.next;
            temp = temp.next;
        }
    answer = answer.next;
    return answer;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

