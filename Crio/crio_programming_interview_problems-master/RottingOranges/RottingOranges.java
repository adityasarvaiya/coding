import java.util.*;

class RottingOranges{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while((t--)>0){
            int n,m;
            n= sc.nextInt();
            m=sc.nextInt();
            ArrayList<ArrayList<Integer> > a = new ArrayList<ArrayList<Integer> >();
            for(int i=0;i<n;i++){
                a.add(new ArrayList<Integer>());
            }
            for(int i=0;i<n;i++){
                for(int j = 0;j<m;j++){
                    a.get(i).add(sc.nextInt());
                }
            }
            int ans  = RottingOranges.rottingOranges(a);
            System.out.println(ans);
        }
        sc.close();
    }
    public static int rottingOranges(ArrayList<ArrayList<Integer> > a){
            // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            int n = a.size();
            if(n==0)return 0;
            int m = a.get(0).size();
            if(m==0)return 0;
            Queue<Integer> q = new LinkedList<>();
            int cnt = 0;
            for(int i=0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(a.get(i).get(j)==2){
                        q.add(i*m+j);
                    }
                    else if(a.get(i).get(j)==1){
                        cnt++;
                    }
                }
            }
            int ans =0;
            int[] dir = {-1,0,1,0,-1};
            Queue<Integer> temp = new LinkedList<>();
            while(true){
                while(!q.isEmpty()){
                    int top = q.remove();
                    int topx = top/m;
                    int topy = top%m;
                    for(int i=0;i<4;i++){
                        int x = topx+dir[i];
                        int y = topy+dir[i+1];

                        if(x>=0&&x<n&&y>=0&&y<m&&a.get(x).get(y)==1){
                            cnt--;
                            a.get(x).set(y,2);
                            temp.add(x*m+y);
                        }
                    }
                    
                }
                if(temp.size()==0){
                    break;
                }
                else{
                    ans++;
                    q = temp;
                    temp =  new LinkedList<>();
                }

            }
            if(cnt==0){
                return ans;
            }
            else return -1;
            // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        }
}
