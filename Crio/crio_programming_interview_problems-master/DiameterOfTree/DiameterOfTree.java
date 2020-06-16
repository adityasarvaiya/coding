import java.util.*;

class DiameterOfTree{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	private static Vector<Vector<Integer> > createAdjList(int n,Vector<Vector<Integer> > edges)
	{
		Vector<Vector<Integer> > adjList= new Vector<Vector<Integer> >();
		for(int i=0;i<=n;i++)
		{
			Vector<Integer> temp = new Vector<Integer>();
			adjList.add(temp);
		}
		for(int i=0;i<edges.size();i++)
		{
			adjList.get(edges.get(i).get(0)).add(edges.get(i).get(1));
			adjList.get(edges.get(i).get(1)).add(edges.get(i).get(0));
		}
		return adjList;
	}
	private static Vector<Integer> bfs(int n,int source,Vector<Vector<Integer> > vec)
	{
		Queue<Integer> q= new LinkedList<Integer>();
		int [] level = new int[n+1];
		q.add(source);
		level[source]=1;
		while(q.size()!=0)
		{
			int front = q.poll();
			for(int i=0;i<vec.get(front).size();i++)
			{
				if(level[vec.get(front).get(i)]==0)
				{
					level[vec.get(front).get(i)]=level[front]+1;
					q.add(vec.get(front).get(i));
				}
			}
		}
		Vector<Integer> ans = new Vector<Integer>();
		int maxLev=-1,index=-1;
		for(int i=1;i<=n;i++)
		{
			if(maxLev<level[i])
			{
				maxLev=level[i];
				index= i;
			}
		}
		ans.add(maxLev);
		ans.add(index);
		return ans;

	}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	private static int diameterOfTree(int n,Vector<Vector<Integer> > edges)
	{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		Vector<Vector<Integer> > vec = createAdjList(n,edges);
		Vector<Integer> source = bfs(n,1,vec);
		Vector<Integer> answer = bfs(n,source.get(1),vec);
		return answer.get(0)-1;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
		
	}
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int t= sc.nextInt();
		for(int test=0;test<t;test++)
		{
			int n=sc.nextInt();
			int m=sc.nextInt();
			Vector<Vector<Integer> > edges = new Vector<Vector<Integer> >();
			for(int i=0;i<m;i++)
			{
				int u=sc.nextInt();
				int v=sc.nextInt();
				Vector<Integer> edge = new Vector<Integer>();
				edge.add(u);
				edge.add(v);
				edges.add(edge);
			}
			System.out.println(diameterOfTree(n,edges));
		}
	}
}
