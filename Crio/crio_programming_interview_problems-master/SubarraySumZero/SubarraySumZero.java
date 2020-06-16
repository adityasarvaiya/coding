import java.util.*;

class SubarraySumZero{
	public static String subarraySumZero(Vector<Integer> arr)
 	{
                // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int n=arr.size();
		int sum=0;
		HashMap<Integer,Integer> mp=new HashMap<Integer,Integer>();
		mp.put(0,1);
		for(int i=0;i<n;i++)
		{
			sum+=arr.get(i);
			if(mp.containsKey(sum))
				return "Yes";
			else
				mp.put(sum,1);
		}
		return "No";
                // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int j=0;j<t;j++)
		{
			int n=sc.nextInt();
			Vector<Integer> arr=new Vector<Integer>();
			for(int i=0;i<n;i++)
			{
				arr.add(sc.nextInt());
			}
			System.out.println(subarraySumZero(arr));
		}

	}
}
