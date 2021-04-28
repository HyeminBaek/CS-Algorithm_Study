package AL_CS_STUDY.Weekly18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class RemainderSum {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st=new StringTokenizer(br.readLine());

        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());

        long s[]=new long[n+1];
        long mod[]=new long[m];

        long cnt=0;
        st=new StringTokenizer(br.readLine());
        for (int i = 1; i < n+1; i++) {
            long num=Long.parseLong(st.nextToken());
            s[i]=s[i-1]+num;
            if(s[i]%m==0)
                cnt++;
            mod[(int) (s[i]%m)]+=1;
        }
//        System.out.println(Arrays.toString(mod));
        for (int i = 0; i < m; i++) {
            cnt+=mod[i]*(mod[i]-1)/2;
        }
        System.out.println(cnt);

    }
}
