import java.util.*;
import crio.ds.Tree.TreeNode;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

public class MinimalTree {

    public static void inorder(TreeNode root , ArrayList<Long>inorderArray) {
        if(root == null) {
            return;
        }
        inorder(root.left , inorderArray);
        inorderArray.add(root.val);
        inorder(root.right , inorderArray);
    }  
    public static boolean isValidBST(TreeNode root , long low ,long high) {
        if(root == null) {
            return true;
        }
        if(root.val > high || root.val < low) {
            return false;
        }
        boolean leftValid = isValidBST(root.left, low, root.val);
        boolean rightValid = isValidBST(root.right, root.val, high);

        return (leftValid && rightValid);
    }
    public static int findHeight(TreeNode root) {
        if(root == null) {
            return 0;
        }
       
        int leftHeight = findHeight(root.left);
        int rightHeight = findHeight(root.right);

        return Math.max(leftHeight , rightHeight) + 1;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int treeArray[] = new int[n];
        for(int i = 0 ; i < n ; i++) {
            treeArray[i] = scanner.nextInt();
        }
        scanner.close();
        Solution solution = new Solution();
        TreeNode root = solution.findMinimalTree(treeArray);
        ArrayList<Long>inorderArray = new ArrayList<Long>();
        inorder(root , inorderArray);
        int height = -2;
        if(inorderArray.size() != n) {
            height = -1;
        } else {
            for(int i = 0 ; i < n ; i++) {
                if(treeArray[i] != inorderArray.get(i)) {
                    height = -1;
                    break;
                }
            }  
            if(height == -2) {
                boolean isValid = isValidBST(root, treeArray[0] , treeArray[n-1]);
                if(isValid) {
                    height = findHeight(root);
                } else {
                    height = -1;
                }
            }
        }
        System.out.println(height);
    }
}