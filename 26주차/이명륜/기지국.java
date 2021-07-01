import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

//어떻게 푸냐... dp같긴 한데...........
//일단 r값으로 필요한 최소한의 통신범위를 알 수 있음
//연속적으로 묶이기 때문에 c값을 통해 인접한 것과 함께 처리될 수 있는지 여부를 따질 수 있긴한데..
// 연속된 것들을 적절히 그룹 나누는 냅색으로 풀릴거 같긴 함
// 기존 그룹에 포함시키느냐 / 새로운 그룹으로 시작하느냐에 따른 비용

///////////////////////////////////////////////////////////////////
// 그게 아니라
// LIS처럼  현재 위치보다 앞에있는 모든 것들에 대해 최적을 따져보는 식으로


public class Main {
    static int n;
    static List<int[]> infos = new ArrayList<>();
    static int[] dp;

    private static int solve(int idx){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        dp[idx]=(int)1e9;

        int[] hereInfo = infos.get(idx);
        int maxRow = hereInfo[1];

        for(int next = idx;next<n;next++){
            int[] nextInfo = infos.get(next);

            int colDiff = nextInfo[0] - hereInfo[0];
            maxRow = Math.max(maxRow,nextInfo[1]);
            int cost = Math.max(colDiff,maxRow);

            dp[idx] = Math.min(dp[idx],cost + solve(next+1));
        }

        return dp[idx];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        n= Integer.parseInt(br.readLine());
        dp= new int[n];

        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            int col = Integer.parseInt(st.nextToken());
            int row = Math.abs(Integer.parseInt(st.nextToken()));
            infos.add(new int[]{col,row*2});
        }

        infos.sort((x, y)->Integer.compare(x[0],y[0]));
        
        for(int i=0;i<n;i++) dp[i] = -1;

        System.out.println(solve(0));
//        for(int i=0;i<n;i++) System.out.print(dp[i]+" ");

    }
}

