import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ2294 {

	public static void main(String[] args) throws Exception{
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken()),K=Integer.parseInt(st.nextToken());
		int[] arr = new int[N];
		
		for(int i=0;i<N;i++) arr[i]=Integer.parseInt(br.readLine());
		
		Arrays.sort(arr);
		for(int i=0;i<N;i++) {
			if(arr[i]>K) {
				N=i; break;
			}
		}

		solution(N,K,arr);
	}
	private static void solution(int N,int K,int arr[]) {
		int dp[] = new int[K+1];
		for(int i=0;i<=K;i++) dp[i]=987654321;
		for(int i=0;i<N;i++) dp[arr[i]]=1;
		
		for(int k=1;k<=K;k++) {
			for(int i=0;i<N;i++) {
				if(k<=arr[i]) break;
				
				dp[k]=Math.min(dp[k], dp[k-arr[i]]+1);
			}
		}
		
		if(dp[K]==987654321) System.out.println(-1);
		else System.out.println(dp[K]);
	}//sol func
	
}
