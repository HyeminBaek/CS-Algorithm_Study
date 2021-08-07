package AL_CS_STUDY.RealTimeSolving.Weekly16;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class HarvestingCrops {
    static int map[][];
    static int n;
    static int ans;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(br.readLine());
        StringBuilder sb=new StringBuilder();
        for (int i = 0; i < T; i++) {
             n=Integer.parseInt(br.readLine());
            map=new int[n][n];
            for (int j = 0; j < n; j++) {
                String str[]=br.readLine().split("");
                for (int k = 0; k < n; k++) {
                    map[j][k]=Integer.parseInt(str[k]);
                }
            }

            int divde=n/2;
            for (int j = 0; j <divde ; j++) {
                for (int k = divde-j; k <=divde+j ; k++) {
                    ans+=map[j][k];
                }
            }

            for (int j = divde; j >=0 ; j--) {
                for (int k = divde-j; k <=divde+j ; k++) {
                    ans+=map[n-1-j][k];
                }
            }

            sb.append("#").append(i+1).append(" ").append(ans);
            ans=0;
        }
        System.out.println(sb);
    }
}

/*
1
7
3200021
1000023
3001023
0000004
1010033
3203112
1032100
*/