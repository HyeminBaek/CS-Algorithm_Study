import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        int n = Integer.parseInt(br.readLine());
        List<int[]>[] tree = new ArrayList[n];
        for (int i = 0; i < n; i++) tree[i] = new ArrayList<>();

        List<int[]>[] adjList = new ArrayList[n];
        for (int i = 0; i < n; i++) adjList[i] = new ArrayList<>();

        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int parent = Integer.parseInt(st.nextToken()) - 1;
            int child = Integer.parseInt(st.nextToken()) - 1;
            int weight = Integer.parseInt(st.nextToken());

            tree[parent].add(new int[]{child, weight});

            adjList[parent].add(new int[]{child, weight});
            adjList[child].add(new int[]{parent, weight});
        }

        //step 1 : 루트에서 가장 거리가 먼 노드 알아내기.
        Queue<int[]> queue = new LinkedList<>();
        int[] minWeight = new int[n];
        for (int i = 0; i < n; i++) minWeight[i] = (int) 1e9;

        queue.add(new int[]{0, 0});
        minWeight[0] = 0;
        int maxWeightSum = 0;
        int maxWeightSumNode = 0;

        while (queue.isEmpty() == false) {
            int[] hereNode = queue.poll();
            int here = hereNode[0];
            int weight = hereNode[1];

            if (weight > maxWeightSum) {
                maxWeightSum = weight;
                maxWeightSumNode = here;
            }

            for (int[] nxtNode : tree[here]) {
                if (minWeight[nxtNode[0]] <= weight + nxtNode[1]) continue;

                queue.add(new int[]{nxtNode[0], weight + nxtNode[1]});
                minWeight[nxtNode[0]] = weight + nxtNode[1];
            }
        }

        // step 2: 찾은 노드로 트리를 재구성하자
        List<int[]>[] treeForDiameter = new ArrayList[n];
        for (int i = 0; i < n; i++) treeForDiameter[i] = new ArrayList<>();

        Queue<Integer> treeConstructor = new LinkedList<>();
        boolean[] visited = new boolean[n];
        visited[maxWeightSumNode] = true;
        treeConstructor.add(maxWeightSumNode);

        while (treeConstructor.isEmpty() == false) {
            int here = treeConstructor.poll();

            for (int[] nxtNode : adjList[here]) {
                if (visited[nxtNode[0]]) continue;
                treeForDiameter[here].add(nxtNode);

                treeConstructor.add(nxtNode[0]);
                visited[nxtNode[0]] = true;
            }
        }

        
        //step 3: 다시 한 번 bfs like (가중치가 있는 그래프니까 다익스트라라고 해야하나?)
        for (int i = 0; i < n; i++) minWeight[i] = (int) 1e9;
        queue.add(new int[]{maxWeightSumNode, 0});
        minWeight[maxWeightSumNode] = 0;
        int diameter = 0;

        while (queue.isEmpty() == false) {
            int[] hereNode = queue.poll();
            int here = hereNode[0];
            int weight = hereNode[1];

            diameter = Math.max(diameter, weight);

            for (int[] nxtNode : treeForDiameter[here]) {
                if (minWeight[nxtNode[0]] <= weight + nxtNode[1]) continue;

                queue.add(new int[]{nxtNode[0], weight + nxtNode[1]});
                minWeight[nxtNode[0]] = weight + nxtNode[1];
            }
        }

        System.out.println(diameter);
    }
}
