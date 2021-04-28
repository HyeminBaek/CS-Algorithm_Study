package AL_CS_STUDY.Weekly18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class DragonCurve {
    static int dy[]={0,-1,0,1};
    static int dx[]={1,0,-1,0};
    static boolean map[][]=new boolean[101][101];
    static ArrayList<Integer> directions;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st=new StringTokenizer(br.readLine());
            directions=new ArrayList<>();

            int x=Integer.parseInt(st.nextToken());
            int y=Integer.parseInt(st.nextToken());
            int d=Integer.parseInt(st.nextToken());
            directions.add(d);
            int g=Integer.parseInt(st.nextToken());
            curve(g);
            draw(x,y);
        }
        int rectangleNumber=0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if(map[i][j] && map[i][j+1] &&map[i+1][j+1] && map[i+1][j])
                    rectangleNumber++;
            }
        }
        System.out.println(rectangleNumber);
    }
    static void curve(int generation)
    {
        for (int i = 0; i < generation; i++) {
            for (int j = directions.size()-1; j >=0 ; j--) {
                directions.add((directions.get(j)+1)%4);
            }
        }
    }
    static void draw(int x,int y)
    {
        map[x][y]=true;
        int nx=x;
        int ny=y;
        for (int i = 0; i < directions.size(); i++) {
            int d=directions.get(i);
            nx+=dx[d];
            ny+=dy[d];
            map[nx][ny]=true;
        }
    }
}
