package AL_CS_STUDY.Weekly24;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

//
public class DiceYutGame {
    static class Node
    {
        int score;
        boolean isEmpty;
        boolean isFinish;
        Node next;
        Node anotherPath;

        public Node(int score) {
            this.score = score;
            this.isEmpty=true;
        }

        public Node add(int score)
        {
            Node next=new Node(score);
            this.next=next;
            return next;
        }
        public static Node get(Node start,int targetScore)
        {
            Node cur=start;
            while (true)
            {
                if(cur==null) return null;
                if(cur.score==targetScore) return cur;
                cur=cur.next;
            }
        }
    }
    static int dices[],orders[];
    static Node horses[];
    static int answer=-1;
    static Node start;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        dices=new int[10];
        orders=new int[10];
        horses=new Node[4];
        for (int i = 0; i < 10; i++) {
            dices[i]=Integer.parseInt(st.nextToken());
        }
        start=new Node(0);
        Node cur = start;
        for (int i = 2; i <= 40; i+=2) {
            cur=cur.add(i);
        }
        Node last = cur.add(0);
        last.isFinish=true;
        last.next=last;

        Node cross = new Node(25);

        cur=cross.add(30);
        cur=cur.add(35);
        cur.next=Node.get(start,40);

        cur = Node.get(start, 10);
        cur = cur.anotherPath = new Node(13);
        cur = cur.add(16);
        cur = cur.add(19);
        cur.next = cross;

        cur = Node.get(start, 20);
        cur = cur.anotherPath = new Node(22);
        cur = cur.add(24);
        cur.next = cross;

        cur = Node.get(start, 30);
        cur = cur.anotherPath = new Node(28);
        cur = cur.add(27);
        cur = cur.add(26);
        cur.next = cross;

        perm(0);
        System.out.println(Arrays.toString(orders));
        System.out.println(answer);
    }
    static void perm(int cnt)
    {
        if(cnt>=10)
        {
            answer=Math.max(answer,gameStart());
            return;
        }
        for (int i = 0; i < 4; i++) {
            orders[cnt]=i;
            perm(cnt+1);
        }
    }
    static int gameStart()
    {
        Arrays.fill(horses,start);

        int score=0;
        for (int i = 0; i < 10; i++) {
            Node cur = horses[orders[i]];
            cur.isEmpty=true;

            for (int j = 0; j < dices[i]; j++) {
                if(j==0 &&cur.anotherPath!=null)
                {
                    cur=cur.anotherPath;
                }
                else
                    cur=cur.next;
            }
            horses[orders[i]]=cur;
            if(!cur.isEmpty && !cur.isFinish)
            {
                score=0;
                break;
            }
            else
            {
                cur.isEmpty=false;
                score+=cur.score;
            }
        }
        for (int i = 0; i < 4; i++) {
            horses[i].isEmpty=true;
        }
        return score;

    }
}
