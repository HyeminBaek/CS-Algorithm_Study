package AL_CS_STUDY.Weekly17;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class ExcellentVillage {
    static int n;
    static int village[];
    static int dp[][];
    static boolean visisted[];
    static ArrayList<ArrayList<Integer>> list=new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        village=new int[n+1];
        visisted=new boolean[n+1];
        dp=new int[n+1][2];
        StringTokenizer st=new StringTokenizer(br.readLine());
        for (int i = 1; i < n+1; i++) {
            list.add(new ArrayList<>());
            village[i]=Integer.parseInt(st.nextToken());
        }
        list.add(new ArrayList<>());

        for (int i = 0; i < n-1; i++) {
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            list.get(a).add(b);
            list.get(b).add(a);
        }
        dfs(1);
        System.out.println(Math.max(dp[1][0],dp[1][1]));
    }
    static void dfs(int cur)
    {
        if(visisted[cur])
            return;
        visisted[cur]=true;
        dp[cur][0]=0;
        dp[cur][1]=village[cur];

        for (Integer val : list.get(cur)) {
            if(visisted[val])
                continue;

            dfs(val);

            dp[cur][0]+=Math.max(dp[val][0],dp[val][1]);

            dp[cur][1]+=dp[val][0];
        }

    }
}
