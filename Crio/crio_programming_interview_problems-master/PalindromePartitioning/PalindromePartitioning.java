import java.util.*;

public class PalindromePartitioning {
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    ArrayList<ArrayList<String> > answer;
    ArrayList<String> oneAnswer; 
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    ArrayList<ArrayList<String> > palindromePartitioning(String s) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        answer = new ArrayList<>();
        if(s == null || s.length() == 0) { 
            return answer;
        }
        partitions(s, new ArrayList<>(), 0);
        return answer;
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    void partitions(String s, List<String> current, int index){
        if(index >= s.length()){
            answer.add(new ArrayList<>(current));
            return;
        }
        
        for(int i = index; i < s.length(); i++){
            if(isPalindrome(s.substring(index, i + 1))){
                current.add(s.substring(index, i + 1));
                partitions(s, current, i + 1);
                current.remove(current.size() - 1);
            }
        }
    }
    
    public boolean isPalindrome(String str){
        int start = 0;
        int end = str.length() - 1;
        while(start < end){
            if(str.charAt(start) != str.charAt(end)){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        ArrayList<ArrayList<String> > result = new PalindromePartitioning().palindromePartitioning(s);
        for(int i = 0 ; i < result.size() ; i++) {
            for(int j = 0 ; j < result.get(i).size() ; j++) {
                System.out.print(result.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }
}
