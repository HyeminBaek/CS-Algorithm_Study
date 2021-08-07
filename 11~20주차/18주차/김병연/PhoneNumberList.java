package AL_CS_STUDY.Weekly18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class PhoneNumberList {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(br.readLine());
        StringBuilder sb=new StringBuilder();
        while (T-->0)
        {
            int n=Integer.parseInt(br.readLine());
            ArrayList<String> arr=new ArrayList<>();
            for (int i = 0; i < n; i++) {
                arr.add(br.readLine());
            }
            Collections.sort(arr);
            System.out.println(arr);
            boolean flag=true;
            for (int i = 0; i <arr.size()-1; i++) {
                    if(arr.get(i+1).startsWith(arr.get(i))) {
                        flag = false;
                        break;
                    }
                }
            if(!flag)
                sb.append("NO\n");
            else
                sb.append("YES\n");
        }
        System.out.println(sb);
    }
}
