package AL_CS_STUDY.Weekly24;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class DiceStacking {
    static int n,dices[][];
    static int sideIdx[]={5,3,4,1,2,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        dices=new int[n][6];

        for (int i = 0; i < n; i++) {
            st=new StringTokenizer(br.readLine());

            for (int j = 0; j < 6; j++) {
                dices[i][j]=Integer.parseInt(st.nextToken());
            }
        }
        int total=0;
        int answer=0;

        for (int i = 0; i < 6; i++) {
            int up=dices[0][i];
            total=check(up,0,i);
            for (int j = 1; j < n; j++) {
                for (int k = 0; k < 6; k++) {
                    if(up==dices[j][k])
                    {
                        total+=check(dices[j][k],j,k);
                        up=dices[j][sideIdx[k]];
                        break;
                    }
                }
            }
            answer=Math.max(total,answer);
        }

        System.out.println(answer);
    }

    private static int check(int up, int bottom, int idx) {
        int tmp=0;
        for (int i = 0; i < 6; i++) {
            if(dices[bottom][i]==dices[bottom][idx] || dices[bottom][i]==dices[bottom][sideIdx[idx]])
            {
                continue;
            }
            tmp=Math.max(tmp,dices[bottom][i]);
        }
        return tmp;
    }

}
