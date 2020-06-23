import java.util.*;
class FirstUniqueInteger{
	public static int firstUniqueInteger(Vector<Integer> vec)
	{
                // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int n=vec.size();
		HashMap<Integer,Integer> mp=new HashMap<Integer,Integer>();    
		for(int i=0;i<n;i++)
		{
			if(mp.containsKey(vec.get(i)))
				mp.replace(vec.get(i),mp.get(vec.get(i))+1);
			else
				mp.put(vec.get(i),1);
		}
		for(int i=0;i<n;i++)
		{
			if(mp.get(vec.get(i))==1)
				return vec.get(i);
		}
		return -1;
                // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		Vector<Integer> vec=new Vector<Integer>();
		for(int i=0;i<n;i++)
			vec.add(sc.nextInt());
		System.out.println(firstUniqueInteger(vec));
	}
}
