package AL_CS_STUDY.Weekly34;
import java.io.*;

public class MischiefYounghoon {
    static long K;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        char[] arr = br.readLine().toCharArray();
        int[] num = new int[arr.length];

        int cnt = 0;
        for (int i = arr.length - 1; i >= 0; i--) {
            if (arr[i] == '1' || arr[i] == '2' || arr[i] == '6' || arr[i] == '7') {
                // 위치 및 개수 저장
                num[cnt++] = i;
                // 67이면 12로 바꾸기
                if (arr[i] == '6')
                    arr[i] = '1';
                else if (arr[i] == '7')
                    arr[i] = '2';
            }
        }

        K = Long.parseLong(br.readLine());
        K--;
        long numberOfCase = (long) Math.pow(2, cnt);

        // 범위 넘어갈 경우 out
        if (numberOfCase < K) {
            System.out.println(-1);
            return;
        }
        cnt = 0;
        while (K > 0) {
            // K를 2로 나누면서 나머지가 1이면 해당자리의 숫자를 바꿈
            if(K%2==1) {
                if (arr[num[cnt]] == '1')
                    arr[num[cnt]] = '6';
                else if (arr[num[cnt]] == '2')
                    arr[num[cnt]] = '7';
            }
            K/=2;
            cnt++;
        }

        for(char c : arr)
            sb.append(c);

        System.out.println(sb);
    }
}
