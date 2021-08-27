package AL_CS_STUDY.Weekly34;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class TrunkOfTreeAndBranch {
    static class Node {
        private int vertex, edge;

        public Node(int vertex, int edge) {
            this.vertex = vertex;
            this.edge = edge;
        }
    }

    static List<Node> list[];
    static boolean v[];
    static int n = 0, root = 0;
    static int longestBranchLen = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        root = Integer.parseInt(st.nextToken());
        list = new List[n + 1];
        v = new boolean[n + 1];
        for (int i = 1; i < n + 1; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            list[a].add(new Node(b, w));
            list[b].add(new Node(a, w));
        }
        int[] trunk = findTrunk(root, 0);
        int gigaNode = trunk[0];
        int trunkToGigaNodeDistance = trunk[1];
        findLeaf(gigaNode, 0);
        System.out.println(trunkToGigaNodeDistance+" "+longestBranchLen);

    }


    private static void findLeaf(int cur, int branchLen) {
        v[cur] = true;
        if (list[cur].size() == 1) {
            longestBranchLen = Math.max(longestBranchLen, branchLen);
        }
        for (Node node : list[cur]) {
            int nextVertex = node.vertex;
            int nextEdge = node.edge;
            if (!v[nextVertex]) {
                findLeaf(nextVertex, branchLen+nextEdge);
            }
        }

    }

    private static int[] findTrunk(int cur, int edge) {
        v[cur] = true;
        if (list[cur].size() > 2)
            return new int[]{cur, edge};
        if (list[root].size() == 2)
            return new int[]{cur, edge};
        for (Node node : list[cur]) {
            int nextVertex = node.vertex;
            int nextEdge = node.edge;
            if (!v[nextVertex]) {
                return findTrunk(nextVertex, edge + nextEdge);
            }
        }
        return new int[]{cur, edge};
    }
}
