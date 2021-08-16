import java.io.BufferedReader;//버퍼드리더 사용
import java.io.InputStreamReader;//인풋스트림리더 사용
import java.util.StringTokenizer;//스트링토크나이저 사용

public class Main { //클래스 시작
	private static StringBuilder button, cur;//버튼을 담기 위한 스트링빌더 변수들, 각각 만들어야 하는것과 현재 상태
	
	public static void main(String[] args) throws Exception{//메인함수 시작
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//입력.을 위해 객체 생성
		int N= Integer.parseInt(br.readLine()); //버튼의 개수 N을 입력받음
		
		button = new StringBuilder(); //객체 생성
		cur = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine());//띄어쓰기단위로 토큰 분할을 위해 토크나이저 사용
		for(int i=0;i<N;i++) {
			button.append(st.nextToken()); //입력으로 들어온 상태를 저장한다
			cur.append(0);//전부 꺼져있음을 표시하기 위해 0으로 초기화한다
		}
		System.out.print(solution());//최솟값을 구하는 solution 함수의 결과값을 출력한다.
	}
	
	private static int solution() {
		int cnt=0; //바뀐 횟수를 나타내는 변수
		
		for(int i=0;i<button.length();i++) { //만들어야 하는 버튼의 상태를  순차 탐색하면서 새 버튼을 같게 만들어 나감
			if(button.charAt(i)!=cur.charAt(i)) { //만약 현 상태와 다르다면
				cur.setCharAt(i, button.charAt(i));//버튼을 눌러 상태가 변화했음을 나타냄
				cnt+=1;//버튼 누른 횟수를 1회 추가해줌
				
				for(int j=1;j<=2;j++) { //오른쪽 2개도 같이 눌림을 표시
					if(i+j==button.length()) break; //인덱스를 넘어가면 바로 break;
					
					char ch ='0';//기본 값을 0(꺼짐)으로 설정
					if(cur.charAt(i+j)=='0') ch = '1'; //만약 꺼져있다면 켜져야 하므로 1로 값을 변경
					
					cur.setCharAt(i+j, ch);//현재 상태를 바꿔준다
				}
			}
		}
		return cnt;//같게 만드는데 연산했던 횟수 리턴
	}
}//클래스 끝
