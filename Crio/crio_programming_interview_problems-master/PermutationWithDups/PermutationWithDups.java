import java.util.*;
public class PermutationWithDups {
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    Set<String> distinct = new TreeSet<String>();
    void permute(int index , String s , char permutation[],int taken[]) {
        if(index == s.length()) {
            String ans = "";
            for(int i = 0 ; i < permutation.length ; i++) {
                ans += permutation[i];
            }
            distinct.add(ans);
            return;
        }
        for(int i = 0 ; i < s.length() ; i++) {
            if(taken[i] == 0) {
                permutation[index] = s.charAt(i);
                taken[i] = 1;
                permute(index + 1, s, permutation, taken);
                taken[i] = 0;   
            }
        }
    }
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    ArrayList<String> permutationsWithDups(String s) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        char permutation[] = new char[s.length()];
        int taken[] = new int[s.length()];
        for(int i = 0 ; i < s.length() ; i++) {
            taken[i] = 0;
        }
        ArrayList<String> answer = new ArrayList<String>();
        permute(0, s, permutation, taken);
        for(String i : distinct) {
            answer.add(i);
        }
        return answer;
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PermutationWithDups result = new PermutationWithDups();
        String s = scanner.next();
        scanner.close();
        ArrayList<String> answer = result.permutationsWithDups(s);
        for(int i = 0 ; i < answer.size() ; i++) {
            System.out.println(answer.get(i));
        }
    }
}
