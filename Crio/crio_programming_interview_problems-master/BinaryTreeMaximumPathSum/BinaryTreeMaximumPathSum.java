import java.util.Scanner;
import java.util.concurrent.TimeUnit;
import java.io.*;
import crio.ds.Tree.TreeNode;


class BinaryTreeMaximumPathSum {
    // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
    long answer;

    public long maxSum(TreeNode root) {
        if(root == null)
            return 0;

        long maxSumLeft = maxSum(root.left);
        long maxSumRight = maxSum(root.right);
        long maxWithNode = root.val;

        if(maxWithNode < root.val + maxSumLeft)
            maxWithNode = root.val + maxSumLeft;

        if(maxWithNode < root.val + maxSumRight)
            maxWithNode = root.val + maxSumRight;

        if(answer < maxWithNode)
            answer = maxWithNode;

        if(answer < maxSumLeft + maxSumRight + root.val)
            answer = maxSumLeft + maxSumRight + root.val;

        return maxWithNode;
    }
    // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

    // TODO: implement your solution by completing the below function
    public long maxPathSum(TreeNode root) {
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        answer = root.val;
        long temp = maxSum(root);
        return answer;
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L2_PROBLEMS
        //return 0;
        // CRIO_UNCOMMENT_END_MODULE_L2_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int n;
        n = scanner.nextInt();
        String tree[] = new String[n];

        for(int i = 0 ; i < n ; i++)
            tree[i] = scanner.next();

        scanner.close();
        TreeNode root = null;
        root = TreeNode.makeTreeFromArray(0, tree, root);
        long result = new BinaryTreeMaximumPathSum().maxPathSum(root);
        System.out.println(result);
    }
}