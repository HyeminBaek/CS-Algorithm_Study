import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Firefly {
    public static void main(String[] args) throws IOException {
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int h=Integer.parseInt(st.nextToken());
        int up[]=new int[n/2]; // 석순
        int down[]=new int[n/2]; // 종유석.
        int u=0;
        int d=0;
        for (int i = 0; i < n; i++) {
            st=new StringTokenizer(br.readLine());
            if(i%2==1)
            {
                down[d++]=Integer.parseInt(st.nextToken());
            }
            else
            {
                up[u++]=Integer.parseInt(st.nextToken());
            }
        }

//        System.out.println(Arrays.toString(up));
//        System.out.println(Arrays.toString(down));

        Arrays.sort(up);
        Arrays.sort(down);
        int min=(int)1e9;
        int cnt[]=new int[h];
        for (int i = 1; i <=h; i++) {
            int a=bs(0,n/2-1,i,up,n);
            int b=bs(0,n/2-1,h-i+1,down,n);
            cnt[i-1]=a+b;
            if(min>cnt[i-1])
            {
                min=cnt[i-1];
            }
        }
        int sameCnt=0;
        for (int i : cnt) {
            if(i==min)
                sameCnt++;
        }
        System.out.println(min+" "+sameCnt);

    }
    static int bs(int s,int e,int target,int[] arr,int n)
    {
        int min=(int)1e9;
        while (s<=e)
        {
            int mid=(s+e)/2; // 거윤데 이면서 이 최소 부딪힌 횟수.
            if(target<=arr[mid])
            {
                // 부딪힌다. 아무딧히는 쪽으로 e=mid-1;
                e=mid-1;
                min=Math.min(min,mid); //
            }
            else
                s=mid+1;
        }
        // 전체-안 부딪치는 개수= 부딪힌 개수.
        if(min==(int)1e9)
            return 0;


        // 부딪힌거.
        return n/2-min;

    }
}
