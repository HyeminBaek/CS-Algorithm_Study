import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        //"주신 금액의 총 합은 100,000원을 넘지 않는다." 가 가장 큰 힌트같음
        // 금액으로 dp하면 될듯?

        final int max = 100100;

        for(int tt=0;tt<3;tt++){
            int n = Integer.parseInt(br.readLine());

            boolean[][] dp = new boolean[n+1][max];
            int[] arr = new int[n];
            int[] cnt = new int[n];
            int[] maxLimit = new int[n];
            int tot=0;

            for(int i=0;i<n;i++){
                st = new StringTokenizer(br.readLine());
                int value = Integer.parseInt(st.nextToken());
                int howmany = Integer.parseInt(st.nextToken());
                arr[i] = value;
                cnt[i] = howmany;
                tot+=arr[i]*cnt[i];
                maxLimit[i] = tot;
            }

            dp[0][0]=true;

            for(int i=0;i<n;i++){
                for(int j=0;j<max;j++){
                    if(dp[i][j]==false) continue;
                    int here = arr[i];
                    int howmany =  cnt[i];
                    for(int k=0;k<=howmany;k++){
                        if(j+here*k>=max) break;    //시간초과 방지
                        dp[i+1][j+here*k]=true;
                    }
                }
            }

            if(tot%2==1 || dp[n][tot/2]==false) System.out.println(0);
            else System.out.println(1);

//            for(int i=0;i<10;i++){
//                System.out.print(dp[n][i]+" ");
//            }
//            System.out.println();
        }

    }
}
