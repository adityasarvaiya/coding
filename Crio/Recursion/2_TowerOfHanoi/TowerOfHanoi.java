import java.util.*;

public class TowerOfHanoi {
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    ArrayList<String> answer;
    void move(int n, char from,char to, char temp) { 
        if(n == 1) { 
            String res = n + " " + from + " " + to;
            answer.add(res);
            return; 
        } 
        move(n - 1, from, temp, to); 
        String res = n + " " + from + " " + to;
        answer.add(res); 
        move(n - 1, temp, to, from); 
        return;
    }
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    ArrayList<String> towerOfHanoi(int n) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        answer = new ArrayList<>();
        move(n, 'A', 'C', 'B');
        return answer;
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<String> result = new TowerOfHanoi().towerOfHanoi(n);
        for(int i = 0 ; i < result.size() ; i++) {
            System.out.println(result.get(i));
        }
    }
}
