import java.util.*;

public class ReplaceWords {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    public static class Node{
        boolean end;
        Node[] child;
        Node(){
            child = new Node[26];
        }
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    public static String replaceWords(ArrayList<String>dict, String sentence){
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        StringBuilder ans = new StringBuilder();
        Node head = new Node();
        for (String key : dict) {
            Node cur = head;
            for (char ch : key.toCharArray()) {
                if(cur.child[ch-'a']==null){
                    cur.child[ch-'a'] = new Node();
                }
                cur = cur.child[ch-'a'];
            }
            cur.end = true;
        }
        for (String word : sentence.split("\\s+")){
            Node cur = head;
            StringBuilder temp = new StringBuilder();
            for (char ch : word.toCharArray()) {
                if(cur.end){
                    break;
                }
                if(cur.child[ch-'a']!=null){
                    cur = cur.child[ch-'a'];
                }
                else{
                    temp.delete(0, temp.length());
                    temp.append(word);
                    break;
                }
                temp.append(ch);
            }
            temp.append(" ");
            ans.append(temp);
        }
        return ans.toString();
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<String>dict = new ArrayList<String>();
        for (int i = 0; i < n; i++) {
            dict.add(sc.next());
        }
        String sentence = sc.nextLine();
        sentence = sc.nextLine();
        String ans = replaceWords(dict,sentence);
        System.out.print(ans);
        sc.close();
    }    
}
