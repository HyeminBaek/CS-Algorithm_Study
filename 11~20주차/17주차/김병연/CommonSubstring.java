package AL_CS_STUDY.Weekly17;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class CommonSubstring {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        char[] s1=br.readLine().toCharArray();
        char[] s2=br.readLine().toCharArray();
        int dp[][]=new int[s1.length+1][s2.length+1];
        int max=0;
        for (int i = 1; i <=s1.length; i++) {
            for (int j = 1; j <= s2.length; j++) {
                {
                    if(s1[i-1]==s2[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1]+1;
                        max= Math.max(dp[i][j],max);
                    }
                }
            }
        }

        for (int i = 0; i <s1.length ; i++) {
            System.out.println(Arrays.toString(dp[i]));

        }
        System.out.println(max);
    }
}