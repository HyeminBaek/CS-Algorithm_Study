package AL_CS_STUDY.Weekly16;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class runway {
    static int n,l;
    static int map[][];
    static int cnt;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
         l=Integer.parseInt(st.nextToken());

         map=new int[n][n];
        for (int i = 0; i < n; i++) {
            st=new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j]=Integer.parseInt(st.nextToken());
            }
        }


        for (int i = 0; i < n; i++) {
            if(check(i,0,0))
                cnt++;
            if(check(0,i,1))
                cnt++;
        }
        System.out.println(cnt);
    }
    static boolean check(int y,int x,int d)
    {
        boolean visited[]=new boolean[n];
        int comp[]=new int[n];
        for (int i = 0; i < n; i++) {
            comp[i]=d==0 ? map[y][x+i]:map[y+i][x];
        }
        for (int i = 0; i < n-1; i++) {
            if(comp[i]==comp[i+1])
                continue;
            if(Math.abs(comp[i]-comp[i+1])>1)
                return false;
            if(comp[i]-1==comp[i+1])
            {
                for (int j = i+1; j <=i+l ; j++) {
                    if(j>=n || comp[i+1]!=comp[j] || visited[j])
                        return false;
                    visited[j]=true;
                }
            }

            else if(comp[i]+1==comp[i+1])
            {
                for (int j = i; j >i-l ; j--) {
                    if(j<0 || comp[i] !=comp[j] || visited[j])
                        return false;

                    visited[j]=true;
                }
            }
        }
        return true;
    }



}
