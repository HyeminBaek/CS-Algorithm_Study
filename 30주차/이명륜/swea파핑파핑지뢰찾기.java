import java.util.*;
import java.io.*;
 
class Solution
{
     
    public static void main(String args[]) throws Exception
    {
     
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T;
        T=Integer.parseInt(br.readLine());
         
        DIRS = new ArrayList<>();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0 && j==0) continue;
                DIRS.add(new int[]{i,j});
            }
        }
 
        for(int test_case = 1; test_case <= T; test_case++)
        {
            n =Integer.parseInt(br.readLine());
            char[][] map = new char[n][n];
            StringTokenizer st = new StringTokenizer("");
             
            for(int i=0;i<n;i++){
                String row = br.readLine();
                for(int j=0;j<n;j++){
                    map[i][j] = row.charAt(j);
                }
            }
             
            mineCnt = new int[n][n];
            visited = new boolean[n][n];
             
            for(int r=0;r<n;r++){
                for(int c=0;c<n;c++){
                    int cnt=0;
                    for(int d=0;d<8;d++){
                        int nr=r+DIRS.get(d)[0];
                        int nc=c+DIRS.get(d)[1];
                        if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
                        if(map[nr][nc]=='*') cnt++;
                    }     
                    mineCnt[r][c] = cnt;
                }
            }
             
            int answer=0;
             
            for(int r=0;r<n;r++){
                for(int c=0;c<n;c++){
                    if(map[r][c]=='*') continue;
                    if(mineCnt[r][c]!=0) continue;
                    if(visited[r][c]) continue;
                    answer++;
                    dfs(r,c);
                }
            }
 
            for(int r=0;r<n;r++){
                for(int c=0;c<n;c++){
                 if(visited[r][c]) continue;
                   if(map[r][c]=='*') continue;
                    answer++;
                }
            }
             
            System.out.println("#"+test_case+" "+answer);
        }
    }
     
    static int n;
    private static List<int[]> DIRS;
    private static boolean[][] visited;
    private static  int[][] mineCnt;
     
    private static void dfs(int r,int c){
        visited[r][c]=true;
        for(int d=0;d<8;d++){
            int nr=r+DIRS.get(d)[0];
            int nc=c+DIRS.get(d)[1];
            if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
            if(mineCnt[nr][nc]==0 && visited[nr][nc]==false) dfs(nr,nc); 
            visited[nr][nc]=true;
        }
    }
}
