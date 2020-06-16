import java.util.*;

//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class Pair{
	int first;
	String second;
	public Pair(int first,String second)
	{
		this.first=first;
		this.second=second;
	}
}
class PairComparator implements Comparator<Pair> { 
    public int compare(Pair o1, Pair o2) { 
        if(o1.first>o2.first)
        	return -1;
        if(o1.first==o2.first)
        {
        	if(o1.second.compareTo(o2.second)>0)
        		return 1;
        	else
        		return -1;
        }
        else
        	return 1;
    }  
}
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
class FrequentWords{
	public static Vector<String> frequentWords(Vector<String> vec,int k)
	{
               // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		
		int n=vec.size();
		Vector<Pair> a=new Vector<Pair>();
		HashMap<String,Integer> mp=new HashMap<String,Integer>();
		for(int i=0;i<n;i++)
		{
			if(mp.containsKey(vec.get(i)))
				mp.replace(vec.get(i),mp.get(vec.get(i))+1);
			else
				mp.put(vec.get(i),1);
		}
		for(Map.Entry<String,Integer> entry : mp.entrySet())  
        {
        	Pair p=new Pair(entry.getValue(),entry.getKey());
        	a.add(p);
        } 
        Collections.sort(a,new PairComparator());
        Vector<String> ans=new Vector<String>();
        for(int i=0;i<k;i++)
        	ans.add(a.get(i).second);
        return ans;
               // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		Vector<String> vec=new Vector<String>();
		for(int i=0;i<n;i++)
			vec.add(sc.next());
		int k=sc.nextInt();
		Vector<String> ans = frequentWords(vec, k);
		for(int i=0;i<k;i++)
			System.out.println(ans.get(i));
	}
}
