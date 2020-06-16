import java.util.*;
import crio.ds.Tree.TreeNode;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class Pair {
    int first;
    int second;
    Pair(int a, int b) {
        first = a;
        second = b;
    }
}

public class PathsWithSumRootToLeaf {
    TreeNode makeTreeFromEdges(long val[] , ArrayList<Pair> edges) {
        HashMap<Integer , TreeNode> nodebyIndex = new HashMap<Integer , TreeNode>();
        int n = val.length;
        for (int i = 0; i < n; i++) {
            nodebyIndex.put(i, new TreeNode(val[i]));
        }
        TreeNode root = nodebyIndex.get(0);
        for (int i = 0; i < n; i++) {
            TreeNode ptr = nodebyIndex.get(i);
            if (edges.get(i).first != -1) {

                ptr.left = nodebyIndex.get(edges.get(i).first);
            }
            if (edges.get(i).second != -1) {
                ptr.right = nodebyIndex.get(edges.get(i).second);
            }
        }
        return root;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tests = scanner.nextInt();
        for(int t = 0; t <  tests ; t++) {
            int n, a, b;
            n = scanner.nextInt();
            long val[] = new long[n];
            for (int i = 0; i < n; i++) {
                val[i] = scanner.nextLong();
            }
            ArrayList<Pair> edges = new ArrayList<Pair>();
            for ( int i = 0; i < n; i++) {
                int x;
                x = scanner.nextInt(); 
                a = scanner.nextInt();
                b = scanner.nextInt();
                edges.add(new Pair(a-1, b-1));
            }
            TreeNode root = new PathsWithSumRootToLeaf().makeTreeFromEdges(val, edges);
            long sum;
            sum = scanner.nextLong();
            long answer = new Solution().pathsWithSumRootToLeaf(root,sum);
            System.out.println(answer);
        }
    }
    
}
