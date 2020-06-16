import java.util.*;
import crio.ds.Tree.TreeNode;

/*
// Definition of TreeNode
public class TreeNode {
    public long val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode (long x) {
        val = x;
        left = null;
        right = null;
    }
}
*/

public class Solution {
    ArrayList<LinkedList<Long>> inputSequencesForBst(TreeNode node) { 
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS	    
        ArrayList<LinkedList<Long>> result = new ArrayList<LinkedList<Long>>(); 
        if (node == null) {
            result.add(new LinkedList<Long>());
            return result ; 
        }
        LinkedList<Long> prefix = new LinkedList<Long>(); 
        prefix.add(node.val); 
        ArrayList<LinkedList<Long> > leftSeq = inputSequencesForBst(node.left);
        ArrayList<LinkedList<Long> > rightSeq = inputSequencesForBst(node.right);  
        for (LinkedList<Long> left : leftSeq) {
             for (LinkedList<Long> right : rightSeq) {
             ArrayList<LinkedList<Long>> weaved = new ArrayList<LinkedList<Long>>();
             weaveLists(left, right , weaved, prefix) ;
             result.addAll(weaved);
                }
            }
        return result ;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        }
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS	    
    void weaveLists(LinkedList<Long> first , LinkedList<Long> second, ArrayList<LinkedList<Long>> results , LinkedList<Long> prefix ) {
        if (first.size() == 0 || second.size() == 0) {
        LinkedList<Long> result = (LinkedList<Long>) prefix.clone();
        result.addAll(first) ;
        result.addAll(second);
        results.add(result);
        return ;
        }
        long headFirst = first.removeFirst();
        prefix.addLast(headFirst);
        weaveLists(first , second, results , prefix);
        prefix.removeLast();
        first.addFirst(headFirst);  

        long headSecond = second.removeFirst();
        prefix.addLast(headSecond);
        weaveLists(first , second, results , prefix);
        prefix.removeLast();
        second.addFirst(headSecond); 
    }
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
 
    
}
