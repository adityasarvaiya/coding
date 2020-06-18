import java.io.*;
import java.util.*;
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class AddTwoNumbers {
    public static ListNode createList(List<Integer> numbers) {
        if (numbers.size() == 0)
            return null;
    
        ListNode head = new ListNode(numbers.get(0));
        ListNode node = head;
    
        for (int i = 1; i < numbers.size(); ++i) {
            node.next = new ListNode(numbers.get(i));
            node = node.next;
        }
    
        return head;
    }
    
    public static List<Integer> extractList(ListNode head) {
        List<Integer> lst = new ArrayList<Integer>();
    
        while(head != null) {
            lst.add(head.val);
            head = head.next;
        }
    
        return lst;
    }
    
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        List<Integer> firstNumber = new ArrayList<Integer>();
        int n = scanner.nextInt();
        for (int i = 0; i < n; ++i)
            firstNumber.add(scanner.nextInt());

        List<Integer> secondNumber = new ArrayList<Integer>();
        n = scanner.nextInt();
        for (int i = 0; i < n; ++i)
            secondNumber.add(scanner.nextInt());

        scanner.close();

        ListNode firstNumberList = createList(firstNumber);
        ListNode secondNumberList = createList(secondNumber);

        ListNode addedNumber = new Solution().addTwoNumbers(firstNumberList, secondNumberList);
        List<Integer> result = extractList(addedNumber);
        for(Integer i : result){
            System.out.print(i+" ");
        }
    }
}