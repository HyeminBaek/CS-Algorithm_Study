import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());

        int[] inDegree = new int[n+1];
        List<Integer>[] DAG = new ArrayList[n+1];
        for(int i=0;i<=n;i++) DAG[i] = new ArrayList<>();

        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int from  =Integer.parseInt(st.nextToken());
            int to =Integer.parseInt(st.nextToken());
            inDegree[to]++;
            DAG[from].add(to);
        }

        Queue<Node> q = new LinkedList<>();

        for(int i=1;i<=n;i++){
            if(inDegree[i]==0) q.add(new Node(i,1));
        }

        int[] answer = new int[n+1];

        while(q.isEmpty()==false){
            Node hereNode = q.poll();
            int here=hereNode.node;
            int depth=hereNode.depth;

            answer[here]=depth;

            for(int nxt:DAG[here]){
                inDegree[nxt]--;
                if(inDegree[nxt]==0) q.add(new Node(nxt,depth+1));
            }
        }

        for(int i=1;i<=n;i++) System.out.print(answer[i]+" ");

    }

    static class Node{
        int node,depth;
        public Node(int node,int depth){
            this.node=node;
            this.depth=depth;
        }
    }
}
