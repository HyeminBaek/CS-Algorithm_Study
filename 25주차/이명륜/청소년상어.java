import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

//상어가 움직일 수 있는 모든 경우의 수 : 16! 정도
// 일단 물고기 쭉 움직이고
// 상어가 갈 수 있는 모든 경우의 수 dfs처럼 하면 되나?
// 근데 상어 움직임 별로 물고기 맵이 달라지는데

public class Main{
    static int[][] dirs= new int[][]{{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
    static int answer=0;
    static int maxSum=0;

    static class Fish{
        int r,c,idx,dir;
        boolean isDead;
        public Fish(int idx,int dir,boolean isDead,int r,int c){
            this.idx=idx;
            this.dir=dir;
            this.isDead=isDead;
            this.r=r;
            this.c=c;
        }

        @Override
        public String toString() {
            return "Fish{" +
                    "r=" + r +
                    ", c=" + c +
                    ", idx=" + idx +
                    ", dir=" + dir +
                    ", isDead=" + isDead +
                    '}';
        }
    }

    static class Shark{
        int r,c,dir;
        public Shark(int r,int c,int dir){
            this.r=r;
            this.c=c;
            this.dir=dir;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        Fish[][] map = new Fish[4][4];

        for(int i=0;i<4;i++){
            st= new StringTokenizer(br.readLine());
            for(int j=0;j<4;j++){
                int idx = Integer.parseInt(st.nextToken());
                int dir = Integer.parseInt(st.nextToken())-1;
                map[i][j]=new Fish(idx,dir,false,i,j);
            }
        }

        Shark shark = new Shark(0,0,map[0][0].dir);
        map[0][0].isDead=true;

        fishesMove(map,shark,map[0][0].idx);

        System.out.println(maxSum);

    }

    private static void fishesMove(Fish[][] map,Shark shark,int sum){
        Fish[][] newMap = new Fish[4][4];
        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) {
                newMap[i][j]=new Fish(map[i][j].idx,map[i][j].dir,map[i][j].isDead,map[i][j].r,map[i][j].c);
            }
        }
        int sharkRow = shark.r;
        int sharkCol = shark.c;

        List<Integer> fishes = new ArrayList<>();  //살아있는 움직일 물고기들
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(newMap[i][j].isDead==false) fishes.add(newMap[i][j].idx);
            }
        }

        fishes.sort(Integer::compareTo);

        for(int i=0;i<fishes.size();i++){
            int fishIdx= fishes.get(i);

            boolean found=false;
            for(int r=0;r<4;r++){
                for(int c=0;c<4;c++){
                    if(newMap[r][c].idx!=fishIdx) continue;
                    found=true;

                    for(int d=newMap[r][c].dir , cnt=0 ; cnt<8 ; cnt++,d++,d%=8){
                        int nr= r+dirs[d][0];
                        int nc= c+dirs[d][1];
                        if(nr<0 || nr>=4 || nc<0 || nc>=4) continue;
                        if(nr==sharkRow && nc==sharkCol) continue;

                        Fish tmp
                                = new Fish(newMap[nr][nc].idx,newMap[nr][nc].dir,newMap[nr][nc].isDead,nr,nc);

                        newMap[nr][nc].idx=newMap[r][c].idx;
                        newMap[nr][nc].dir=d;
                        newMap[nr][nc].isDead=newMap[r][c].isDead;
//                        newMap[nr][nc].r=r;
//                        newMap[nr][nc].c=c;

                        newMap[r][c].idx=tmp.idx;
                        newMap[r][c].dir=tmp.dir;
                        newMap[r][c].isDead=tmp.isDead;
//                        newMap[r][c].r=tmp.r;
//                        newMap[r][c].c=tmp.c;

                        break;
                    }
                    if(found) break;
                }
                if(found) break;
            }
        }

        sharkMove(newMap,shark,sum);
    }

    private static void sharkMove(Fish[][] map,Shark shark,int sum){
        int sr=shark.r;
        int sc=shark.c;
        int sd=shark.dir;

        Fish[][] newMap = new Fish[4][4];
        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) {
                newMap[i][j]=new Fish(map[i][j].idx,map[i][j].dir,map[i][j].isDead,map[i][j].r,map[i][j].c);
            }
        }

//        System.out.println(shark.r+" "+shark.c+" "+sum);
//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++){
//                System.out.print(newMap[i][j]+" ");
//            }
//            System.out.println();
//        }
//        System.out.println();

//        boolean existToMove=false;

        for(int i=1;i<4;i++){
            int nr=sr+dirs[sd][0]*i;
            int nc=sc+dirs[sd][1]*i;

            if(nr<0 || nr>=4 || nc<0 || nc>=4) continue;
            if(newMap[nr][nc].isDead) continue;

//            existToMove=true;

            newMap[nr][nc].isDead=true;

            maxSum =Math.max(maxSum,sum+newMap[nr][nc].idx);

            fishesMove(newMap,new Shark(nr,nc,newMap[nr][nc].dir),sum+newMap[nr][nc].idx);

            newMap[nr][nc].isDead=false;

        }


    }


}
