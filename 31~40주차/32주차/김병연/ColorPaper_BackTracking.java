package AL_CS_STUDY.Weekly32;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ColorPaper_BackTracking {
    static final int N = 10;
    static int[][] paper = new int[N][N];
    static int restPaper[] = {0,5,5,5,5,5};
    static int answer=Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                paper[i][j] = Integer.parseInt(st.nextToken());

            }
        }

        dfs(0,0);
        System.out.println(answer==Integer.MAX_VALUE? -1:answer);
    }
    static void dfs(int idx, int cnt)
    {
        if(idx==N*N)
        {
            answer=Math.min(answer,cnt);
        }
        if(answer<=cnt)
            return;
        int y=idx/N;
        int x=idx%N;
        if(paper[y][x]==1)
        {
            for (int paperSize = 5; paperSize >=1 ; paperSize--) {
                if(restPaper[paperSize]>0 && checkPaper(paperSize,y,x))
                {
                    overWriteArray(paperSize,y,x,0);
                    restPaper[paperSize]--;
                    dfs(idx+1,cnt+1);
                    overWriteArray(paperSize,y,x,1);
                    restPaper[paperSize]++;
                }
            }
        }
        else {
            dfs(idx+1,cnt);
        }
    }
    private static boolean checkPaper(int paperSize, int y, int x) {
        if (y+paperSize>10 || x+paperSize>10) {
            return false;
        }
        for (int i = y; i < y + paperSize; i++) {
            for (int j = x; j < x + paperSize; j++) {

                if (paper[i][j] != 1) {
                    return false;
                }
            }
        }
        return true;
    }

    private static void overWriteArray(int paperSize, int y, int x,int state) {
        for (int i = y; i < y + paperSize; i++) {
            for (int j = x; j < x + paperSize; j++) {
                paper[i][j]= state;
            }
        }
    }
}
