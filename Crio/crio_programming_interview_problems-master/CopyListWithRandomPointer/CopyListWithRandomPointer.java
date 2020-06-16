import java.util.Scanner;
import java.util.*;
import java.lang.*;
import crio.ds.List.*;

/* Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

class CopyListWithRandomPointer {

    // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
    Map<Node, Integer> buildMap(Node head) {
        Map<Node, Integer> map = new HashMap<>();
        map.put(null, -1);

        int i = 0;
        while (head != null) {
            map.put(head, i++);
            head = head.next;
        }

        return map;
    }

    Node buildList(Node head, Map<Node, Integer> map) {
        Node newList = null;
        Node trav = null;

        Map<Integer, Node> reverseMap = new HashMap<>();
        Node headBkp = head;
        int i = 0;
        while (head != null) {

            if (newList == null) {
                newList = new Node(head.val, null, null);
                trav = newList;
            } else {
                trav.next = new Node(head.val, null, null);
                trav = trav.next;
            }
            reverseMap.put(i++, trav);
            head = head.next;
        }

        head = headBkp;
        trav = newList;
        while (head != null) {
            int nodeIndex= map.get(head.random);
            if (nodeIndex != -1)
                trav.random = reverseMap.get(nodeIndex);
            head = head.next;
            trav = trav.next;
        }

        return newList;
    }
    // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

    public Node copyRandomList(Node head) {
    // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        if (head == null)
            return null;

        Map<Node, Integer> map = buildMap(head);
        return buildList(head, map);
    // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

    // CRIO_UNCOMMENT_START_MODULE_L2_PROBLEMS
    // return null;
    // CRIO_UNCOMMENT_END_MODULE_L2_PROBLEMS
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        List<Integer> nums = new ArrayList<>();

        for(int i = 0 ; i < n ;i++) {
            nums.add(scanner.nextInt());
        }

        List<String> random = new ArrayList<>();
        for(int i = 0 ; i < n ;i++) {
            random.add(scanner.next());
        }

        Node list = new Node().makeList(nums, random);
        Node clonedList = new CopyListWithRandomPointer().copyRandomList(list);

        if (clonedList != null) {
            clonedList.print(clonedList);
        }
    }
}
