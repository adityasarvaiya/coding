import java.util.*;

public class SparseSearch {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    Map<String , Integer>occurs;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    ArrayList<Integer> sparseSearch(String sparseArray[] , String queries[]) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        occurs = new HashMap<String,Integer>();
        for(int i = 0 ; i < sparseArray.length ; i++) {
            if(!(sparseArray[i].equals(""))) {
                occurs.put(sparseArray[i], i);
            }
        }
        ArrayList<Integer> answer = new ArrayList<Integer>();
        for(int i = 0 ; i < queries.length ; i++) {
            String target = queries[i];
            if(occurs.containsKey(target)) {
                answer.add(occurs.get(target));
            } else {
                answer.add(-1);
            }
        }
        return answer;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String sparseArray[] = new String[n];
        SparseSearch answer = new SparseSearch();
        for(int i = 0 ; i < n ; i++) {
            sparseArray[i] = scanner.next();
            if((sparseArray[i].equals("$"))) {
                sparseArray[i] = "";
            }
        }
        int q = scanner.nextInt();
        String queries[] = new String[q];
        for(int i = 0 ; i < q ; i++) {
            String target = scanner.next();
            queries[i] = target;
        }
        ArrayList<Integer> result = new SparseSearch().sparseSearch(sparseArray, queries);
        for(int i = 0 ; i < result.size(); ++i) {
            System.out.println(result.get(i));
        }
        scanner.close();
    }
}
