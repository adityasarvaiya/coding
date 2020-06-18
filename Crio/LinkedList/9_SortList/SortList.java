/*
public class ListNode {
   public int val; 
   public ListNode next;
   public ListNode(int x) { val = x; next = null; }
}
*/
import java.io.*;
import java.util.*;
import crio.ds.List.ListNode;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class SortList {

    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        List<Integer> nums = new ArrayList<Integer>();

        for (int i = 0 ; i < n ;i++) {
            nums.add(scanner.nextInt());
        }

        ListNode list = ListNode.createList(nums);
        ListNode sortedList = new Solution().sortList(list);
        List<Integer> res = ListNode.extractList(sortedList);
        for (int i = 0; i < res.size(); ++i) {
            System.out.printf("%d ", res.get(i));
        }
    }
}
