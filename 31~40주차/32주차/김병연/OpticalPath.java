package AL_CS_STUDY.RealTimeSolving.Weekly32;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class OpticalPath {
    static class Node{
        private int x,y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static int n;
    static Node home,office,customers[];
    static boolean v[];
    static int min;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int testCase = 1; testCase <= t; testCase++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            String input[]=br.readLine().split(" ");
            home = new Node(Integer.parseInt(input[0]), Integer.parseInt(input[1]));
            office = new Node(Integer.parseInt(input[2]), Integer.parseInt(input[3]));
            customers=new Node[n];
            int idx=0;
            for (int i = 4; i < 4 + n * 2; i+=2) {
                customers[idx++]=new Node(
                        Integer.parseInt(input[i]), Integer.parseInt(input[i+1])
                );
            }
            min=Integer.MAX_VALUE;
            v=new boolean[n];
            permutation(0,home.x,home.y,0);
            int answer = min;
            sb.append("#").append(testCase).append(" ").append(answer).append("\n");
        }
        System.out.println(sb);
    }

    private static void permutation(int cnt, int x, int y, int distance) {
        if(cnt==n)
        {
            distance+=getDistance(x,y,office);
            min=Math.min(min,distance);
            return;
        }
        for (int i = 0; i < n; i++) {
            if(!v[i])
            {
                v[i]=true;
                permutation(cnt+1,customers[i].x,customers[i].y
                , distance+getDistance(x,y,customers[i]));
                v[i]=false;
            }
        }
    }
    private static int getDistance(int x,int y,Node nextTarget)
    {
        return Math.abs(x-nextTarget.x)+Math.abs(y-nextTarget.y);
    }

}
