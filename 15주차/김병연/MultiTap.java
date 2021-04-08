package AL_CS_STUDY.Weekly15;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class MultiTap {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str[] = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int k = Integer.parseInt(str[1]);
        int num[] = new int[k];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int cnt = 0;
        // 가장 늦게 나오
        int max=-1;
        for (int i = 0; i < k; i++) {
            int a = Integer.parseInt(st.nextToken());
            num[i] = a;
            max=Math.max(a,max);
        }
        // 뒤에 아무도 출연하지 않은 수 제거
        // 뒤에 모두 쓰이면 가장 나중에 쓰인것 찾기.
        boolean use[]=new boolean[max+1];
        int put=0;
        for (int i = 0; i < k; i++) {
            int number=num[i];
           if(!use[number])
           {
               if(put<n)
               {
                   use[number]=true;
                   put++;
               }
               else
               {
                   ArrayList<Integer> list=new ArrayList<>();
                   for (int j = i; j <k ; j++) {
                       if(use[num[j]]&& !list.contains(num[j])) // 콘센트에 꼽혀있고, 리스트에 들어가 있지 않으면 리스트에 추가.
                       {
                           list.add(num[j]);
                       }
                   }
                   if(list.size()!=n)
                   {
                       for (int j = 0; j < use.length; j++) {
                           if(use[j] && !list.contains(j)) // 나중에 사용 안할 것 같은 콘센트 제거.
                           {
                            use[j]=false;
                            break;
                           }
                       }
                   }
                   else
                   {
                       int pop=list.get(list.size()-1);
                       use[pop]=false;
                   }
                   use[number]=true;
                   cnt++;
               }
           }
        }
        System.out.println(cnt);
    }
}

/*
testcase 모음

2 7
2 3 2 3 1 2 7
답: 2

2 5
5 2 2 3 5
답: 1

2 4
5 3 1 5
답: 1

3 6
1 1 1 1 2 3
답: 0

3 8
1 2 3 4 1 1 1 2
답: 1

2 15
3 2 1 2 1 2 1 2 1 3 3 3 3 3 3
답: 2

1 3
1 2 1
답: 2
*/
