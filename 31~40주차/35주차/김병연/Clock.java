package AL_CS_STUDY.Weekly34;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Clock {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] c1 = new int[720_000];
        int[] c2 = new int[360_000];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int t = Integer.parseInt(st.nextToken());
            c1[t] = 1;
            c1[t + 360_000] = 1;
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            c2[Integer.parseInt(st.nextToken())] = 1;
        }

        String answer = kmp(c1, c2);
        System.out.println(answer);

    }

    public static String kmp(int[] originality, int[] pattern) {
        int pi[] = getPi(pattern);
        int j = 0;
        for (int i = 0; i < originality.length; i++) {
            while (j > 0 && originality[i] != pattern[j]) {
                j = pi[j - 1];
            }
            if (originality[i] == pattern[j]) {
                if (j == pattern.length - 1) {
                    return "possible";
                } else {
                    j++;
                }
            }
        }
        return "impossible";
    }

    public static int[] getPi(int[] pattern) {
        int[] pi = new int[pattern.length];
        int j = 0;
        for (int i = 1; i < pattern.length; i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = pi[j - 1];
            }
            if (pattern[i] == pattern[j])
                pi[i] = ++j;
        }
        return pi;
    }
}
