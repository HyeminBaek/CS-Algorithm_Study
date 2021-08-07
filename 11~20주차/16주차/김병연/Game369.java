package AL_CS_STUDY.RealTimeSolving.Weekly16;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Game369 {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        Pattern pattern= Pattern.compile("[369]");
        String str;
        Matcher matcher;
        for (int i = 1; i <=n; i++) {
            matcher=pattern.matcher(String.valueOf(i));
            str="";
            while (matcher.find())
                str+="-";
            if(str.equals(""))
                System.out.print(i+" ");
            else
                System.out.print(str+" ");
        }
    }
}