package AL_CS_STUDY.RealTimeSolving.Weekly17;

import java.util.Scanner;

public class SubsequenceSum {
    static int n, k,arr[];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T;
        T=sc.nextInt();
        StringBuilder sb=new StringBuilder();
        for(int test_case = 1; test_case <= T; test_case++)
        {
            n=sc.nextInt();
            arr=new int[n];
            k =sc.nextInt();
            for (int i = 0; i < n; i++) {
                arr[i]=sc.nextInt();
            }
            pick(0,0);
            sb.append("#" + test_case).append(" ").append(cnt).append("\n");
            cnt=0;
        }
        System.out.println(sb);

    }
    static int cnt=0;
    static void  pick(int idx,int sum)
    {
        if(sum>k)
            return ;
        if(sum==k)
        {
            cnt++;
            return;
        }
        for (int i = idx; i <n ; i++) {
            pick(i+1,sum+arr[i]);
        }
    }
}
