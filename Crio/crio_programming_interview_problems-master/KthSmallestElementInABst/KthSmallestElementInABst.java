import java.util.*;
import java.io.*;
import crio.ds.Tree.TreeNode;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class KthSmallestElementInABst {
    public static TreeNode getTreeFromInput(int n, int[] val, int[][] edges) {
        TreeNode[] nodes = new TreeNode[n];
        for(int i = 0; i < n ; ++i) {
            nodes[i] = new TreeNode(val[i]);
        }

        for(int i = 0 ; i < n ; ++i) {
            
            int parentIdx = edges[i][0] - 1;
            int leftChildIdx = edges[i][1] - 1;
            int rightChildIdx = edges[i][2] - 1;
    
            if(leftChildIdx >= 0) {
                nodes[parentIdx].left = nodes[leftChildIdx];
            }
            if(rightChildIdx >= 0) {
                nodes[parentIdx].right = nodes[rightChildIdx];
            }
        }
        return nodes[0];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] val = new int[n];
        for (int i = 0; i < n; ++i) {
            val[i] = scanner.nextInt();
        }
        int[][] edges = new int[n][3];
        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < 3 ; ++j) {
                edges[i][j] = scanner.nextInt();
            }
        }
        int k = scanner.nextInt();
        scanner.close();

        TreeNode root = getTreeFromInput(n, val, edges);
        int result = new Solution().kthSmallest(root, k);
        System.out.println(result);
    }
}
