package AL_CS_STUDY.Weekly24;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class LogFile {

    static String logs[];
    static int levels[];
    static int dp[][];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q=Integer.parseInt(st.nextToken());
        logs=new String[n+1];
        levels=new int[n+1];
        dp=new int[n+1][7];
        for (int i = 1; i < n+1; i++) {
            st=new StringTokenizer(br.readLine(),"#");
            logs[i]=st.nextToken();
            levels[i]=Integer.parseInt(st.nextToken());
            for (int j = levels[i]; j >0 ; j--) {
                dp[i][j]++;
            }
        }

        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j <7 ; j++) {
                dp[i][j]+=dp[i-1][j];
            }
        }

        StringBuilder sb=new StringBuilder();
        for (int i = 0; i < q; i++) {
            st=new StringTokenizer(br.readLine(),"#");
            String start= st.nextToken();  ;
            String end=st.nextToken();    ;
            int lv=Integer.parseInt(st.nextToken());


            int lower=lowerBound(1,n+1,start);
            int upper=upperBound(1,n+1,end);
            int cnt=dp[upper-1][lv]-dp[lower-1][lv];
            sb.append(cnt+"\n");
        }
        System.out.print(sb);
    }
    static int lowerBound(int l,int r,String target)
    {
        while (l<r)
        {
            int mid=(l+r)/2;
            if(target.compareTo(logs[mid])<=0)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return r;
    }
    static int upperBound(int l,int r,String target) {
        while (l < r)
        {
            int mid=(l+r)/2;
            if(target.compareTo(logs[mid])>=0)
            {
                l=mid+1;
            }
            else
                r=mid;
        }
        return r;
        }
}
