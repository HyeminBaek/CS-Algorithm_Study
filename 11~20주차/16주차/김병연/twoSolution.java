package AL_CS_STUDY.Weekly16;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class twoSolution {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        int arr[]=new int[n];

        StringTokenizer st=new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i]=Integer.parseInt(st.nextToken());
        }

        int ans=Integer.MAX_VALUE;
        int sum=0;
        int l=0;
        int r=n-1;
        int ret[]=new int[2];
        Arrays.sort(arr);
//        System.out.println(Arrays.toString(arr));
        while (l<r)
        {
           sum=(arr[l]+arr[r]);
           int res=Math.abs(sum);

           if(res<ans)
           {
               ans=res;
               ret[0]=arr[l];
               ret[1]=arr[r];
           }
           if(sum>0)
               r--;
           else
               l++;
        }
        System.out.println(ret[0]+" "+ret[1]);
    }

}
