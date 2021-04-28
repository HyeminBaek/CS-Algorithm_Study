package AL_CS_STUDY.Weekly18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Sebu  {
    static int n,m,s,e;
    static final int INF=Integer.MAX_VALUE;
    static ArrayList<Node> list[];
    static class Node implements Comparable<Node>
    {
        private int v, dist;

        public Node(int v, int dist) {
            this.v = v;
            this.dist = dist;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "v=" + v +
                    ", dist=" + dist +
                    '}';
        }

        @Override
        public int compareTo(Node o) {
            return o.dist-dist;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        list=new ArrayList[n+1];
        for (int i = 0; i < n+1; i++) {
            list[i]=new ArrayList<>();
        }


        st=new StringTokenizer(br.readLine());
        s=Integer.parseInt(st.nextToken());
        e=Integer.parseInt(st.nextToken());

        for (int i = 0; i < m; i++) {
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken()) ;
            int b=Integer.parseInt(st.nextToken()) ;
            int w=Integer.parseInt(st.nextToken()) ;
            list[a].add(new Node(b,w));
            list[b].add(new Node(a,w));
        }

//        for (int i = 0; i < n+1; i++) {
//            System.out.println(list[i]);
//        }
        boolean visited[]=new boolean[n+1];
        PriorityQueue<Node> pq=new PriorityQueue<>();
        pq.offer(new Node(s,0));

        int dTable[]=new int[n+1];
        dTable[s]=INF;
        while (!pq.isEmpty())
        {
            Node cur = pq.poll();
            if(visited[cur.v]) continue;
            visited[cur.v]=true;
            for (int i = 0; i < list[cur.v].size(); i++) {
                int vertax=list[cur.v].get(i).v;
                int dist=list[cur.v].get(i).dist;
                dTable[vertax]=Math.max(dTable[vertax],Math.min(dTable[cur.v],dist));
                pq.add(new Node(vertax,dist));
            }
        }

        System.out.println(dTable[e]);

    }

}
