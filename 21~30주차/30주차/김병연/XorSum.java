package AL_CS_STUDY.Weekly30;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
// https://www.acmicpc.net/problem/11338
public class XorSum {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int testCase = Integer.parseInt(st.nextToken());
        while (testCase-- > 0) {
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int answer = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                String str[] = br.readLine().split(" ");
                if (str.length == 2) {
                    int value = Integer.parseInt(str[1]);
                    pq.offer(value);
                    answer ^= value;
                    cnt++;
                    if (cnt > k) {
                        if (!pq.isEmpty())
                            answer ^= (pq.poll());
                    }
                } else
                    System.out.println(answer);
            }
        }
    }
}
