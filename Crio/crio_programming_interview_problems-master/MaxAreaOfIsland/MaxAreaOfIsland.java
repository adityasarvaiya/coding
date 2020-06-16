import java.util.*;
import java.io.*;

class MaxAreaOfIsland{

    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        int n,m;

        n = sc.nextInt();
        m = sc.nextInt();
        
        ArrayList<ArrayList<Integer> > a = new ArrayList<ArrayList<Integer> >();
        for(int i=0;i<n;i++){
            ArrayList<Integer> b = new ArrayList<>();

            for(int j = 0;j<m;j++){
                b.add(sc.nextInt());
            }
            a.add(b);
        }

        int ans = MaxAreaOfIsland.maxAreaOfIsland(a);
        System.out.println(ans);
    }   

    public static int maxAreaOfIsland(ArrayList<ArrayList<Integer> > a){
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int n = a.size();
        if(n==0)return 0;
        int m=a.get(0).size();
        if(m==0)return 0;

        int ans = 0;

        boolean[][] vis = new boolean[n][m];

        int[] dir = {-1,0,1,0,-1};
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&a.get(i).get(j)==1){
                    Queue<Integer> q = new LinkedList<>();

                    q.add(i*m+j);
                    int area = 1;
                    vis[i][j]=true;

                    while(!q.isEmpty()){
                        int top = q.remove();
                        int x = top/m;
                        int y = top%m;

                        for(int k=0;k<4;k++){
                            int xx = x+dir[k];
                            int yy = y+dir[k+1];

                            if(xx>=0&&xx<n&&yy>=0&&yy<m&&a.get(xx).get(yy)==1){
                                if(!vis[xx][yy]){
                                    vis[xx][yy]=true;
                                    area+=1;
                                    q.add(xx*m+yy);
                                }
                            }

                        }

                    }
                    ans = Math.max(ans,area);   
                }
            }
        }



        return ans;

        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}
