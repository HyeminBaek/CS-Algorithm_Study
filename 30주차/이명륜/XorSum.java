import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        //pq나 treeMap쓰면 되겠다. pq가 더 나을듯
        int tc = Integer.parseInt(br.readLine());
        for (int tt = 0; tt < tc; tt++) {
            st = new StringTokenizer(br.readLine());
            int cmdCnt = Integer.parseInt(st.nextToken());
            int kElements = Integer.parseInt(st.nextToken());

            PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
            int xor = 0;

            for (int i = 0; i < cmdCnt; i++) {
                st = new StringTokenizer(br.readLine());
                String command = st.nextToken();

                if (command.equals("insert")) {
                    int number = Integer.parseInt(st.nextToken());
                    priorityQueue.add(number);
                    xor ^= number;
                    if (priorityQueue.size() > kElements) {
                        int minNumber = priorityQueue.poll();
                        xor ^= minNumber;
                    }
                } else {
                    System.out.println(xor);
                }

            }
        }
    }
}
