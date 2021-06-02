package AL_CS_STUDY.Weekly23;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class IcyBreaking {
    static int n,s,p;
    static ArrayList<Integer> ice[];
    static ArrayList<Integer> list=new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        s=Integer.parseInt(st.nextToken());
        p=Integer.parseInt(st.nextToken());
        ice=new ArrayList[n+1];
        for (int i = 0; i < n+1; i++) {
            ice[i]=new ArrayList<>();
        }
        for (int i = 0; i < n-1; i++) {
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            ice[a].add(b);
            ice[b].add(a);
        }
        DFS(p,-1,0);
        System.out.println(list);
        Collections.sort(list);
        System.out.println(list);
        System.out.println(n-list.get(0)-list.get(1)-1);
    }

    private static void DFS(int cur, int parent, int cnt) {
        if(1<= cur && cur<=s)
        {
            list.add(cnt);
            return;
        }
        for (int i = 0; i < ice[cur].size(); i++) {
            int next=ice[cur].get(i);
            if(next!= parent)
            {
                DFS(next,cur,cnt+1);
            }
        }
    }

}
