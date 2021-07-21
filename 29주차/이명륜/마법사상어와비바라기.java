    import java.io.*;
    import java.util.*;

    public class Main{
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer("");

            st = new StringTokenizer(br.readLine());
            int n  = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            int[][] rain = new int[n][n];
            int[][] goorm = new int[n][n];

            for(int i=0;i<n;i++){
                st = new StringTokenizer(br.readLine());
                for(int j=0;j<n;j++){
                    rain[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            //초기 구름.
            goorm[n-1][0]=1;
            goorm[n-1][1]=1;
            goorm[n-2][0]=1;
            goorm[n-2][1]=1;

            List<int[]> moveInfos = new ArrayList<>();

            for(int i=0;i<m;i++){
                st = new StringTokenizer(br.readLine());
                int d= Integer.parseInt(st.nextToken());
                d--;
                int s=Integer.parseInt(st.nextToken());
                moveInfos.add(new int[]{d,s});
            }

            int[][] dirs = new int[][]{{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
            int[][] crossDirs = new int[][] {{-1,-1},{-1,1},{1,-1},{1,1}};

            //시뮬레이션
            for(int mi=0;mi<m;mi++){
                int d=moveInfos.get(mi)[0];
                int s=moveInfos.get(mi)[1];
                int[][] nxtGoorm = new int[n][n];
                int[][] incremented = new int[n][n];

                //1. 모든 구름 이동
                for(int r=0;r<n;r++){
                    for(int c=0;c<n;c++){
                        if(goorm[r][c]==0) continue;
                        int nr = r+dirs[d][0]*s;
                        int nc = c+dirs[d][1]*s;

                        nr+=n*s;
                        nc+=n*s;

                        nr%=n;
                        nc%=n;
                        nxtGoorm[nr][nc]=1;
                    }
                }

                //2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
                for(int r=0;r<n;r++){
                    for(int c=0;c<n;c++){
                        if(nxtGoorm[r][c]==0) continue;
                        rain[r][c]++;
                        incremented[r][c]=1;    //물이 증가한 칸
                    }
                }

                //3.구름이 모두 사라진다.
                for(int r=0;r<n;r++){
                    for(int c=0;c<n;c++){
                        goorm[r][c]=0;
                    }
                }

                //4. (2)에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다.
                for(int r=0;r<n;r++){
                    for(int c=0;c<n;c++){
                        if(incremented[r][c]==0) continue;
                        int crossWateredBucket = 0;
                        for(int di=0;di<4;di++){
                            int nr=r+crossDirs[di][0];
                            int nc=c+crossDirs[di][1];
                            if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
                            if(rain[nr][nc]!=0) crossWateredBucket++;
                        }

                        rain[r][c]+=crossWateredBucket;
                    }
                }

                //5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다.
                // 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
                for(int r=0;r<n;r++){
                    for(int c=0;c<n;c++){
                        if(rain[r][c]<2) continue;
                        if(nxtGoorm[r][c]!=0) continue;
                        goorm[r][c]=1;
                        rain[r][c]-=2;
                    }
                }
            }

            int totalRain = 0;
            for(int r=0;r<n;r++){
                for(int c=0;c<n;c++){
//                    System.out.print(rain[r][c]+" ");
                    totalRain+=rain[r][c];
                }
//                System.out.println();
            }

            System.out.println(totalRain);

        }
    }
