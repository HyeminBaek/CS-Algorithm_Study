import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        //가장 아래의 주사위를 어떻게 하냐에 따라 위에것들의 수직 방향이 결정되고 수평방향은 맘대로 조정 가능하다
        //수평 방향도 가장 아래에 있는 주사위의 옆면 중에  가장 큰 숫자에 이어서 최대화시키는 것이 최적일 것

        int n= Integer.parseInt(br.readLine());

        int[][] besides = new int[n+1][7];
        List<Integer>[] list = new ArrayList[n];

        for(int i=0;i<n;i++){
            st= new StringTokenizer(br.readLine());
            List<Integer> line = new ArrayList<>();
            for(int j=0;j<6;j++){
                line.add(Integer.parseInt(st.nextToken()));
            }

            besides[i][line.get(0)]=line.get(5);
            besides[i][line.get(5)]=line.get(0);

            besides[i][line.get(1)]=line.get(3);
            besides[i][line.get(3)]=line.get(1);

            besides[i][line.get(2)]=line.get(4);
            besides[i][line.get(4)]=line.get(2);

            list[i] = line;
        }


        int nowBot=0;
        int nowTop=0;
        int maxSum =0;

        for(int firstBot=1;firstBot<=6;firstBot++){
            nowBot = firstBot;
            nowTop = besides[0][nowBot];
            int sum=0;

            for(int i=0;i<n;i++){
                List<Integer> line = new ArrayList<>();
                for(int j=0;j<6;j++) {
                    if(list[i].get(j)==nowBot || list[i].get(j)==nowTop) continue;
                    line.add(list[i].get(j));
                }

                line.sort(Integer::compareTo);
                sum+=line.get(line.size()-1);
                nowBot = nowTop;
                nowTop = besides[i+1][nowBot];
            }
            maxSum=Math.max(maxSum,sum);
        }

        System.out.println(maxSum);


//        for(int i=0;i<n;i++){
//            System.out.println(list[i]);
//        }



    }
}

