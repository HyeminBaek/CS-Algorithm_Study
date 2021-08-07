package AL_CS_STUDY.Weekly32;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
// ref . https://suhyeokeee.tistory.com/115 , https://withhamit.tistory.com/246

public class TSP {
    static final int INF = (int) 1e9;
    private static int n;
    private static int[][] arr;
    private static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        dp = new int[n][(1 << n) - 1];

        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], INF);
        }

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int val = Integer.parseInt(st.nextToken());
                arr[i][j] = val;
            }
        }
        System.out.println(tsp(0, 1));

    }

    private static int tsp(int vertax, int v) { // 현재 위치 , 비트마스킹 번호
        if (v == (1 << n) - 1) {
            if (arr[vertax][0] == 0) {
                return INF;
            }
            return arr[vertax][0];
        }
        if(dp[vertax][v]!=INF)
        {
            return dp[vertax][v];
        }
        for (int i = 0; i < n; i++) {
            int next=v | (1<<i); // i번쨰 도시 방문.
            if(arr[vertax][i]==0 || (v &(1<<i))!=0)
                continue;
            dp[vertax][v]=Math.min(dp[vertax][v],tsp(i,next)+arr[vertax][i]);
        }

        return dp[vertax][v];
    }
}
