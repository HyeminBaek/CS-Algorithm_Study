package AL_CS_STUDY.Weekly17;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class LadderManipulation {

    static int n, m, h;
    static int ladder[][];
    static int min=4;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        ladder=new int[h][n];
        for (int i = 0; i < m; i++) {
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            ladder[a-1][b-1]=1;
            ladder[a-1][b]=-1;
        }
        pick(0,0);
        if(min>=4)
            System.out.println(-1);
        else
            System.out.println(min);


    }
    static void pick(int cnt,int idx)
    {
        if(cnt==3 || idx>= h*n)
        {
            if(check())
            {
                min=Math.min(min,cnt);
            }
            return;
        }
       int i=idx/n;
       int j=idx%n;
       if(j!=n-1 && ladder[i][j]==0 && ladder[i][j+1]==0)
       {
           ladder[i][j]=1;
           ladder[i][j+1]=-1;
           pick(cnt+1,idx+2);
           ladder[i][j]=ladder[i][j+1]=0;
       }
       pick(cnt,idx+1);
    }
    static boolean check()
    {
        for (int i = 0; i < n; i++) {
            int col=i;
            int row=0;
            while (row <h)
            {
                if(ladder[row][col]==-1)
                {
                    col--;
                }
                else if(ladder[row][col]==1)
                {
                    col++;
                }
                    row++;
            }
            if(col!=i)
                return false;
        }
        return true;
    }
}
