import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] map = new int[200][200];
        int[][] DIRS = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int[] origin = new int[]{100, 100};
        int radius = (n - 1) / 2;

        //answer
        int[] explodedCnt = new int[3];

        for (int r = origin[0] - radius; r <= origin[0] + radius; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = origin[1] - radius; c <= origin[1] + radius; c++) {
                map[r][c] = Integer.parseInt(st.nextToken());
            }
        }

        for (int tt = 0; tt < m; tt++) {
            st = new StringTokenizer(br.readLine());
            int dir = Integer.parseInt(st.nextToken()) - 1;
            int dist = Integer.parseInt(st.nextToken());

            //1. 파괴
            for (int d = 0; d <= dist; d++) {
                int nr = origin[0] + DIRS[dir][0] * d;
                int nc = origin[1] + DIRS[dir][1] * d;

                map[nr][nc] = 0;
            }

            List<Integer> marbles = new ArrayList<>();
            int nowRow = origin[0];
            int nowCol = origin[1];

            //나선 모양으로 움직이며 리스트에 다 담기
            for (int lap = 1; lap <= radius; lap++) {
                int minRow = origin[0] - lap;
                int maxRow = origin[0] + lap;
                int minCol = origin[1] - lap;
                int maxCol = origin[1] + lap;

                for (; nowCol > minCol; nowCol--) marbles.add(map[nowRow][nowCol]);
                for (; nowRow < maxRow; nowRow++) marbles.add(map[nowRow][nowCol]);
                for (; nowCol < maxCol; nowCol++) marbles.add(map[nowRow][nowCol]);
                for (; nowRow > minRow; nowRow--) marbles.add(map[nowRow][nowCol]);
                for (; nowCol > minCol; nowCol--) marbles.add(map[nowRow][nowCol]);
            }

            marbles.removeIf(x -> x == 0);  //구슬이 파괴된 것은 제거
            if (marbles.isEmpty()) break;

            //2.폭발 단계
            while (true) {
                boolean exploded = false;
                int recent = marbles.get(0);
                int recentCnt = 1;
                List<Integer> tmpMarbles = new ArrayList<>();

                for (int i = 1; i < marbles.size(); i++) {
                    int here = marbles.get(i);

                    if (here == recent) {
                        recentCnt++;
                    } else {
                        if (recentCnt < 4) {
                            for (int j = 0; j < recentCnt; j++) tmpMarbles.add(recent);

                        } else {
                            exploded = true;
                            explodedCnt[recent - 1] += recentCnt;
                        }
                        recent = here;
                        recentCnt = 1;
                    }
                }

                if (recentCnt < 4) {
                    for (int j = 0; j < recentCnt; j++) tmpMarbles.add(recent);
                } else {
                    exploded = true;
                    explodedCnt[recent - 1] += recentCnt;
                }

                marbles.clear();
                marbles.addAll(tmpMarbles);
                if (exploded == false || marbles.isEmpty()) break;
            }

            if (marbles.isEmpty()) break;

            // 3. 구슬이 두 그룹으로 변하는 단계
            int recent = marbles.get(0);
            int recentCnt = 1;
            List<Integer> convertedMarbles = new ArrayList<>();

            for (int i = 1; i < marbles.size(); i++) {
                int here = marbles.get(i);

                if (here == recent) {
                    recentCnt++;
                } else {
                    convertedMarbles.add(recentCnt);
                    convertedMarbles.add(recent);

                    recent = here;
                    recentCnt = 1;
                }
            }

            convertedMarbles.add(recentCnt);
            convertedMarbles.add(recent);

            nowRow = origin[0];
            nowCol = origin[1];
            convertedMarbles.add(0, 0);

            //맵을 초기화시켜놓고
            for (int r = origin[0] - radius; r <= origin[0] + radius; r++) {
                for (int c = origin[1] - radius; c <= origin[1] + radius; c++) {
                    map[r][c] = 0;
                }
            }

            //나선 모양으로 움직이며 리스트에서 맵으로 옮겨 넣기
            for (int lap = 1, idx = 0; lap <= radius; lap++) {
                try {
                    int minRow = origin[0] - lap;
                    int maxRow = origin[0] + lap;
                    int minCol = origin[1] - lap;
                    int maxCol = origin[1] + lap;

                    for (; nowCol > minCol; nowCol--, idx++) map[nowRow][nowCol] = convertedMarbles.get(idx);
                    for (; nowRow < maxRow; nowRow++, idx++) map[nowRow][nowCol] = convertedMarbles.get(idx);
                    for (; nowCol < maxCol; nowCol++, idx++) map[nowRow][nowCol] = convertedMarbles.get(idx);
                    for (; nowRow > minRow; nowRow--, idx++) map[nowRow][nowCol] = convertedMarbles.get(idx);
                    for (; nowCol > minCol; nowCol--, idx++) map[nowRow][nowCol] = convertedMarbles.get(idx);
                } catch (IndexOutOfBoundsException indexException) {
                    break;
                } catch (Exception exception) {
                    System.err.println("never!");
                }
            }
        }

        int answer = 0;

        for (int i = 0; i < 3; i++) {
            answer += explodedCnt[i] * (i + 1);
        }
        System.out.println(answer);

    }
}
