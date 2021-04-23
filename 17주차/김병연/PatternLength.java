package AL_CS_STUDY.RealTimeSolving.Weekly17;

import java.util.*;

public class PatternLength {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();
        sc.nextLine();
        StringBuilder sb = new StringBuilder();
        for (int test_case = 1; test_case <= T; test_case++) {
            String s=sc.nextLine();
            int i=0;
            int j=0;
            for (i = 1; i < s.length(); i++) {
                if(s.charAt(i)==s.charAt(j))
                    j++;
                else
                    j=0;
            }

            sb.append("#" + test_case).append(" ").append(i-j);
        }
        System.out.println(sb);
    }
}
