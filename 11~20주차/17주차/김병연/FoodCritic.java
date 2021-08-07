package AL_CS_STUDY.Weekly17;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class FoodCritic {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        int ans=0;
        if(n>m)
        {
            ans = gcd(n, m);
        }
        else {
            ans=gcd(m, n);
        }
        System.out.println(m-ans);

    }
    static int gcd(int a,int b)
    {
        while (b!=0)
        {
            int temp=a;
            a=b;
            b=temp%b;
        }
        return a;
    }
}
