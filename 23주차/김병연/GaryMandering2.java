package AL_CS_STUDY.Weekly23;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class GaryMandering2 {
    static int n,map[][];
    static boolean area[][];
    static int totalPopulation=0;

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
        map=new int[n][n];
        for (int i = 0; i < n; i++) {
            String str[]=br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                totalPopulation+= map[i][j] = Integer.parseInt(str[j]);
            }
        }

        for (int x = 0; x <n; x++) {
            for (int y = 1; y <n ; y++) {
                for (int d1 = 1; d1<n; d1++) {
                    for (int d2 = 1; d2<n ; d2++) {
                        if(x+d1+d2>=n) continue;
                        if(y-d1<0 || y+d2>=n) continue;

                        solution(x,y,d1,d2);
                    }
                }
            }
        }
        System.out.println(min);
    }
   static int min=Integer.MAX_VALUE;
    private static void solution(int x, int y, int d1, int d2) {
        area=new boolean[n][n];
        for (int i = 0; i <=d1; i++) {
            area[x+i][y-i]=true;
            area[x+d2+i][y+d2-i]=true;
        }
        for (int i = 0; i <=d2; i++) {
            area[x+i][y+i]=true;
            area[x+d1+i][y-d1+i]=true;
        }

        int [] sum=new int[5];
    //1
        for (int i = 0; i <x+d1 ; i++) {
            for (int j = 0; j <=y; j++) {
                if(area[i][j])
                    break;
                sum[0]+=map[i][j];
            }
        }
    //2
        for (int i = 0; i <= x+d2; i++) {
            for (int j = n-1; j >y ; j--) {
                if(area[i][j])
                    break;
                sum[1]+=map[i][j];
            }
        }

        for (int i = x+d1; i <n ; i++) {
            for (int j = 0; j < y-d1+d2; j++) {
                if(area[i][j])
                    break;
                sum[2]+=map[i][j];
            }
        }

        for (int i = x+d2+1; i <n ; i++) {
            for (int j = n-1; j >=y-d1+d2; j--) {
                if(area[i][j])
                    break;
                sum[3]+=map[i][j];
            }
        }

        sum[4]=totalPopulation;
        for (int i = 0; i < 4; i++) {
            sum[4]-=sum[i];
        }
        Arrays.sort(sum);
        min=Math.min(min,sum[4]-sum[0]);
    }
}
