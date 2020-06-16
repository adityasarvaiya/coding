import java.util.*;
import crio.ds.Tree.TreeNode;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
public class CheckBalanced {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int tests=0; tests<t;tests++)
        {
            TreeNode root  = TreeNode.readTreeReturnRoot(sc);
            boolean answer = new Solution().checkBalanced(root);
            if(answer) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}