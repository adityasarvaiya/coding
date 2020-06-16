import java.util.*;
class Pair{
	int first,second;
    public Pair(int first,int second) {
        this.first = first;
        this.second = second;
    }
}
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class PairComparator implements Comparator<Pair> { 
    public int compare(Pair o1, Pair o2) { 
        if(o1.first>o2.first)
        	return -1;
        if(o1.first==o2.first)
        {
        	if(o1.second>o2.second)
        		return -1;
        	else
        		return 1;
        }
        else
        	return 1;
    }  
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
class CircusTower {
	public static int circusTower(Vector<Pair> vec)
	{
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		Collections.sort(vec, new PairComparator());
		int n=vec.size();
		int ans[] = new int[n];
        for(int i = n-1 ; i>= 0 ; i--) {
            ans[i] = 0;
            for(int j = i+1 ; j < n ; j++) {
                if(vec.get(j).first < vec.get(i).first && vec.get(j).second < vec.get(i).second) {
                    ans[i] = Math.max(ans[i], ans[j]);
                }
            }
            ans[i] ++;
        }
        int maxHeight = 0;
        for(int i = 0 ; i < n ;i++) {
            maxHeight = Math.max(maxHeight,ans[i]);
        }
        return maxHeight;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int n=sc.nextInt();
		int a ,b;
		Vector<Pair> vec=new Vector<Pair>();
		for ( int i = 0; i < n; i++) {
			a=sc.nextInt();
			b=sc.nextInt();
			Pair p=new Pair(a,b);
			vec.add(p);
		}
		System.out.println(circusTower(vec));
	}
}