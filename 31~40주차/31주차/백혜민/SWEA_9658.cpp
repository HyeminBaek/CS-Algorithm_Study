import java.util.Scanner;
import java.io.FileInputStream;
 
class Solution
{
    public static void main(String args[]) throws Exception
    {
 
        Scanner sc = new Scanner(System.in);
        int T;  T=sc.nextInt();
 
        for(int test_case = 1; test_case <= T; test_case++)
        {
            String s; s=sc.next();
             
            int arr[]= {0,0};
            int flag =(s.charAt(2)-'0' >=5)?1:0;
            for(int i=1;i>=0;i--)
            {
                int cur = s.charAt(i)-'0';
                cur+=flag;
                 
                if(i!=0&&cur>=10)
                {
                    flag = 1; arr[i]=0;
                }
                else
                {
                    flag =0; arr[i]=cur;
                }
            }
             
            String num=new String();
            if(arr[0]==10)
            {
                num="1.0"; flag=1;
            }
            else
            {
                num=Integer.toString(arr[0])+"."+Integer.toString(arr[1]); flag =0;
            }
             
            System.out.println("#"+test_case+" "+num+"*10^"+(s.length()-1+flag));
        }
    }
}
