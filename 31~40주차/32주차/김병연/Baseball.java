package AL_CS_STUDY.Weekly32;

import java.io.*;
import java.util.StringTokenizer;

public class Baseball {

    private static int N;
    private static boolean v[];
    private static int[] lineOrder;
    private static int answer;
    private static int[][] players;

    // 타순이 좋은 순 오름차순?  1번 선수 고정 4번 대기자
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        players = new int[N + 1][10];
        StringTokenizer st;
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= 9; j++) {
                players[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        v = new boolean[10];
        lineOrder = new int[10];

        v[4] = true;
        lineOrder[4] = 1;

        answer = 0;
        permutation(2);
        System.out.println(answer);
    }

    static void permutation(int cnt) {
        if (cnt == 10) {
            play();
            return;
        }
        for (int i = 1; i <= 9; i++) {
            if (!v[i]) {
                v[i] = true;
                lineOrder[i] = cnt;
                permutation(cnt + 1);
                v[i] = false;
            }
        }
    }

    private static void play() {
        int score = 0;
        int startPlayer = 1;
        boolean base[];

        for (int i = 1; i <= N; i++) {
            int out = 0;
            base = new boolean[4];

            exit: while (true) {
                for (int j = startPlayer; j <= 9; j++) {

                    int behavior = players[i][lineOrder[j]];

                    switch (behavior) {
                        case 0:
                            out++;
                            break;
                        case 1:
                            for (int k = 3; k >= 1; k--) {
                                if (base[k]) {
                                    if (k == 3) {
                                        score++;
                                        base[k] = false;
                                        continue;
                                    }
                                    base[k] = false;
                                    base[k + 1] = true;
                                }
                            }
                            base[1] = true;
                            break;
                        case 2:
                            for (int k = 3; k >= 1; k--) {
                                if (base[k]) {
                                    if (k == 3 || k == 2) {
                                        score++;
                                        base[k] = false;
                                        continue;
                                    }
                                    base[k] = false;
                                    base[k + 2] = true;
                                }
                            }
                            base[2] = true;
                            break;
                        case 3:
                            for (int k = 3; k >= 1; k--) {
                                if (base[k]) {
                                    score++;
                                    base[k] = false;
                                }
                            }
                            base[3]=true;
                            break;

                        case 4:
                            for (int k = 3; k >= 1; k--) {
                                if (base[k]) {
                                    score++;
                                    base[k] = false;
                                }
                            }
                            score++;
                            break;
                    } // switch

                    if (out == 3) {
                        startPlayer = j + 1;
                        if (startPlayer == 10) {
                            startPlayer = 1;
                        }
                        break exit;
                    }
                } // for
                startPlayer = 1;
            } // while

        }
        answer = Math.max(answer, score);
    }
}
