package AL_CS_STUDY.Weekly24;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CircleRotate {
    static int dy[] = {-1, 1, 0, 0};
    static int dx[] = {0, 0, -1, 1};
    static int m, n, arr[][];
    static boolean isFind = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int order[][] = new int[t][3];

        for (int i = 0; i < t; i++) {
        st = new StringTokenizer(br.readLine());
            int xi = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            for (int j = 0; j < n; j++) {
                if ((j + 1) % xi == 0) {
                    if (d == 0) {
                        for (int number = 0; number < k; number++) {
                            int val = arr[j][m - 1];   // 2 5 2 4
                            for (int l = m-1; l >0; l--) {
                                arr[j][l] = arr[j][l - 1];
                            }
                            arr[j][0] = val;
                        }
                    } else {
                        for (int number = 0; number < k; number++) {
                            int val = arr[j][0];
                            for (int l = 0; l < m-1; l++) {
                                arr[j][l] = arr[j][l + 1];
                            }
                            arr[j][m - 1] = val;
                        }
                    }

                }
            }

            boolean isErased = false;
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < m; l++) {
                    isFind = false;
                    if (arr[j][l] != 0) {
                        dfs(j, l, arr[j][l]);
                    }
                    if (isFind){
                        arr[j][l] = 0;
                        isErased=true;
                    }
                }
            }
            if(!isErased)
            {
                double sum=0;
                int cnt=0;

                for (int j = 0; j < n; j++) {
                    for (int l = 0; l < m; l++) {
                        if(arr[j][l]!=0)
                        {
                            sum+=arr[j][l];
                            cnt++;
                        }
                    }
                }

                double avg=sum/cnt;

                for (int j = 0; j < n; j++) {
                    for (int l = 0; l < m; l++) {
                        if(arr[j][l]!=0 && arr[j][l]<avg)
                        {
                            arr[j][l]+=1;
                        }
                        else  if(arr[j][l]!=0 && arr[j][l]>avg)
                        {
                            arr[j][l]-=1;
                        }
                    }
                }
            }
        }
        int sum=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum+=arr[i][j];
            }
        }
        System.out.println(sum);


    }

    static void dfs(int y, int x, int number) {
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = (x + dx[i])%m;
            if (nx < 0) {
                nx = m - 1;
            }
            if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
                if (arr[ny][nx] == number) {
                    isFind=true;
                    arr[ny][nx]=0;
                    dfs(ny,nx,number);
                }
            }
        }
    }
}
