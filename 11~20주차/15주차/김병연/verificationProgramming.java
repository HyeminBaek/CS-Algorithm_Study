package AL_CS_STUDY.RealTimeSolving.Weekly15;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
// #36 NO
/*
1
4 5
..v..
...<@
^.>..
>..v.
* */
public class verificationProgramming {
    static int n;
    static int m;
    static char[][] arr;
    static int[] dy = {-1, 1, 0, 0};
    static int[] dx = {0, 0, -1, 1};
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            boolean flag ;
            String[] input = br.readLine().split(" ");
            n = Integer.parseInt(input[0]);
            m = Integer.parseInt(input[1]);
            arr = new char[n][m];
            for (int i = 0; i < n; i++) {
                String str = br.readLine();
                for (int j = 0; j < m; j++) {
                    arr[i][j] = str.charAt(j);
                }
            }
         flag=bfs(test_case);
            if(flag)
            {
                sb.append("#" + test_case).append(" ").append("YES").append("\n");
            }
            else
            {
                sb.append("#" + test_case).append(" ").append("NO").append("\n");
            }
        }
        System.out.println(sb);
    }

    public static boolean bfs(int TC) {
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(0, 0, 3, 0));
        boolean visited[][][][] =new boolean[21][21][4][16];
        visited[0][0][3][0]=true;
        while (!q.isEmpty()) {
            Node cur = q.poll();
            int y = cur.y;
            int x = cur.x;
            int mem = cur.memory;
            int dir=cur.d;
            if (arr[y][x] == '@') {
                return true ;
            }
            if (arr[y][x] >= '0' && arr[y][x] <= '9')
                mem = arr[y][x] - '0';
            else if (arr[y][x] == '>')
                dir = 3;
            else if (arr[y][x] == '<')
                dir = 2;
            else if (arr[y][x] == 'v')
                dir = 1;
            else if (arr[y][x] == '^')
                dir = 0;
            else if (arr[y][x] == '+')
                mem = mem == 15 ? 0 : mem + 1;
            else if (arr[y][x] == '-')
                mem = mem == 0 ? 15 : mem - 1;
            else if (arr[y][x] == '_')
                dir = mem == 0 ? 3 : 2;
            else if (arr[y][x] == '|')
                dir = mem == 0 ? 1 : 0;
            else if(arr[y][x]=='?')
            {
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if(ny==-1)
                        ny=n-1;
                    else if(ny==n)
                        ny=0;
                    if(nx==-1)
                        nx=m-1;
                    else if(nx==m)
                        nx=0;

                    //
                    if(!visited[ny][nx][i][mem]){
                        q.offer(new Node(ny,nx,i,mem));
                        visited[ny][nx][i][mem] = true;
                    }
                }
            }

            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny==-1)
                ny=n-1;
            else if(ny==n)
                ny=0;
            if(nx==-1)
                nx=m-1;
            else if(nx==m)
                nx=0;
            if(!visited[ny][nx][dir][mem]){
                q.offer(new Node(ny,nx,dir,mem));
                visited[ny][nx][dir][mem] = true;
            }
        }
        return false;
    }

    static class Node {
        private int y, x, d;
        int memory;

        public Node(int y, int x, int d, int memory) {
            this.y = y;
            this.x = x;
            this.d = d;
            this.memory = memory;
        }
    }
}
