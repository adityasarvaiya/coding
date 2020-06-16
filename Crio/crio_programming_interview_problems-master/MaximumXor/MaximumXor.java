import java.util.*;

public class MaximumXor {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in); 
        int n;
        n = sc.nextInt();
        ArrayList<Integer> a = new ArrayList<>();
        for(int i=0;i<n;i++){
            a.add(sc.nextInt());
        }
        int ans = maximumXor(n,a);
        System.out.println(ans);
        sc.close();
    }
    public static int maximumXor(int n,ArrayList<Integer> a){
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        TrieNode root = new TrieNode();
        for(int i=0;i<n;i++){
            root.insert(a.get(i));
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = Math.max(ans,root.query(a.get(i)));
        }
        return ans;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }    
}

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class TrieNode{
    TrieNode[] bit = new TrieNode[2];


    TrieNode(){
        this.bit[0]=null;
        this.bit[1]=null;
    }

    void insert(int key){
        int[] numbits = new int[32];
        for(int i=0;i<32;i++){
            numbits[i]=key%2;
            key/=2;
        }

        TrieNode curr = this;
        for(int i=31;i>=0;i--){
            int b = numbits[i];
            if(curr.bit[b]==null){
                curr.bit[b]=new TrieNode();
            } 
            curr = curr.bit[b];
            key/=2;
        }

    }
    int query(int num){
        TrieNode curr = this;
        int ans = 0;
        int[] numbits = new int[32];
        for(int i=0;i<32;i++){
            numbits[i] = num%2;
            num/=2;
        }

        for(int i=31;i>=0;i--){
            int b = numbits[i];
            int val;
            if(b==0){
                if(curr.bit[1] == null){
                    val=0;
                }
                else val=1;  
            }
            else{
                if(curr.bit[0]==null){
                    val=1;
                }
                else{
                    val=0;
                }
            }
            curr = curr.bit[val];
            ans = ans*2+val^b;
            num/=2;
        }

        return ans;
    }
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS



