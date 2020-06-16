import java.util.*;

public class BuildOrder {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int p = sc.nextInt();
        int d = sc.nextInt();
        
        sc.nextLine();
        ArrayList<String> project = new ArrayList<>();
        for(String val:sc.nextLine().split(" ")){
            // System.out.print(val+" ");
            project.add(val);
        }
        
        ArrayList<ArrayList<String> > dependencies = new ArrayList<>();
        for(int i=0;i<d;i++){
            ArrayList<String> dependency = new ArrayList<>();
            for(String dep:sc.nextLine().split(" ")){
                dependency.add(dep);
            }
            dependencies.add(dependency);
        }
        ArrayList<String> ans = buildOrder(project,dependencies);

        for(String proj:ans){
            System.out.print(proj+" ");
        }
        sc.close();
    }
    public static ArrayList<String> buildOrder(ArrayList<String> project,ArrayList<ArrayList<String> > dependencies){
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	    
        int n = project.size();
        ArrayList<ArrayList<Integer> > adj = new ArrayList<>();
        ArrayList<String> ans = new ArrayList<>();
        HashMap<String,Integer> projectToIndex = new HashMap<>();
        HashMap<Integer,String> indexToProject = new HashMap<>();
        ArrayList<Integer> deg = new ArrayList<>();
        for(int i =0;i<n;i++){
            projectToIndex.put(project.get(i),i);
            indexToProject.put(i,project.get(i));
            deg.add(0);
            adj.add(new ArrayList<>());
        }
        
        for(ArrayList<String> dependency:dependencies){
            int val = deg.get(projectToIndex.get(dependency.get(1)));
            deg.set(projectToIndex.get(dependency.get(1)),val+1);
            adj.get(projectToIndex.get(dependency.get(0))).add(projectToIndex.get(dependency.get(1)));
        }

        Queue<Integer> q = new LinkedList<>();

        for(int i=0;i<n;i++){
            if(deg.get(i)==0){
                q.add(i);
            }
        }

        while(!q.isEmpty()){
            int top = q.remove();
            ans.add(indexToProject.get(top));

            for(int child:adj.get(top)){
                deg.set(child,deg.get(child)-1);
                if(deg.get(child)==0){
                    q.add(child);
                }
            }
        }

        if(ans.size()<n){
            ans.clear();
            ans.add("-1");
        }

        
        return ans;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

}
