import crio.ds.Tree.TreeNode;
import java.io.*;
import java.util.*;
import java.lang.*;

public class MaximumDepthOfBinaryTree {
    // Implement your solution by completing the below function
    public int maxDepth(TreeNode root) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (root == null)
            return 0;
        if (root.left == null && root.right == null)
            return 1;

        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return 0;
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
        int maxDepth = new MaximumDepthOfBinaryTree().maxDepth(root);
        System.out.print(Integer.toString(maxDepth));
    }
}