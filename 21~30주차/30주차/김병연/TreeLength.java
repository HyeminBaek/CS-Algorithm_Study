package AL_CS_STUDY.Weekly30;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
//https://www.acmicpc.net/problem/1967
public class TreeLength {
    static class Node implements Comparable<Node> {
        private int idx, weight;

        public Node(int idx, int weight) {
            this.idx = idx;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return weight - o.weight;
        }
    }

    static ArrayList<Node> list[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        list = new ArrayList[n + 1];
        for (int i = 1; i < n + 1; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int v1 = Integer.parseInt(st.nextToken());
            int v2 = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            list[v1].add(new Node(v2, cost));
            list[v2].add(new Node(v1, cost));
        }
        int farDistVertax = dijkstra(1, n).idx;
        Node restVertax = dijkstra(farDistVertax, n);
        System.out.println(restVertax.weight);

    }

    static int INF = (int) 1e9;

    static Node dijkstra(int start, int size) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        int dist[] = new int[size + 1];
        Arrays.fill(dist, INF);
        dist[start] = 0;
        pq.offer(new Node(start, 0));
        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            if (dist[cur.idx] < cur.weight)
                continue;
            for (Node node : list[cur.idx]) {
                int cost = dist[cur.idx] + node.weight;
                if (cost < dist[node.idx]) {
                    dist[node.idx] = cost;
                    pq.offer(new Node(node.idx, cost));
                }
            }
        }
        int idx = -1;
        int max = -1;
        for (int i = 1; i < size + 1; i++) {
            if (dist[i] > max) {
                max = dist[i];
                idx = i;
            }
        }
        return new Node(idx, max);
    }
}
