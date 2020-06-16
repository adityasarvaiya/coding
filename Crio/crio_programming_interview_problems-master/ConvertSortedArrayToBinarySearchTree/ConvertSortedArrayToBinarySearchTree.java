import crio.ds.Tree.TreeNode;
import java.io.*;
import java.util.*;

public class ConvertSortedArrayToBinarySearchTree {
    // Implement your solution by completing the below function
    public TreeNode sortedArrayToBST(int[] num) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (num.length == 0) {
            return null;
        }
        TreeNode head = helper(num, 0, num.length - 1);
        return head;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return new TreeNode(-1);
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    public TreeNode helper(int[] num, int low, int high) {
        if (low > high) { // Done
            return null;
        }
        int mid = (low + high) / 2;
        TreeNode node = new TreeNode(num[mid]);
        node.left = helper(num, low, mid - 1);
        node.right = helper(num, mid + 1, high);
        return node;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        int[] array = new int[scanner.nextInt()];
        for (int i = 0; i < array.length; i++)
            array[i] = scanner.nextInt();
        scanner.close();

        TreeNode treeRoot = new ConvertSortedArrayToBinarySearchTree().sortedArrayToBST(array);
        String treeAsArray = TreeNode.treeNodeToString(treeRoot);
        System.out.print(treeAsArray);
    }
}