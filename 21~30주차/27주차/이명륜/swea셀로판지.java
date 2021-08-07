import java.util.*;
import java.io.*;
import java.io.FileInputStream;
 
/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
    public static void main(String args[]) throws Exception
    {
        /*
           아래의 메소드 호출은 앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
           여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
           이 코드를 프로그램의 처음 부분에 추가하면 이후 입력을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
           따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 메소드를 사용하셔도 좋습니다.
           단, 채점을 위해 코드를 제출하실 때에는 반드시 이 메소드를 지우거나 주석 처리 하셔야 합니다.
         */
        //System.setIn(new FileInputStream("res/input.txt"));
 
        /*
           표준입력 System.in 으로부터 스캐너를 만들어 데이터를 읽어옵니다.
         */
        //Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         
        int T;
        T=Integer.parseInt(br.readLine());
         
        /*
           여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
        */
 
        for(int test_case = 1; test_case <= T; test_case++)
        {
             
            int p,q,r;
            int lc,lr,rc,rr;
            StringTokenizer st = new StringTokenizer(br.readLine());
             
            p = Integer.parseInt(st.nextToken()) +1000;
            q= Integer.parseInt(st.nextToken())+1000;
            r= Integer.parseInt(st.nextToken());
             
            st = new StringTokenizer(br.readLine());
            lc= Integer.parseInt(st.nextToken())+1000;
            lr=   Integer.parseInt(st.nextToken())+1000;
            rc=  Integer.parseInt(st.nextToken())+1000;
            rr=   Integer.parseInt(st.nextToken())+1000;
            int R=r*r;
             
            StringBuilder answer = new StringBuilder("NN");
             
            //circle이 유일한 부분(red) 존재하는지
            //left 
            if(p-r <lc) answer.setCharAt(0,'Y');
            //right 
            if(p+r >rc) answer.setCharAt(0,'Y');
            //top
            if(q-r <lr) answer.setCharAt(0,'Y');  
            //bot   
            if(q+r >rr) answer.setCharAt(0,'Y');
             
            //사각형이 유일한 부분 존재하는지 == 원이 사각형을 완전히 포함하는지?
            //사각형의 꼭지점에서 원의 중심까지 거리
             
            List<Integer> dists = new ArrayList<>();
            dists.add((lc-p)*(lc-p) +(rr-q)*(rr-q) );
            dists.add((lc-p)*(lc-p) +(lr-q)*(lr-q));
            dists.add((rc-p)*(rc-p) +(lr-q)*(lr-q));
            dists.add((rc-p)*(rc-p) +(rr-q)*(rr-q));
             
            for(int d:dists){
                if(d>R) answer.setCharAt(1,'Y');
            }
             
            System.out.println("#"+test_case+" "+answer);
             
        }
    }
}
