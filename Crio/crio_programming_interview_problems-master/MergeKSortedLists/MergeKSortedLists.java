import java.io.*;
import java.util.*;
import crio.ds.List.ListNode;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class MergeKSortedLists {
    public static void main(String[] args) throws IOException{
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        ListNode lists[] = new ListNode[k];
        for(int i = 0 ; i < k ; i++) {
            int n = scanner.nextInt();
            List<Integer>numbers = new ArrayList<Integer>();
            for(int j = 0 ; j < n ; j++) {
                int value = scanner.nextInt();
                numbers.add(value);
            }
            lists[i] = ListNode.createList(numbers);
        }
        scanner.close();
        ListNode result = new Solution().mergeKSortedLists(lists);
        while(result != null) {
            System.out.print(result.val);
            System.out.print(" ");
            result = result.next;
        }
    }
}
