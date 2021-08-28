import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

class Solution {
    public String[] solution(String[] record) {
        String[] answer;
        
        Map<String,String> map = new HashMap<String,String>();
        
        int cnt =0;
        
        for(int i=0;i<record.length;i++) {
        	StringTokenizer st = new StringTokenizer(record[i]," ");
        	
        	String oper = st.nextToken(),uId=st.nextToken();

        	if(oper.equals("Leave")) {
        		cnt+=1; continue;
        	}
        	
        	String nick=st.nextToken();
        	if(oper.equals("Enter")) {
        		cnt+=1; map.put(uId, nick);
        	}
        	else if(oper.equals("Change")) map.put(uId, nick);
        }
        int size= 0;
        answer = new String[cnt];
        
        for(int i=0;i<record.length;i++) {
        	StringTokenizer st = new StringTokenizer(record[i]);
        
        	String oper = st.nextToken(),uId=st.nextToken();
        	if(oper.equals("Change")) continue;
        	
        	if(oper.equals("Enter")) answer[size++]=map.get(uId)+"님이 들어왔습니다.";
        	else if(oper.equals("Leave")) answer[size++]=map.get(uId)+"님이 나갔습니다.";
        }
        
        return answer;
    }
    
}