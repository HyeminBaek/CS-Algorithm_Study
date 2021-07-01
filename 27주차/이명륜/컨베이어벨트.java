import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main{
    static class Belt {
        int durability;
        boolean robotOn;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        st = new StringTokenizer(br.readLine());
        int n= Integer.parseInt(st.nextToken());
        int k =Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        Belt[] belts = new Belt[2*n];
        for(int i=0;i<2*n;i++) {
            belts[i] = new Belt();
            belts[i].robotOn=false;
        }

        for(int i=0;i<2*n;i++) {
            belts[i].durability = Integer.parseInt(st.nextToken());
            belts[i].robotOn=false;
        }

        int step = 1;
        for(;;step++){
            // 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다. 내리는 위치에 있는 로봇은 내린다.
            int offBeltDurability = belts[n-1].durability;    //n th
            //int onBeltDurability = belts[2*n-1].durability; //2n th

            //윗벨트
            for(int i=n-2;i>=0;i--){
                belts[i+1].robotOn=belts[i].robotOn;
                belts[i+1].durability = belts[i].durability;
            }

            //아랫벨트
            for(int i=2*n-1;i>=n;i--){
                int next = (i+1)%(2*n);
//                belts[next].robotOn = belts[i].robotOn;
                belts[next].durability = belts[i].durability;
            }
            //이 부분이 헷갈렸음
            belts[n].durability = offBeltDurability;
            belts[n].robotOn=false;
            belts[0].robotOn=false;
            belts[n-1].robotOn=false;
            

            // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.
            // 만약 이동할 수 없다면 가만히 있는다
                // 로봇이 내리는 위치가 아니고, 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
            for(int i=n-2;i>=0;i--){
                if(belts[i+1].robotOn) continue;
                if(belts[i+1].durability==0) continue;
                if(belts[i].robotOn==false) continue;

                //belts[i+1].robotOn=belts[i].robotOn;
                belts[i+1].robotOn=true;
                belts[i].robotOn=false;
                belts[i+1].durability-=1;
            }

            // 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
            if(belts[0].durability!=0) {
                belts[0].robotOn=true;
                belts[0].durability-=1;
            }

            // 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
            int zeroDurabilityCnt=0;
            for(int i=0;i<2*n;i++){
                if(belts[i].durability==0) zeroDurabilityCnt++;
            }

//            for(int i=0;i<2*n;i++) System.out.print(belts[i].durability+" ");
//            System.out.println();
//            for(int i=0;i<2*n;i++) System.out.print(belts[i].robotOn+" ");
//            System.out.println();
            if(zeroDurabilityCnt>=k) break;
        }

        System.out.println(step);
    }
}
