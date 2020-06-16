import java.io.*;
import java.util.*;

class BinaryTreeLevelOrderTraversal {
    // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
    // complete the below function implementation
    public List<List<Integer>> levelOrder(TreeNode root) {
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        List<List<Integer>> answer = new ArrayList<List<Integer>>();
        Queue<TreeNode> q = new  LinkedList<TreeNode>();
         if(root == null)
            return answer;
        q.add(root);
        while(!q.isEmpty()) {
            List<Integer> atThisLevel = new ArrayList<Integer>();
            int size = q.size();
            while(size > 0) {
                size--;
                TreeNode temp = q.peek();
                q.remove();
                if(temp.left != null) {
                    q.add(temp.left);
                }
                if(temp.right != null) {
                    q.add(temp.right);
                }
                atThisLevel.add(temp.val);
            }
            answer.add(atThisLevel);
        }
        return answer; 
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
        // CRIO_UNCOMMENT_START_MODULE_L2_PROBLEMS
        // List<List<Integer>> answer = new ArrayList<List<Integer>>();
        // return answer;
        // CRIO_UNCOMMENT_END_MODULE_L2_PROBLEMS  
    }
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int n;
        n = scanner.nextInt();
        String tree[] = new String[n];
        for(int i = 0 ; i < n ; i++) {
            tree[i] = scanner.next();
        }
        scanner.close();
        TreeNode root = null;
        root = new TreeNode().makeTreeFromArray(0 , tree , root);
        List<List<Integer>> result = new BinaryTreeLevelOrderTraversal().levelOrder(root);
        for(List<Integer> i : result) {
            for(Integer j : i) {
                System.out.printf("%d ",j);
            }
            System.out.println();
        }
    } 
}
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode () {
    }
    TreeNode (int x) {
        val = x;
        left = null;
        right = null;
    }
    public TreeNode makeTreeFromArray(int idx , String tree[] , TreeNode root) {
        if(idx >= tree.length) {
            return null;
        }
        if(tree[idx].equals("null")) {
            return null;
        }
        int x = Integer.parseInt(tree[idx]);
        root = new TreeNode(x);
        root.left = makeTreeFromArray(2*idx + 1  , tree , root.left);
        root.right = makeTreeFromArray(2*idx + 2 , tree , root.right);
        return root;
    }  
}