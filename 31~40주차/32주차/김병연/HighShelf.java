package AL_CS_STUDY.RealTimeSolving.Weekly32;

import java.io.*;
import java.util.StringTokenizer;

public class HighShelf {

    private static int min;
    private static int n;
    private static int b;
    private static int[] height;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int testCase = 1; testCase <= t; testCase++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            height = new int[n];
            st=new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                height[i]=Integer.parseInt(st.nextToken());
            }

            min = Integer.MAX_VALUE;
            dfs(0,0,0);
            int answer = min;
            sb.append("#").append(testCase).append(" ").append(answer).append("\n");
        }
        System.out.println(sb);
    }

    private static void dfs(int cnt, int idx, int sum) {
        if(cnt==n || sum>= b)
        {
            int val = sum - b;
            min = Math.min(val, HighShelf.min);
            return;
        }
        for (int i = idx; i <n ; i++) {
            dfs(cnt+1,i+1,sum+height[i]);
        }
    }


}
