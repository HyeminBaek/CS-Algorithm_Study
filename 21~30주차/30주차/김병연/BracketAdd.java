package AL_CS_STUDY.Weekly30;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
//https://www.acmicpc.net/problem/16637
public class BracketAdd {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        String equation=br.readLine();
        int asnwer= solution(n,equation);
        System.out.println(answer);
    }
    static int answer=Integer.MIN_VALUE;
    static List<Integer> numbers=new LinkedList<>();
    static List<Character> operations=new LinkedList<>();
    static int operationsSize =0;
    private static int solution(int n, String equation) {
        for (int i = 0; i < equation.length(); i++) {
            if(i%2==0)
                numbers.add(equation.charAt(i)-'0');
            else
                operations.add(equation.charAt(i));
        }
        operationsSize =operations.size();
        dfs(0,numbers.get(0));
        return answer;
    }
    static void dfs(int cnt,int sum)
    {
        if(cnt== operationsSize)
        {
            answer=Math.max(answer,sum);
            return;
        }
        int notBracket=calc(cnt,sum, numbers.get(cnt+1));
        dfs(cnt+1,notBracket);
        if(cnt+1< operationsSize)
        {
            int isBracket =calc(cnt+1,numbers.get(cnt+1),numbers.get(cnt+2));
            int result=calc(cnt,sum,isBracket);
            dfs(cnt+2,result);
        }
    }

    private static int calc(int operationIdx, int value1, Integer value2) {
        switch (operations.get(operationIdx))
        {
            case '+':
                return value1+value2;
            case '-':
                return value1-value2;
            case '*':
                return value1*value2;
            default:
                return -1;
        }
    }
}
