
import java.util.*; 

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

public class CountOfSmallerNumbersAfterSelf{ 
	public static void main(String[] args) 
	{  
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int [] arr=new int[n];
		for(int i=0;i<n;i++)
			arr[i]=sc.nextInt();	 
		Solution so = new Solution(); 
		ArrayList<Integer> countList = so.countOfSmallerNumberAfterSelf(arr); 
		for (Integer i : countList) 
			System.out.print(i + " "); 
	} 
} 
