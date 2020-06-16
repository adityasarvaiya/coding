import java.util.*;

class MissingRanges{
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	static int removeDuplicates(int arr[], int n) 
    { 
        if (n==0 || n==1) 
            return n;  
        int[] temp = new int[n]; 
        int j = 0; 
        for (int i=0; i<n-1; i++) 
            if (arr[i] != arr[i+1]) 
                temp[j++] = arr[i]; 
          
        temp[j++] = arr[n-1];    
        for (int i=0; i<j; i++) 
            arr[i] = temp[i]; 

        return j; 
	} 
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS	
	public static Vector<String> findMissingRanges(int n,int lower,int upper,int [] nums)
	{
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		Vector<String> ans=new Vector<String>();
		if(n==0)
		{
			if(lower==upper)
			{
				ans.add(Integer.toString(lower));
			}
			else
			{
				String s=lower+"->"+upper;
				ans.add(s);
			}

		}
		else
		{
			int sizeOfNewNums=removeDuplicates(nums,n);
			int prev=lower-1,flag=0;
			for(int i=0;i<sizeOfNewNums;i++)
			{
				if(nums[i]<lower)
				{	
					i++;
					continue;
				}
				else if(nums[i]>upper)
				{
					if(flag==0)
					{
						String s=prev+1+"->"+upper;
						ans.add(s);
						flag=1;
					}
					break;
				}
				else
				{
					if(prev!=(nums[i]-1))
					{
						String s;
						if(prev+1==nums[i]-1)
						{
							ans.add(Integer.toString(prev+1));
						}	
						else
						{
							int temp=nums[i]-1;
							s=prev+1+"->"+temp;
							ans.add(s);
						}
					}
					prev=nums[i];
					if(nums[i]==upper)
						flag=1;
				}
			}
			if(nums[sizeOfNewNums-1]<upper && nums[sizeOfNewNums-1]>=lower && flag==0)
			{
				int temp=nums[sizeOfNewNums-1]+1;
				if(temp==upper)
					ans.add(Integer.toString(temp));
				else
				{
					String s=temp+"->"+upper;
					ans.add(s);
				}
			}
		}
		return ans;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String [] args)
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int lower=sc.nextInt(),upper=sc.nextInt();
		int [] nums=new int [n];
		for(int i=0;i<n;i++)
		{
			nums[i]=sc.nextInt();
		}
		Vector<String> answer=findMissingRanges(n,lower,upper,nums);
		for(int i=0;i<answer.size();i++)
		{
			System.out.println(answer.get(i));
		}
	}
}
