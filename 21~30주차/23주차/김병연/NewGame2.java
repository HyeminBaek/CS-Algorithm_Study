package AL_CS_STUDY.Weekly23;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class NewGame2 {
    static int n, k;
    static int dy[] = {0, 1, 0, -1};
    static int dx[] = {1, 0, -1, 0};
    static LinkedList<Integer> map[][];
    static int colors[][];
    static Node horses[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        map = new LinkedList[n][n];
        colors = new int[n][n];
        horses=new Node[k];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = new LinkedList<>();
                colors[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int y = Integer.parseInt(st.nextToken()) - 1;
            int x = Integer.parseInt(st.nextToken()) - 1;
            int d = Integer.parseInt(st.nextToken());
            if(d==1)
                d=0;
            else if(d==4)
                d=1;

            horses[i] = new Node(i, y, x, d);
            map[y][x].add(i);
        }

        int time = play();
        System.out.println(time);

    }

    static int play() {
        for (int t = 1; t <= 1000; t++) {
            for (int j = 0; j < k; j++) {
                Node horse = horses[j];
                int idx=orderSearch(j, horses[j].y, horses[j].x);

                int ny=dy[horse.d]+horse.y;
                int nx=dx[horse.d]+horse.x;
                if(ny<0 || nx<0 || nx>=n || ny>=n || colors[ny][nx]==2)
                {
                    horse.setD((horse.d+2)%4);
                    ny=dy[horse.d]+ horse.y;
                    nx=dx[horse.d]+ horse.x;
                    if (ny < 0 || nx < 0 || ny >= n || nx >= n ||colors[ny][nx] == 2) {
                        continue;
                    }
                }
                if(move(horse.y,horse.x,ny,nx,idx,colors[ny][nx]))
                {
                    return t;
                }
            }
        }
        return -1;
    }

    private static boolean move(int y, int x, int ny, int nx, int idx, int colorVal) {
//        A번 말의 위에 다른 말이 있는 경우에는 A번 말과 위에 있는 모든 말이 이동한다.
        while (map[y][x].size()>idx)
        {
            int temp=-1;
            if(colorVal==0)
            {
                temp=map[y][x].remove(idx);
            }
            else
            {
                temp=map[y][x].removeLast();
            }

            horses[temp].setY(ny);
            horses[temp].setX(nx);
            map[ny][nx].add(temp);
        }
        if(map[ny][nx].size()>=4)
            return true;
        return false;
    }

    private static int orderSearch(int k, int y, int x) {
        for (int i = 0; i < map[y][x].size(); i++) {
            if(map[y][x].get(i)==k)
                return i;
        }
        return -1;
    }

    static class Node {
        private int id, y, x, d;

        public Node(int id, int y, int x, int d) {
            this.id = id;
            this.y = y;
            this.x = x;
            this.d = d;
        }

        public void setD(int d) {
            this.d = d;
        }

        public void setY(int y) {
            this.y = y;
        }

        public void setX(int x) {
            this.x = x;
        }
    }

}
