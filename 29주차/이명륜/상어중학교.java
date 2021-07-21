    import java.io.*;
    import java.util.*;

    public class Main{
        private static int n;
        private static int[][] map;
        private static int[][] DIRS = new int[][]{{0,-1},{-1,0},{0,1},{1,0}};   //코딩 컨벤션에 따라 상수는 대문자로 함.

        private static class Info implements Comparable<Info>{
            int row,col,blockCnt,rainbowCnt;

            @Override
            public int compareTo(Info other) {
                if(this.blockCnt!=other.blockCnt) return -(this.blockCnt-other.blockCnt);
                else{
                    if(this.rainbowCnt!=other.rainbowCnt) return -(this.rainbowCnt-other.rainbowCnt);
                    else{
                        if(this.row!=other.row) return -(this.row-other.row);
                        else return -(this.col-other.col);
                    }
                }
            }

            @Override
            public String toString() {
                return "Info{" +
                        "row=" + row +
                        ", col=" + col +
                        ", blockCnt=" + blockCnt +
                        ", rainbowCnt=" + rainbowCnt +
                        '}';
            }
        }

        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer("");

            //진짜 하라는 대로 하면 되겠다
            // 효율을 크게 안 따져도 모든 각 칸에 대해 bfs해서 블록의 크기 ,기준 블록,무지개블록 갯수를 구하고
                // 기준 블록 : 무지개 블록이 아닌 블록 중에서 행의 번호가 가장 작은 블록, 그러한 블록이 여러개면 열의 번호가 가장 작은 블록이다.
            // 가장 크며 최고 우선순위의 블록을 찾고
            // 그거 다 지우고 (-2라 하자)
            //맵에 중력 작용시키고
            //맵을 90도 반시게로 회전시키고
            //맵에 중력 작용시키고

            //위 과정을 블록 남아있을 때 까지 무한 반복하면 되는데


            st = new StringTokenizer(br.readLine());
            n= Integer.parseInt(st.nextToken());
            int m=Integer.parseInt(st.nextToken());
            map= new int[n][n];

            for(int r=0;r<n;r++){
                st = new StringTokenizer(br.readLine());
                for(int c=0;c<n;c++){
                    map[r][c] =Integer.parseInt(st.nextToken());
                }
            }

//            rotateCCW90();
//            print();

            int answerScore=0;


            while(true){
                //종료 검사
                boolean isFinished=checkFinished();
                if(isFinished) break;
                List<Info> infos = new ArrayList<>();

                // 1. 모든 각 칸에서 완전탐색하여 크기가 가장 큰 블록 그룹을 찾는다
                for(int r=0;r<n;r++){
                    for(int c=0;c<n;c++){
                        int hereNum = map[r][c];
                        if(hereNum==0 || hereNum==-1 || hereNum==-2) continue;

                        Queue<int[]> queue = new LinkedList<>();
                        int[] baseBlock = new int[]{r,c};
                        int blockCnt=0;
                        int rainbowBlockCnt=0;

                        queue.add(new int[]{r,c});
                        boolean[][] visited = new boolean[n][n];

                        while(queue.isEmpty()==false){
                            int[] here = queue.poll();
                            int hr=here[0];
                            int hc=here[1];

                            for(int di=0;di<4;di++){
                                int nxtRow = hr+DIRS[di][0];
                                int nxtCol = hc+DIRS[di][1];

                                if(nxtRow<0 || nxtRow>=n || nxtCol<0 || nxtCol>=n) continue;
                                if(visited[nxtRow][nxtCol]) continue;
                                if(map[nxtRow][nxtCol]!=hereNum && map[nxtRow][nxtCol]!=0) continue;

                                queue.add(new int[]{nxtRow,nxtCol});
                                visited[nxtRow][nxtCol]=true;
                            }
                        }

                        //블록 갯수 세아리기,기준 블록 찾기
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                if(visited[i][j]==false) continue;
                                blockCnt++;
                                if(map[i][j]==0) {
                                    rainbowBlockCnt++;
                                    continue;
                                }

                                if(baseBlock[0] >i){
                                    baseBlock[0]=i;
                                    baseBlock[1]=j;
                                }else if(baseBlock[0]==i){
                                    if(baseBlock[1]>j){
                                        baseBlock[0]=i;
                                        baseBlock[1]=j;
                                    }
                                }
                            }
                        }


                        Info hereInfo =new Info();
                        hereInfo.row=baseBlock[0];
                        hereInfo.col=baseBlock[1];
                        hereInfo.rainbowCnt=rainbowBlockCnt;
                        hereInfo.blockCnt=blockCnt;

                        infos.add(hereInfo);
                    }
                }


                infos.sort(Info::compareTo);

                if(infos.isEmpty()) break;
                
                // 1.가장 큰 블록 찾음
                Info biggestBlockInfo = infos.get(0);

                int baseRow = biggestBlockInfo.row;
                int baseCol = biggestBlockInfo.col;
                int biggestBlockCnt = biggestBlockInfo.blockCnt;
                int hereNum = map[baseRow][baseCol];

                if(biggestBlockCnt<2) break;

                answerScore+=biggestBlockCnt*biggestBlockCnt;

                // 2. 찾은 블록 그룹의 모든 블록을 제거한다. 블록 그룹에 포함된 블록의 수를 B라고 했을 때, B2점을 획득한다.
                Queue<int[]> queue2 = new LinkedList<>();   //queue to erase
                queue2.add(new int[]{baseRow,baseCol});
                map[baseRow][baseCol]=-2;

                while(queue2.isEmpty()==false){
                    int[] here = queue2.poll();
                    int r=here[0];
                    int c=here[1];

                    for(int i=0;i<4;i++){
                        int nr=r+DIRS[i][0];
                        int nc=c+DIRS[i][1];
                        if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
                        if(map[nr][nc]==-2 || map[nr][nc]==-1) continue;
                        if(map[nr][nc]!=hereNum && map[nr][nc]!=0) continue;

                        queue2.add(new int[]{nr,nc});
                        map[nr][nc]=-2;
                    }
                }



                //3. 격자에 중력이 작용한다.
                doGravity();

                //4.격자에 중력이 작용한다.
                rotateCCW90();

                //5. 다시 격자에 중력이 작용한다.
                doGravity();

//                System.out.println(infos);
//                System.out.println(biggestBlockInfo);
//                System.out.println(answerScore);
//                print();

            }

            System.out.println(answerScore);

        }


        //종료 검사 함수
        private static boolean checkFinished(){
            for(int r=0;r<n;r++){
                for(int c=0;c<n;c++){
                    if(map[r][c]!=-2 && map[r][c]!=-1) return false;
                }
            }

            return true;
        }

        //중력 함수
        private static void doGravity(){
            int[][] tempMap = new int[n][n];
            for(int r=0;r<n;r++) for(int c=0;c<n;c++) tempMap[r][c]=map[r][c];

            for(int r=n-2;r>=0;r--){
                for(int c=0;c<n;c++){
                    if(tempMap[r][c]==-2) continue;
                    if(tempMap[r][c]==-1) continue;

                    for(int down=1;down<=n;down++){
                        int nr=r+down;
                        if(nr>=n) break;
                        int below = tempMap[nr][c];
                        if(below!=-2 || below==-1) break;
                        tempMap[nr][c]=tempMap[nr-1][c];
                        tempMap[nr-1][c]=below;
                    }
                }
            }

            for(int r=0;r<n;r++) for(int c=0;c<n;c++) map[r][c]=tempMap[r][c];
        }

        //맵을 90도 반시계 회전하는 함수
        private static void rotateCCW90(){
            int[][] tempMap = new int[n][n];
            for(int r=0;r<n;r++) for(int c=0;c<n;c++) tempMap[r][c]=map[r][c];

            for(int r=0;r<n;r++){
                for(int c=0;c<n;c++){
                    int nr=n-1-c;
                    int nc=r;
                    map[nr][nc]=tempMap[r][c];
                }
            }
        }

        private static void print(){
            for(int r=0;r<n;r++){
                for(int c=0;c<n;c++){
                    System.out.print(map[r][c]+" ");
                }
                System.out.println();
            }
        }


    }
