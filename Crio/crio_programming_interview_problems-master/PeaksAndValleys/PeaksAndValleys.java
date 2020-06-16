import java.util.*;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class PeaksAndValleys{

	public static void main(String [] args)
	{
		Solution so=new Solution();
		so.readInput();
		int answer[]=so.solve();
		for(int i=1;i<answer.length;i++)
		{
			System.out.print(answer[i]+" ");
		}
	}
}
