package AL_CS_STUDY.Weekly18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class ChickenDelivery {
    static class Node{
        private int y, x;

        public Node(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "y=" + y +
                    ", x=" + x +
                    '}';
        }
    }
    static int map[][];
    static ArrayList<Node> house;
    static ArrayList<Node> chicken;
    static int m;
    static int min=Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String s[]=br.readLine().split(" ");
        int n=Integer.parseInt(s[0]);
         m=Integer.parseInt(s[1]);
         map=new int[n+1][n+1];
         house=new ArrayList<>();
         chicken=new ArrayList<>();
        pick=new Node[m];
        for (int i = 1; i < n+1; i++) {
            s=br.readLine().split(" ");
            for (int j = 1; j < n+1; j++) {
                map[i][j]=Integer.parseInt(s[j-1]);
                if(map[i][j]==1)
                    house.add(new Node(i,j));
                else if(map[i][j]==2)
                    chicken.add(new Node(i,j));
            }
        }
        pickChicken(0,0);
        System.out.println(min);
    }
    static Node [] pick;
    static void pickChicken(int cnt,int idx)
    {
        if(cnt==m)
        {
           min=Math.min(min, calc());
            return;
        }

        for (int i = idx; i < chicken.size(); i++) {
            Node cur = chicken.get(i);
            pick[cnt]=new Node(cur.y,cur.x);
            pickChicken(cnt+1,i+1);
        }
    }
    static int calc(){
        int sum=0;

            int max=Integer.MAX_VALUE;
            for (int j = 0; j < house.size(); j++) {
                Node hou = house.get(j);
                max=Integer.MAX_VALUE;
                for (int i = 0; i < m; i++) {
                    Node ch = pick[i];
                    max= Math.min(max,Math.abs(ch.y-hou.y)+Math.abs(ch.x-hou.x));
                }
                sum+=max;
            }
        return sum;
    }

}
