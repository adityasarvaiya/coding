import java.io.*;
import java.util.*;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


class ConstructBinaryTreeFromPreorderAndInorderTraversal {
    public static void _makePreOrderFromTree(TreeNode root, List<Long> preOrder) {
        if(root == null) {
            return;
        }
        preOrder.add(root.val);
        _makePreOrderFromTree(root.left, preOrder);
        _makePreOrderFromTree(root.right, preOrder);
    }
    public static List<Long> makePreOrderFromTree(TreeNode root) {
        ArrayList<Long> preOrder = new ArrayList<Long>();
        _makePreOrderFromTree(root, preOrder);
        return preOrder;
    }
    public static void _makeInOrderFromTree(TreeNode root, List<Long> inOrder) {
        if(root == null) {
            return;
        }
        _makeInOrderFromTree(root.left, inOrder);
        inOrder.add(root.val);
        _makeInOrderFromTree(root.right, inOrder);
    }
    public static List<Long> makeInOrderFromTree(TreeNode root) {
        ArrayList<Long> inOrder = new ArrayList<Long>();
        _makeInOrderFromTree(root, inOrder);
        return inOrder;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int preorder[] = new int[n];
        for (int i = 0 ; i < n ; i++) {
            preorder[i] = scanner.nextInt();
        }
        
        int inorder[] = new int[n];
        for (int i = 0 ; i < n ; i++) {
            inorder[i] = scanner.nextInt();
        }
        scanner.close();

        TreeNode result = new Solution().constructBinaryTreeFromPreorderAndInorderTraversal(preorder , inorder);

        List<Long> preOrder = makePreOrderFromTree(result);                
        for(int i = 0 ; i < preOrder.size() ; ++i) {
            System.out.print(preOrder.get(i) + " ");
        }
        System.out.println();

        List<Long> inOrder = makeInOrderFromTree(result);
        for(int i = 0 ; i < inOrder.size() ; ++i) {
            System.out.print(inOrder.get(i) + " ");
        }
        System.out.println();
    }
}
