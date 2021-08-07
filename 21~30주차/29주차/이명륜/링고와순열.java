    import java.io.*;
    import java.util.*;

    public class Main{
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer("");

            st = new StringTokenizer(br.readLine());
            int n =Integer.parseInt(st.nextToken());
            long k=Long.parseLong(st.nextToken());

            // 1~n에서 만약 n를 젤 앞에 놔버리면
            // n 뒤에 어떻게 놓든 n-1개의 반전이 생긴다
            //=> 본인보다 뒤의 것들만 반전의 갯수에 반영되도록 세아릴 수 있다

            long max = (long)(n-1)*n/2;
            if(k>max){
                System.out.println(-1);
            }else{
                boolean[] used= new boolean[n+1];


                for(int i=n;i>=1;i--) {
                    if(k>=i-1){
                        System.out.print(i+" ");
                        k-=(i-1);
                        used[i]=true;
                    }else{
                        continue;
                    }
                }

                for(int i=1;i<=n;i++){
                    if(used[i]) continue;
                    System.out.print(i+" ");
                }

            }
        }
    }
