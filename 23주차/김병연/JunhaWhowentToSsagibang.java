package AL_CS_STUDY.Weekly23;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class JunhaWhowentToSsagibang {
    static class Person implements Comparable<Person> {
        private int start, end;

        public Person(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Person o) {
            if (start == o.start) {
                return end - o.end;
            }
            return start - o.start;
        }

        @Override
        public String toString() {
            return "Person{" +
                    "s=" + start +
                    ", e=" + end +
                    '}';
        }
    }
    static class Computer implements Comparable<Computer>
    {
        private int idx,endTime;

        public Computer(int idx, int endTime) {
            this.idx = idx;
            this.endTime = endTime;
        }

        @Override
        public int compareTo(Computer o) {
            return endTime-o.endTime;
        }
    }

    static int n;
    static Person p[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        p = new Person[n];
        for (int i = 0; i < n; i++) {
            String str[] = br.readLine().split(" ");
            p[i] = new Person(Integer.parseInt(str[0]), Integer.parseInt(str[1]));
        }
        System.out.println(Arrays.toString(p));
        Arrays.sort(p);
        System.out.println(Arrays.toString(p));
        int cnt[]=new int[100001];// 사용 횟수

        int idx=0;

        PriorityQueue<Computer> pq=new PriorityQueue<>();
        PriorityQueue<Integer> endTime=new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            while (!pq.isEmpty() && p[i].start >=pq.peek().endTime)
            {
                endTime.add(pq.poll().idx);
            }

            if(!endTime.isEmpty())
            {
                int pollValue = endTime.poll();
                cnt[pollValue]++;
                pq.offer(new Computer(pollValue,p[i].end));
            }
            else
            {
                cnt[idx]++;
                pq.offer(new Computer(idx++,p[i].end));
            }
        }
            StringBuilder sb=new StringBuilder();
        for (int i = 0; i < 100001; i++) {
            if(cnt[i]==0)
            {
                System.out.println(i);
                break;
            }
            sb.append(cnt[i]+" ");
        }
        System.out.println(sb);

    }

}
