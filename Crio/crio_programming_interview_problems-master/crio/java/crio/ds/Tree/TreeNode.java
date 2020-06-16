package crio.ds.Tree;

import java.io.*;
import java.util.*;
// CRIO_SOLUTION_AND_STUB_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_AND_STUB_END_MODULE_L1_PROBLEMS


public class TreeNode {
    public long val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode next;

//    TreeNode () {}

    public TreeNode (long x) {
        val = x;
        left = null;
        right = null;
        next = null;
    }
    public static Vector<TreeNode> readTreeFromEdges(int n,Vector<Integer> value, Vector<Vector<Integer> > edges)
    {
        Vector<TreeNode > nodes= new Vector<TreeNode>();
        for(int i=0;i<n;i++)
        {
            TreeNode temp = new TreeNode(value.get(i+1));
            nodes.add(temp);
        }
        for(Vector<Integer> edge: edges)
        {
            int parent = edge.get(0);
            int leftchild = edge.get(1);
            int rightchild = edge.get(2);
            if(leftchild != -1)
                nodes.get(parent - 1).left = nodes.get(leftchild - 1);
            if(rightchild != -1)
                nodes.get(parent - 1).right = nodes.get(rightchild - 1); 
        }
        return nodes;
    }
    public static Vector<TreeNode> readTree(Scanner sc)
    {
        // IO 
        int n;
        n=sc.nextInt();
        Vector<Integer> value=new Vector<Integer>();
        value.add(-1);
        for (int i = 1; i <= n; i++) 
            value.add(sc.nextInt());
        Vector<Vector <Integer> > edges= new Vector<Vector<Integer> >();
        for(int i=0;i<n;i++)
        {
            Vector<Integer> temp=new Vector<Integer>();
            temp.add(sc.nextInt());
            temp.add(sc.nextInt());
            temp.add(sc.nextInt());
            edges.add(temp);
        }
        return readTreeFromEdges(n,value,edges);
    }
    //when using this pass a scanner object as parameter which takes system.in stream.
    public static Vector<TreeNode> readTreeReturnAllNodes(Scanner sc)
    {
        Vector<TreeNode> nodes = readTree(sc);
        return nodes;
    }

    public static TreeNode readTreeReturnRoot(Scanner sc)
    {
        Vector<TreeNode> nodes = readTree(sc);
        TreeNode root = nodes.get(0);
        return root;   
    }

    public static TreeNode makeTreeFromArray(int idx , String tree[] , TreeNode root) {
        if (idx >= tree.length)
            return null;

        if (tree[idx].equals("null"))
            return null;

        long x = Long.parseLong(tree[idx]);
        root = new TreeNode(x);
        root.left = makeTreeFromArray(2 * idx + 1  , tree , root.left);
        root.right = makeTreeFromArray(2 * idx + 2 , tree , root.right);
        return root;
    }

    public static List<String> makeNextPointersFromTree(TreeNode root , List<String>nextArray) {
        Queue<TreeNode> q = new  LinkedList<TreeNode>();
        if (root == null)
            return nextArray;
        q.add(root);
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0 ; i < size ; i++) {
                TreeNode temp = q.peek();
                q.remove();
                if (temp.left != null) {
                    q.add(temp.left);
                }
                if (temp.right != null) {
                    q.add(temp.right);
                }
                if (temp.next == null) {
                    nextArray.add("null");
                } else {
                    nextArray.add(Long.toString(temp.next.val));
                }
            }
        }
        return nextArray;
    }
}
