import java.util.*;

class TopologicalOrdering{
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	private static Stack<Integer> st = new Stack<Integer>();
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
		}
		return adjList;
	}
	private static void topoSort(int node,Vector<Vector<Integer> > vec, int [] visited )
	{
		for(int i=0;i<vec.get(node).size();i++)
		{
			if(visited[vec.get(node).get(i)] == 0)
			{
				visited[vec.get(node).get(i)] =1;
				topoSort(vec.get(node).get(i),vec,visited);
			}
		}
		st.push(node);
	}
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	private static Vector<Integer> topologicalOrdering(int n,Vector<Vector<Integer> > edges)
	{
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		Vector<Vector<Integer> > vec = createAdjList(n,edges);
		int [] visited = new int [n+1];
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==0)
			{
				visited[i]=1;
				topoSort(i,vec,visited);
			}
		}
		Vector<Integer> answer = new Vector<Integer>();
		while(st.empty() == false)
		{
			answer.add(st.pop());
		}
		return answer;
                // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int e = sc.nextInt();
		Vector<Vector<Integer> > edges = new Vector<Vector<Integer> >();
		for(int i=0;i<e;i++)
		{
			int u=sc.nextInt();
			int v=sc.nextInt();
			Vector<Integer> edge = new Vector<Integer>();
			edge.add(u);
			edge.add(v);
			edges.add(edge);
		}
		Vector<Integer> answer = topologicalOrdering(n,edges);
		for(int elem : answer)
			System.out.print(elem+" ");
	}
}
