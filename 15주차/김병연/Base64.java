package AL_CS_STUDY.RealTimeSolving.Weekly15;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Base64 {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int T=Integer.parseInt(st.nextToken());
        for (int i = 1; i <=T ; i++) {
            String encode=br.readLine();
            String decode=new String(java.util.Base64.getDecoder().decode(encode));
            System.out.println("#"+i+" "+decode);
        }
    }
}
