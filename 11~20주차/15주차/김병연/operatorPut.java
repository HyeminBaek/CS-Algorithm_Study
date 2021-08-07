package AL_CS_STUDY.Weekly15;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class operatorPut {
    static int n,number[],operator[];
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        number=new int[n];
        st=new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            number[i]=Integer.parseInt(st.nextToken());
        }
        st=new StringTokenizer(br.readLine());
        operator=new int[4];
        for (int i = 0; i <4 ; i++) {
            operator[i]=Integer.parseInt(st.nextToken());
        }
        dfs(1,number[0]);
        System.out.println(max+"\n"+min);
    }
    static int max=Integer.MIN_VALUE;
    static int min=Integer.MAX_VALUE;
    static void dfs(int cnt,int sum)
    {
        if(cnt==n)
        {
            max=Math.max(sum,max);
            min=Math.min(sum,min);
            return;
        }
        for (int i = 0; i < 4; i++) {
            if(operator[i]!=0)
            {
                operator[i]--;
                switch (i)
                {
                    case 0:
                        dfs(cnt+1,sum+number[cnt]);
                        break;
                    case 1:
                        dfs(cnt+1,sum-number[cnt]);
                        break;
                    case 2:
                        dfs(cnt+1,sum*number[cnt]);
                        break;
                    case 3:
                        dfs(cnt+1,sum/number[cnt]);
                        break;
                }
                operator[i]++;
            }
        }

    }

}
