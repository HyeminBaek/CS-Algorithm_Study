package AL_CS_STUDY.Weekly30;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
/*
https://www.acmicpc.net/problem/21611
격자의 가장 왼쪽 윗 칸은 (1, 1)이고, 가장 오른쪽 아랫 칸은 (N, N)
마법사 상어는 ((N+1)/2, (N+1)/2)
N = 홀수
1) 상어 위치에서 d 방향으로 si 구슬 파괴
2) 구슬 땡기기 (마지막 부터)
3) 연속하는 구슬 (4개 이상) 폭팔 (연속하는 구슬이 없을 때까지)
4) 그룹(연속하는 구슬들) 2칸으로 분류 1칸은 {구슬의 개수,그룹의 구슬 번호}
*/

public class WizardSharkBlizzard {
    static int dy[] = {-1, 1, 0, 0};
    static int dx[] = {0, 0, -1, 1};
    static int n, m, map[][], attacks[][];
    static int shark;
    static int summary;
    static ArrayList<Integer> list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        attacks = new int[m][2];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            attacks[i][0] = Integer.parseInt(st.nextToken());
            attacks[i][1] = Integer.parseInt(st.nextToken());
        }
        shark = n / 2;
        list = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int d = attacks[i][0];
            int s = attacks[i][1];
            list.clear();
            attack(d, s);
            move();
            remove();
            map=new int[n][n];
            devide();
        }
        System.out.println(summary);

    }

    private static void devide() {
        ArrayList<Integer> substitution = new ArrayList<>();
        int size = list.size();
        int sequenceCnt = 1;
        for (int i = 0; i < size - 1; i++) {
            if (list.get(i) == list.get(i + 1))
                sequenceCnt++;
            else {
                substitution.add(sequenceCnt);
                substitution.add(list.get(i));
                sequenceCnt = 1;
            }
        }
        if (size >= 1) {
            substitution.add(sequenceCnt);
            substitution.add(list.get(size - 1));
        }

        int cnt = 0;
        size = 1;
        int corner = 0;
        int dir = 2;
        int ny = shark;
        int nx = shark;
        int substitutionSize = substitution.size();
        int idx = 0;
        while (substitutionSize-- > 0) {
            cnt++;
            ny += dy[dir];
            nx += dx[dir];
            if (ny == 0 && nx == -1)
                break;

            map[ny][nx] = substitution.get(idx++);
            if (cnt == size) {
                corner++;
                dir = TransDirection(dir);
                cnt = 0;
            }
            if (corner == 2) {
                corner = 0;
                size++;
            }
        }
    }

    private static void remove() {
        int[][] removeList = new int[650][2];

        int size = list.size();
        int sequenceCnt = 1;
        int removeCnt = 0;
        boolean isRemove = false;
        for (int i = 0; i < size - 1; i++) {
            if (list.get(i) == list.get(i + 1))
                sequenceCnt++;
            else {
                if (sequenceCnt >= 4) {
                    removeList[removeCnt][0] = i + 1 - sequenceCnt;
                    removeList[removeCnt][1] = sequenceCnt;
                    removeCnt++;
                    isRemove = true;
                }
                sequenceCnt = 1;
            }
        }
        if (sequenceCnt >= 4) {
            removeList[removeCnt][0] = size - sequenceCnt;
            removeList[removeCnt][1] = sequenceCnt;
            removeCnt++;
            isRemove = true;
        }

        if (isRemove) {
            for (int k = removeCnt - 1; k >= 0; k--) {
                int start = removeList[k][0];
                int len = removeList[k][1];
                for (int j = 0; j < len; j++) {
                    summary += list.get(start);
                    list.remove(start);
                }
            }
            remove();
        }
//            if(isRemove)
//                remove();

    }

    private static void move() {
        int cnt = 0;
        int size = 1;
        int corner = 0;
        int dir = 2;
        int ny = shark;
        int nx = shark;
        while (true) {
            cnt++;
            ny += dy[dir];
            nx += dx[dir];
            if (ny == 0 && nx == -1)
                break;
            if (map[ny][nx] != 0) {
                list.add(map[ny][nx]);
            }
            if (cnt == size) {
                corner++;
                dir = TransDirection(dir);
                cnt = 0;
            }

            if (corner == 2) {
                corner = 0;
                size++;
            }

        }
    }

    public static int TransDirection(int d) {
        if (d == 2)
            return 1;
        else if (d == 1)
            return 3;
        else if (d == 3)
            return 0;
        else if (d == 0)
            return 2;
        return -1;
    }

    public static void attack(int direction, int moveDistance) {
        direction--;
        for (int i = 1; i <= moveDistance; i++) {
            int ny = shark + dy[direction] * i;
            int nx = shark + dx[direction] * i;
            if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                map[ny][nx] = 0;
            } else
                break;
        }
    }

    public static void snail(int n) {
        int arr[][] = new int[n][n];
        int print = n;
        int idx = 1;
        int right = -1;
        int bottom = 0;
        int transDirection = 1;
        for (int i = n; i > 1; i++) {

            for (int j = 0; j < print; j++) {
                right += transDirection;
                arr[bottom][right] = idx++;
            }
            print--;
            for (int j = 0; j < print; j++) {
                bottom += transDirection;
                arr[bottom][right] = idx++;
            }
            transDirection *= -1;
        }
        Arrays.stream(arr).forEach((int[] row) -> System.out.println(Arrays.toString(row)));
    }
}


