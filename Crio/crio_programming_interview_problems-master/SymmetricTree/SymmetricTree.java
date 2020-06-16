import crio.ds.Tree.TreeNode;
import java.io.*;
import java.util.*;

public class SymmetricTree {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    public boolean isMirror(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null)
            return true;
        if (t1 == null || t2 == null)
            return false;
        return (t1.val == t2.val) && isMirror(t1.right, t2.left) && isMirror(t1.left, t2.right);
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    // Implement your solution by completing the below function
    public boolean isSymmetric(TreeNode root) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        return isMirror(root, root);
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return false;
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String input = in.readLine();
        String[] treeElements = new String[0];

        if (input.contains(" "))
            treeElements = input.split(" ");
        else if (!input.isEmpty())
            treeElements = new String[] { input };

        TreeNode root = TreeNode.generateTree(treeElements);
        boolean result = new SymmetricTree().isSymmetric(root);
        System.out.print(String.valueOf(result));
    }
}