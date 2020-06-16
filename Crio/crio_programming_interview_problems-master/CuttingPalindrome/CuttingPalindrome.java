import java.util.*;

public class CuttingPalindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
        int ans = cuttingPalindrome(n,s);
        System.out.println(ans);
        sc.close();
    }
    static int cuttingPalindrome(int n,String s){
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int INT_MAX = 5000;
        ArrayList<ArrayList<Boolean> > isPalindrome = new ArrayList<>();
        ArrayList<Integer> cuts = new ArrayList<>(Collections.nCopies(n,INT_MAX));
        
        for(int i=0;i<n;i++){
            ArrayList<Boolean> b = new ArrayList<>(Collections.nCopies(n, false));
            isPalindrome.add(b); 
        }
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                isPalindrome.get(i).set(i,true);
            }
        }
        for(int l = 2;l<=n;l++){
            for(int i =0;i<n-l+1;i++){
                int j = i+l-1;
                if(l==2){
                    if(s.charAt(i)==s.charAt(j))
                        isPalindrome.get(i).set(j, true);
                }
                else{
                    if(s.charAt(i)==s.charAt(j)&&isPalindrome.get(i+1).get(j-1))
                        isPalindrome.get(i).set(j,true);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(isPalindrome.get(0).get(i))
                cuts.set(i,0);
            else{
                int minimumPreviousCuts = INT_MAX;
                for(int j = 0;j<i;j++){
                    if(isPalindrome.get(j+1).get(i)){
                        minimumPreviousCuts = Math.min(minimumPreviousCuts, cuts.get(j));
                    }
                }
                cuts.set(i, minimumPreviousCuts+1);
            }
        }

        return cuts.get(n-1);
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}
