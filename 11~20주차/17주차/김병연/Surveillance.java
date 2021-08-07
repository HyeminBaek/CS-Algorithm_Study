package AL_CS_STUDY.Weekly17;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Surveillance {
    static int n, m;
    static char office[][];
    static int dy[] = {-1, 1, 0, 0};
    static int dx[] = {0, 0, -1, 1};
    static ArrayList<Node> cctv=new ArrayList<Node>();
    static class Node{
        private int y,x,dir;

        public Node(int y, int x, int dir) {
            this.y = y;
            this.x = x;
            this.dir = dir;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        office=new char[n][m];
        for (int i = 0; i < n; i++) {
            String str[]=br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                office[i][j]=str[j].charAt(0);
                if(office[i][j]!='#' && office[i][j]!='0'&& office[i][j]!='6')
                {
                    cctv.add(new Node(i,j,office[i][j]-'0'));
                }
            }
        }
        watch(0,office);
        System.out.println(maxZero);
    }
    static int maxZero=Integer.MAX_VALUE;
    static void watch(int cnt,char middle[][])
    {
        if (cnt == cctv.size()) {
            int ans=check_rectangleArea(middle);
//            for (int i = 0; i < n; i++) {
//                System.out.println(Arrays.toString(middle[i]));
//            }
//            System.out.println("ans : "+ans);
            maxZero=Math.min(maxZero,ans);
            return;
        }
        char temp[][]=new char[n][m];
        Node cur=cctv.get(cnt);
        switch (cur.dir)
        {
            case 1:
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < n; j++) {
                        temp[j]=middle[j].clone();
                    }
                    detect(cur.y,cur.x,temp,i);
                    watch(cnt+1,temp);
                }
                break;
            case 2:
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < n; j++) {
                        temp[j]=middle[j].clone();
                    }
                    detect(cur.y,cur.x,temp,i);
                    detect(cur.y,cur.x,temp,i+2);
                    watch(cnt+1,temp);
                }
                break;
            case 3:
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < n; j++) {
                        temp[j]=middle[j].clone();
                    }
                    detect(cur.y,cur.x,temp,i);
                    detect(cur.y,cur.x,temp,(i+1)%4);
                    watch(cnt+1,temp);
                }
                break;
            case 4:
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < n; j++) {
                        temp[j]=middle[j].clone();
                    }
                    detect(cur.y,cur.x,temp,i);
                    detect(cur.y,cur.x,temp,(i+1)%4);
                    detect(cur.y,cur.x,temp,(i+2)%4);
                    watch(cnt+1,temp);
                }
                break;
            case 5:
                    for (int j = 0; j < n; j++) {
                        temp[j]=middle[j].clone();
                    }
                    detect(cur.y,cur.x,temp,0);
                    detect(cur.y,cur.x,temp,1);
                    detect(cur.y,cur.x,temp,2);
                    detect(cur.y,cur.x,temp,3);
                    watch(cnt+1,temp);
                break;
        }
    }
    static void detect(int y,int x ,char temp[][],int dir)
    {
        switch (dir)
        {
            // <-
            case 0:
                for (int i = x; i >=0 ; i--) {
                    if(temp[y][i]=='6')
                        break;
                    temp[y][i]='#';
                }
                break;
                // 위
            case 1:
                for (int i = y; i >=0 ; i--) {
                    if(temp[i][x]=='6')
                        break;
                    temp[i][x]='#';
                }
                break;
                // ->
            case 2:
                for (int i = x; i <m ; i++) {
                    if(temp[y][i]=='6')
                        break;
                    temp[y][i]='#';
                }
                break;
                // 아래
            case 3:
                for (int i = y; i <n ; i++) {
                    if(temp[i][x]=='6')
                        break;
                    temp[i][x]='#';
                }
                break;
        }
    }

    static int check_rectangleArea(char arr[][])
    {
        int cnt=0;
        for (int i = 0; i <n; i++) {
            for (int j = 0; j < m; j++) {
                if(arr[i][j]=='0')
                    cnt++;
            }
        }
        return cnt;
    }


}
