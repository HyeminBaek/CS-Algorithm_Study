import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//전형적인 dp같은데
// m=0일 때는 입력이 없는데 StringTokenizer로 입력받아서 nullPointer exception 발생하였음.

public class Main{
    static boolean[] days;
    static int[][] dp;
    static int n;

    private static int solve(int day,int coupon){
        if(day>n) return 0;
        if(dp[day][coupon]!=-1) return dp[day][coupon];

        dp[day][coupon]=(int)1e9;
        if(days[day]) dp[day][coupon]=Math.min(dp[day][coupon],solve(day+1,coupon));

        //쿠폰 사용 안함
            //하루 이용권
        dp[day][coupon] = Math.min(dp[day][coupon],solve(day+1,coupon)+10000);

            //연속 3일 이용권
        for(int i=0;i<3;i++){
//            if(day+i>n) break;
            if(day+i>n) break;
            dp[day][coupon] = Math.min(dp[day][coupon],solve(day+i+1,coupon+1)+25000);
        }

        for(int i=0;i<5;i++){
//            if(day+i>n) break;
            if(day+i>n) break;
            dp[day][coupon] = Math.min(dp[day][coupon],solve(day+i+1,coupon+2)+37000);
        }

        //쿠폰 사용
            //하루 이용권
        if(coupon>=3)
            dp[day][coupon] = Math.min(dp[day][coupon],solve(day+1,coupon-3));


        return dp[day][coupon];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

      
        st = new StringTokenizer(br.readLine());
        n= Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        days = new boolean[n+2];
        if(m!=0){
            st = new StringTokenizer(br.readLine());
            for(int i=0;i<m;i++) {
                days[Integer.parseInt(st.nextToken())]=true;
            }
        }
      

        dp = new int[110][250];
        for(int i=0;i<110;i++) for(int j=0;j<250;j++) dp[i][j]=-1;

        System.out.println(solve(1,0));

    }
}
