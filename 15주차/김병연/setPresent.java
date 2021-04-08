package AL_CS_STUDY.Weekly15;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class setPresent {
    static int parent[];
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        parent=new int[n+1];
        for (int i = 0; i < n+1; i++) {
            parent[i]=i;
        }
        StringBuilder sb=new StringBuilder();
        for (int i = 0; i < m; i++) {
            st=new StringTokenizer(br.readLine());
            int symbol=Integer.parseInt(st.nextToken());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            if(symbol==0)
            {
                // union
                union(a,b);
            }
            else
            {
                if(find(a)==find(b))
                {
                    sb.append("YES").append("\n");
                }
                else {
                    sb.append("NO").append("\n");
                }
            }
        }
        System.out.println(sb);
    }

    public static void union(int a,int b)
    {
        a=find(a);
        b=find(b);

        if(a<b)
        {
            parent[b]=a;
        }
        else
            parent[a]=b;
    }

    public static int find(int a)
    {
        if(parent[a]==a)
            return a;
        return parent[a]=find(parent[a]);
    }
}
/*
3 3
0 1 2
0 1 3
1 2 3


1 2
0 0 1
1 0 1
reslt: NO

3 3
0 0 1
0 2 1
1 0 1
*/