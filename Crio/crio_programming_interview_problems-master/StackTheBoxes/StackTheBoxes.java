import java.util.*; 
//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class Triplet {
    int first,second,third;
    void initTriplet(int first,int second, int third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }
}
class TripletComparator implements Comparator<Triplet> { 
    public int compare(Triplet o1, Triplet o2) { 
          if(o1.first < o2.first) {
             return -1;
          } else {
            if(o1.first == o2.first) {
                if(o1.second < o2.second) {
                    return -1;
                } else {
                    if(o1.second == o2.second) {
                        if(o1.third < o2.third) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                return 1;
            }
          } 
    }  
}
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
public class StackTheBoxes {
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int findLisSum( ArrayList<Triplet> triplets , int n ) {
        int ans[] = new int[n];
        for(int i = n-1 ; i>= 0 ; i--) {
            ans[i] = 0;
            for(int j = i+1 ; j < n ; j++) {
                if(triplets.get(i).first < triplets.get(j).first && triplets.get(i).second < triplets.get(j).second && triplets.get(i).third < triplets.get(j).third) {
                    ans[i] = Math.max(ans[i], ans[j]);
                }
            }
            ans[i] += triplets.get(i).first;
        }
        int maxHeight = 0;
        for(int i = 0 ; i < n ;i++) {
            maxHeight = Math.max(maxHeight,ans[i]);
        }
        return maxHeight;
    }
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    int stackTheBoxes(int length[] , int breadth[] , int height[],int n) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        ArrayList<Triplet> triplets = new ArrayList<Triplet>();
        for(int i = 0 ; i < n ; i++) {
            Triplet temp = new Triplet();
            temp.initTriplet(height[i], breadth[i], length[i]);
            triplets.add(temp);
        }
        Collections.sort(triplets,new TripletComparator());
        int maxHeight = findLisSum(triplets, n);
        return maxHeight;  
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int length[] = new int[n];
        int breadth[] = new int[n];
        int height[] = new int[n];
        for(int i = 0 ; i < n ;i++) {
            length[i] = scanner.nextInt();
            breadth[i] = scanner.nextInt();
            height[i] = scanner.nextInt();
        }
        StackTheBoxes result = new StackTheBoxes();
        int answer = result.stackTheBoxes(length,breadth,height,n);
        System.out.println(answer);
        scanner.close();
    }
}