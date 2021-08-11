import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
   public static class Pair {
      int r, c, s;

      public Pair(int r, int c, int s) {
         this.r = r;
         this.c = c;
         this.s = s;
      }
   }

   public static int N, M, K, answer;
   public static int origin[][];
   public static int origin_copy[][];
   public static Pair list[];
   public static boolean visited[];

   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());

      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());
      K = Integer.parseInt(st.nextToken());
      origin = new int[N + 1][M + 1];
      origin_copy = new int[N + 1][M + 1];

      for (int i = 1; i <= N; i++) {
         st = new StringTokenizer(br.readLine());
         for (int j = 1; j <= M; j++) {
            origin[i][j] = Integer.parseInt(st.nextToken());
            origin_copy[i][j] = origin[i][j];
         }
      }

      answer = -1;
      visited = new boolean[K];
      for (int i = 0; i < K; i++)
         visited[i] = false;

      list = new Pair[K];
      for (int i = 0; i < K; i++) {
         st = new StringTokenizer(br.readLine());

         int r = Integer.parseInt(st.nextToken());
         int c = Integer.parseInt(st.nextToken());
         int s = Integer.parseInt(st.nextToken());

         list[i] = new Pair(r, c, s);
      }

      permu(new StringBuilder());

      System.out.println(answer);
   }

   private static int sum(int arr[][]) {
      int ans = 0;
      for (int i = 1; i <= N; i++) {
         int sm = 0;
         for (int j = 1; j <= M; j++)
            sm += arr[i][j];

         if (ans == 0 || ans > sm)
            ans = sm;
      }

      return ans;
   }

   private static void arr_copy() {
      for (int i = 1; i <= N; i++) {
         for (int j = 1; j <= M; j++) {
            origin[i][j] = origin_copy[i][j];
         }
      }
   }

   private static void permu(StringBuilder sb) {
      if (sb.length() == K) {
         arr_copy();
         for (int i = 0; i < sb.length(); i++) {
            // System.out.println(sb.charAt(i));
            Pair p = list[sb.charAt(i) - '0'];
            rotate(p.r, p.c, p.s, origin);

         }

         int result = sum(origin);

         if (answer == -1 || answer > result)
            answer = result;
         return;
      }
      for (int i = 0; i < list.length; i++) {
         if (!visited[i]) {
            visited[i] = true;

            StringBuilder tmp = new StringBuilder();
            for (int j = 0; j < sb.length(); j++)
               tmp.append(sb.charAt(j));

            tmp.append(i);
            permu(tmp);
            visited[i] = false;
         }
      }
   }

   private static void rotate(int r, int c, int S, int arr[][]) {
      for (int s = 1; s <= S; s++) {
         int temp = arr[r - s][c + s];
         for (int i = c + s; i > c - s; i--)// 위 가로
         {
            arr[r - s][i] = arr[r - s][i - 1];
         }
         int temp1 = arr[r + s][c + s];
         for (int i = r + s; i > r - s; i--)// 오른쪽 세로
         {
            arr[i][c + s] = arr[i - 1][c + s];
         }
         arr[r - s + 1][c + s] = temp;
         temp = arr[r + s][c - s];
         for (int i = c - s; i < c + s; i++) {
            arr[r + s][i] = arr[r + s][i + 1];
         }
         arr[r + s][c + s - 1] = temp1;

         for (int i = r - s; i < r + s; i++) {
            arr[i][c - s] = arr[i + 1][c - s];
         }
         arr[r + s - 1][c - s] = temp;
      }
   }// method
}