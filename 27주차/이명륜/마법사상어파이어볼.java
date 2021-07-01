import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main{
    static List<int[]> dirs = Arrays.asList(
            new int[]{-1,0}, new int[]{-1,1},new int[]{0,1},new int[]{1,1},
            new int[]{1,0},new int[]{1,-1},new int[]{0,-1},new int[]{-1,-1});

    static class FireBall{
        int mass,speed,dir;
        public FireBall(int mass,int speed,int dir){
            this.mass=mass;
            this.speed=speed;
            this.dir=dir;
        }
    }

    static class Map{
        List<FireBall> fireBallList = new ArrayList<>();

        public void addFireBall(FireBall fireBall){
            this.fireBallList.add(fireBall);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        st = new StringTokenizer(br.readLine());
        int n= Integer.parseInt(st.nextToken());
        int m= Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        Map[][] map = new Map[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) map[i][j] = new Map();

        Map[][] map2 = new Map[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) map2[i][j] = new Map();

//        List<FireBall> fireBallList = new ArrayList<>();

        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int r= Integer.parseInt(st.nextToken())-1;
            int c= Integer.parseInt(st.nextToken())-1;
            int mass =Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int d= Integer.parseInt(st.nextToken());

            map[r][c].addFireBall(new FireBall(mass,s,d));
        }

        for(int step=0;step<k;step++){
            for(int r=0;r<n;r++) for(int c=0;c<n;c++) map2[r][c].fireBallList.clear();

            //1. 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다 :: map -> map2
            for(int r=0;r<n;r++){
                for(int c=0;c<n;c++){
                    List<FireBall> list = map[r][c].fireBallList;
                    for(int i=0;i<list.size();i++){
                        int dir = list.get(i).dir;
                        int mass = list.get(i).mass;
                        int speed = list.get(i).speed;

                        int nr=r+dirs.get(dir)[0]*speed;
                        int nc=c+dirs.get(dir)[1]*speed;    //범위 벗어나면 어케하지? 문제에 설명이 없는데
                        //if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
                        int row_mok = nr/n;
                        int col_mok = nc/n;

                        if(nr<0) { nr+=n*(-row_mok+1);}
                        if(nc<0) { nc+=n*(-col_mok+1);}
                        nr%=n;
                        nc%=n;
                        map2[nr][nc].addFireBall(new FireBall(mass,speed,dir)); //mass ,speed ,dir

                    }
                }
            }

            for(int r=0;r<n;r++) for(int c=0;c<n;c++) map[r][c].fireBallList.clear();

//            for(int r=0;r<n;r++){
//                for(int c=0;c<n;c++) {
//                    System.out.print(map2[r][c].fireBallList.size()+" ");
//                }
//                System.out.println();
//            }
//            System.out.println();

            // 2. 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다.
            // map2 -> map
            for(int r=0;r<n;r++){
                for(int c=0;c<n;c++){
                    int massSum = 0;
                    int speedSum =0;
                    boolean evenDir=false;
                    boolean oddDir=false;
                    int fireBallListSize = map2[r][c].fireBallList.size();
                    if(fireBallListSize<2) {
                        map[r][c].fireBallList.addAll(map2[r][c].fireBallList);
                        continue;
                    }

                    for(int i=0;i<map2[r][c].fireBallList.size();i++){
                        massSum+=map2[r][c].fireBallList.get(i).mass;
                        speedSum+=map2[r][c].fireBallList.get(i).speed;
                        int dir=map2[r][c].fireBallList.get(i).dir;
                        if((dir%2)==0) evenDir=true;
                        else oddDir=true;
                    }

                    if((massSum/5) ==0) continue;

                    if(evenDir^oddDir){
                        for(int i=0,d=0;i<4;i++,d+=2)    {
                            FireBall newFireBall = new FireBall(massSum/5,speedSum/fireBallListSize,d);
                            map[r][c].addFireBall(newFireBall);
                        }
                    }else{
                        for(int i=0,d=1;i<4;i++,d+=2)    {
                            FireBall newFireBall = new FireBall(massSum/5,speedSum/fireBallListSize,d);
                            map[r][c].addFireBall(newFireBall);
                        }
                    }
                }
            }
        }

        int totalMass=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                for(int i=0;i<map[r][c].fireBallList.size();i++) totalMass+=map[r][c].fireBallList.get(i).mass;
            }
        }

        System.out.println(totalMass);


    }
}
