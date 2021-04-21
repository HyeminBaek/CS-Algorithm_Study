package AL_CS_STUDY.RealTimeSolving.Weekly17;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Miro1 {
    static int n = 16;
    static int map[][];
    static int dy[] = {-1, 1, 0, 0};
    static int dx[] = {0, 0, -1, 1};

    static class Node {
        private int y, x;

        public Node(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "y=" + y +
                    ", x=" + x +
                    '}';
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T;
        T = 10;

        StringBuilder sb=new StringBuilder();
        Node start = null;
        Node end = null;
        for (int test_case = 1; test_case <= T; test_case++) {
            sc.nextInt();
            sc.nextLine();
            map = new int[16][16];
            for (int i = 0; i < 16; i++) {
                String str[] = sc.nextLine().split("");
                for (int j = 0; j < 16; j++) {
                    map[i][j] = Integer.parseInt(str[j]);
                    if (map[i][j] == 2)
                        start = new Node(i, j);
                    else if (map[i][j] == 3)
                        end = new Node(i, j);
                }
            }

            int ans = bfs(start, end);
//            System.out.println("ans : "+ans);
            sb.append("#" + test_case).append(" ").append(ans).append("\n");
        }
        System.out.println(sb);
    }

    static int bfs(Node start,Node end) {
        boolean visited[][]=new boolean[16][16];
        Queue<Node> q = new LinkedList<>();
        q.offer(start);
        visited[start.y][start.x]=true;
        while (!q.isEmpty())
        {
            Node cur=q.poll();
            if(cur.y==end.y && cur.x==end.x)
            {
                return 1;
            }
            for (int i = 0; i < 4; i++) {
                int ny=dy[i]+cur.y;
                int nx=dx[i]+cur.x;
                if(ny>=0 && nx >=0 && ny<16 && nx <16 && (map[ny][nx]==0 || map[ny][nx]==3) && !visited[ny][nx])
                {
                    visited[ny][nx]=true;
                    q.offer(new Node(ny,nx));
                }
            }
        }
        return 0;
    }
}
