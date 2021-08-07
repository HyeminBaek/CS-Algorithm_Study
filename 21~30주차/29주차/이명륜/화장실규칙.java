    import java.io.*;
    import java.util.*;

    public class Main{
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer("");

            //그냥 시뮬하면 안될테고 ( 매번 검사를 m번 해야 하니까 시간초과)
            //가장 최앞단의 정보를 기억하고 있으면 되겠다
            //그리고 가장 최앞단에서 빠지는 줄의 번호로 그 줄 맨 앞을 빼주고
            //deque쓰면 되겠네. 큐도 되겠지만

            st = new StringTokenizer(br.readLine());
            int n=Integer.parseInt(st.nextToken());
            int m=Integer.parseInt(st.nextToken());
            int k=Integer.parseInt(st.nextToken());

            Deque<Info>[] deque = new ArrayDeque[m];
            for(int i=0;i<m;i++) deque[i] = new ArrayDeque<>();
            int colIdx=0;

            for(int i=0;i<n;i++){
                st = new StringTokenizer(br.readLine());
                int d=Integer.parseInt(st.nextToken());
                int h=Integer.parseInt(st.nextToken());

                Info info =new Info(i,d,h);

                info.col=colIdx;
                deque[colIdx].add(info);
                colIdx++;
                colIdx%=m;
            }

            PriorityQueue<Info> pq = new PriorityQueue<>();
            for(int i=0;i<Math.min(m,n);i++){
                pq.add(deque[i].getFirst());
            }

            // 가장 우선순위 높은 사람 빼내고
            // 그 빼낸 줄의 젤 앞을 제거해주고
            // 그 빼낸 줄에서 새롭게 젤 앞에 온 사람이 있으면 pq에 넣어주고

            int answer=0;
            for(int i=0;i<n;i++){
                Info first = pq.poll();
                int col=first.col;
                int sequence = first.sequence;

                if(sequence==k){
                    answer=i;
                    break;
                }

                deque[col].pollFirst();

                if(deque[col].isEmpty()) continue;

                pq.add(deque[col].getFirst());
            }

            System.out.println(answer);
        }

        static class Info implements Comparable<Info>{
            int sequence,day,hurry,col;
            public Info(int sequence,int day,int hurry){
                this.sequence=sequence;
                this.day=day;
                this.hurry=hurry;
            }

            @Override
            public int compareTo(Info other) {
                if(this.day!= other.day) return -(this.day-other.day);
                else{
                    if(this.hurry!=other.hurry) return -(this.hurry-other.hurry);
                    else {
                        return this.col-other.col;
                    }
                }
            }
        }
    }
