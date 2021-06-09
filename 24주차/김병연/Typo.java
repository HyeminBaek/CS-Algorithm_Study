package AL_CS_STUDY.Weekly24;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Typo {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String str[]=br.readLine().split("");

        int idx=0;
        int l=0;
        int r=0;
        int ans=0;
        for (int i = 0; i < str.length; i++) {
            if(str[i].charAt(0)=='(')
            {
                l++;
                idx++;
            }
            else
            {
                r++;
                idx--;
            }
            if(idx<=1)
                l=0;
            if(idx==-1)
            {
                ans=r;
                break;
            }
        }
        if(idx>0)
            ans=l;
        System.out.println(ans);

    }
}
