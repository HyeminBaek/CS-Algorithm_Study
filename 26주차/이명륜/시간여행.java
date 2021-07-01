import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

//매 쿼리마다 문제 목록에 기록되어 있는 가장 최근에 푼 문제를 출력하는 프로그램을 작성하시오
//그냥 시뮬레이션 하면...
// 메모리가 최대 8만*8만*4바이트 정도 필요한데 == 240*10^8바이트  = 100억 바이트 필요
// 그럼 t K의 경우, 현재-K 번째의 필요한 상태들만 저장해둘까
// 전부 t....t이면 ?

//직전 쿼리 결과에 비해서 증가,감소를 카운트할까
//어차피 증가,감소 아니면 어떤 시점으로 되돌아가기인데
//증가,감소는 간단한데 타임머신은..
//Map으로 캐싱도 하면 좋을거 같기도 하고 아닐거 같기도 하고
//그냥 시뮬하면 3e9정도 연산량 필요한데...

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer("");

        int n =Integer.parseInt(br.readLine());
        List<Integer>[] list = new ArrayList[n+1];
        for(int i=0;i<=n;i++) list[i] = new ArrayList<>();

        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            char op = st.nextToken().charAt(0);

            if(op=='a'){
                int num  = Integer.parseInt(st.nextToken());
                list[i+1].addAll(list[i]);
                list[i+1].add(num);
            }else if(op=='s'){
                list[i+1].addAll(list[i]);
                if(list[i+1].isEmpty()==false) list[i+1].remove(list[i+1].size()-1);

            }else if(op=='t'){
                int queryNum = Integer.parseInt(st.nextToken());
                list[i+1].addAll(list[queryNum-1]);
            }

            if(list[i+1].isEmpty()) System.out.println(-1);
            else System.out.println(list[i+1].get(list[i+1].size()-1));
//            System.out.println("here  : "+list[i+1]);
        }

    }
}
