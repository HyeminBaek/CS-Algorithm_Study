package AL_CS_STUDY.Weekly16;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class FromSeoulToGyeongsan {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int k=Integer.parseInt(st.nextToken());
        int dp[][]=new int[101][100001];
        int a,b,c,d;
        for (int i = 1; i <=n; i++) {
            st=new StringTokenizer(br.readLine());
            a=Integer.parseInt(st.nextToken());
            b=Integer.parseInt(st.nextToken());
            c=Integer.parseInt(st.nextToken());
            d=Integer.parseInt(st.nextToken());
            if(i==1) {
                dp[i][a] = b;
                dp[i][c]=Math.max(dp[i][c],d);
            }
            else
            {
                for (int j = 0; j <=k; j++) {
                    if(dp[i-1][j]!=0)
                    {
                        if(j+a<=k)
                        {
                            dp[i][j+a]=Math.max(dp[i][j+a],dp[i-1][j]+b);
                        }
                        if(j+c<=k)
                        {
                            dp[i][j+c]=Math.max(dp[i][j+c],dp[i-1][j]+d);
                        }
                    }
                }
            }

        }

        int m=-1;
        for (int i = 1; i <=k; i++) {
            m=Math.max(m,dp[n][i]);
        }
        System.out.println(m);
    }
}
