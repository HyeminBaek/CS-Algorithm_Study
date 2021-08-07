import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 확실히 로직이 간단함.
// bfs 함수 만들어 놓고 하라는 대로 하면 될 듯
//자료구조 선택이 좀 까다로웠음 . 자료구조를 꼭 필요한 것 외에도 마구잡이로 쓴 느낌
// bfs는 한 번에 해야 효율적 a->모든 손님으로의 거리 한 번에 구할 수 있는데
// 각 손님마다 bfs하면 시간초과 발생

//각 손님의 위치 및 목적지 담고
//현재 택시와 모든 손님의 거리를 bfs 1번으로 구하고
// 현재 택시와의 거리(행,열)를 기준으로 정렬하고
// 가장 가까운데로 이동 및 목적지로 이동해서 가능한지 ...
// 가능하면 연료 ,택시 위치 , 손님 리스트 갱신해주고
// 불가능하면 멈추고



public class Main {
    static int n,m,Fuel;
    static int[][] map;
    static int[][] dirs = new int[][]{{0,-1},{-1,0},{0,1},{1,0}};
//    static boolean[][] visited;
    static int[][] distMap;

    static List<Location> customerList = new ArrayList<>();

    static class Coord{
        int r,c;
        public Coord(int r,int c){
            this.r=r;
            this.c=c;
        }
    }

    static class Location {
        int row,col,dist,idx,dstRow,dstCol;
        public Location(int row, int col,int dist,int idx,int dstRow,int dstCol){
            this.row=row;
            this.col=col;
            this.dist= dist;
            this.idx=idx;
            this.dstRow=dstRow;
            this.dstCol = dstCol;
        }

        public void setDist(int dist) {
            this.dist = dist;
        }

        @Override
        public String toString() {
            return "Location{" +
                    "row=" + row +
                    ", col=" + col +
                    ", dist=" + dist +
                    '}';
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        Fuel = Integer.parseInt(st.nextToken());

        map = new int[n][n];

        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        int taxiRow = Integer.parseInt(st.nextToken())-1;
        int taxiCol = Integer.parseInt(st.nextToken())-1;

        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int sr = Integer.parseInt(st.nextToken())-1;
            int sc = Integer.parseInt(st.nextToken())-1;
            int dr = Integer.parseInt(st.nextToken())-1;
            int dc = Integer.parseInt(st.nextToken())-1;

            customerList.add(new Location(sr,sc,0,i,dr,dc));
        }

        while(customerList.isEmpty()==false){
            getDistMap(taxiRow,taxiCol);

            //손님들의 택시와의 거리 구하기
            for(int i=0;i<customerList.size();i++){
                int r=customerList.get(i).row;
                int c=customerList.get(i).col;

                customerList.get(i).setDist(distMap[r][c]);
            }

            //현재 택시와 가까운 순으로 정렬
            customerList.sort(new Comparator<Location>() {
                @Override
                public int compare(Location x, Location y) {
                    if(x.dist!=y.dist) return x.dist-y.dist;
                    else{
                        if(x.row!=y.row) return x.row-y.row;
                        else return x.col-y.col;
                    }
                }
            });

            Location neareast = customerList.get(0);

            int cost = neareast.dist;

            // 선택된 가장 가까운 손님의 목적지까지 거리 구하기
            int cost2 = getDestinationDist(neareast.row, neareast.col,  neareast.dstRow, neareast.dstCol);

            if(cost+cost2>Fuel){
                System.out.println(-1);
                return;
            }

            Fuel-=(cost+cost2);
            Fuel+=cost2*2;

            customerList.remove(0);
            taxiRow= neareast.dstRow;
            taxiCol= neareast.dstCol;

//            System.out.println(Fuel);

        }

        System.out.println(Fuel);
    }

    private static void getDistMap(int taxiRow,int taxiCol){
        Queue<Coord> q = new LinkedList<>();
        q.add(new Coord(taxiRow,taxiCol));
        distMap = new int[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) distMap[i][j]=(int)1e9;
        distMap[taxiRow][taxiCol] = 0;

        while(q.isEmpty()==false){
            Coord here = q.poll();
            int r= here.r;
            int c=here.c;

            for(int i=0;i<4;i++){
                int nr=r,nc=c;
                nr+=dirs[i][0];
                nc+=dirs[i][1];

                if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
                if(map[nr][nc]==1) continue;
                if(distMap[nr][nc] <= distMap[r][c]+1) continue;

                distMap[nr][nc] = distMap[r][c]+1;
                q.add(new Coord(nr,nc));
            }
        }
    }

    private static int getDestinationDist(int sr,int sc,int dr,int dc){
        Queue<Coord> q = new LinkedList<>();
        q.add(new Coord(sr,sc));
        distMap = new int[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) distMap[i][j]=(int)1e9;
        distMap[sr][sc]=0;

        while(q.isEmpty()==false){
            Coord here = q.poll();
            int r= here.r;
            int c=here.c;

            for(int i=0;i<4;i++){
                int nr=r,nc=c;
                nr+=dirs[i][0];
                nc+=dirs[i][1];

                if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
                if(map[nr][nc]==1) continue;
                if(distMap[nr][nc] <= distMap[r][c]+1) continue;

                distMap[nr][nc] = distMap[r][c]+1;
                q.add(new Coord(nr,nc));
            }
        }

        return distMap[dr][dc];

    }

}

