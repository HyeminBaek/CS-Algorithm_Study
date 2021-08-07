package AL_CS_STUDY.Weekly15;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class StartAndLink {
    static int n, ablity[][];
    static boolean team[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        team = new boolean[n];
        ablity=new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                ablity[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        pick(0,0);

        System.out.println(minDiff);

    }

    static int minDiff = 1001;

    public static void pick(int cnt, int idx) {
        if (cnt == (n / 2)) {
            int Diff = teamAblityCalculation();
            minDiff = Math.min(minDiff, Diff);
            return;
        }

        for (int i = idx; i < n; i++) {
            team[i] = true;
            pick(cnt + 1, i + 1);
            team[i] = false;
        }
    }

    private static int teamAblityCalculation() {
        int startTeam=0;
        int linkTeam=0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if(i==j) continue;
                if (team[i] && team[j]) {
                    startTeam+=(ablity[i][j]+ablity[j][i]);
                } else if(!team[i] && !team[j]){
                    linkTeam+=(ablity[i][j]+ablity[j][i]);
                }
            }
        }

        return Math.abs(startTeam-linkTeam);
    }

    // 0, 2,5 -> 2+5+5+1+1+3 == 17
    // 1,3,4 -> 3 + 4 + 4 +1+1+2= 15
    // ans =2;
}
