import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        //완탐하면 되겠다
        // 수식의 길이가 20도 안되니까 숫자는 많아야 10개도 안되고
        // 괄호 안에 괄호가 안된다 했으니까 단순히 각 항들의 우선순위만 정해주면 자연스레 모든 경우를 포함한다?
        // 근데 필요충분이려나.. 왼쪽 먼저랬는데
        // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx아니다 xxxxxxxxxxxxxxxxxxxxxxx

        //연산자 우선순위가 없고 왼쪽 우선순위니까
        //괄호가 없으면 무조건 처음부터 계산하면 된다

        //지금 젤 앞에 있는 연산을
        // 1. 젤 앞을 연산한다
        // == 지금 연산을 먼저 한다
        // 2. 젤 앞을 연산하지 않는다
        // == 뒤에가 괄호다?

        len = Integer.parseInt(br.readLine());
        expr = br.readLine();

        dfs(1, expr.charAt(0) - '0');

        System.out.println(answer);
    }

    private static int len, answer = -(int) 1e9;
    private static String expr;

    private static void dfs(int idx, int nowValue) {
        if (idx > len) {
            return;
        } else if (idx == len) {
            answer = Math.max(answer, nowValue);
            return;
        }

        char operator = expr.charAt(idx);
        int num1 = expr.charAt(idx + 1) - '0';
        //System.out.println(idx+" "+num1+" "+operator+" "+nowValue);

        //1. 지금 계산하기 (지금꺼에 괄호 침)
        int nxtValue = nowValue;
        if (operator == '+') nxtValue += num1;
        else if (operator == '-') nxtValue -= num1;
        else if (operator == '*') nxtValue *= num1;

        dfs(idx + 2, nxtValue);

        //2. 지금 계산 안 하고 지금 다음꺼를 계산하기. ( 다음꺼에 괄호 침)
        if (idx + 3 < len) {
            nxtValue = nowValue;

            char operator2 = expr.charAt(idx + 2);
            int num2 = expr.charAt(idx + 3) - '0';

            int operatedValue = num1;
            if (operator2 == '+') operatedValue += num2;
            else if (operator2 == '-') operatedValue -= num2;
            else if (operator2 == '*') operatedValue *= num2;

            if (operator == '+') nxtValue += operatedValue;
            else if (operator == '-') nxtValue -= operatedValue;
            else if (operator == '*') nxtValue *= operatedValue;

            dfs(idx + 4, nxtValue);
        }
    }

}
