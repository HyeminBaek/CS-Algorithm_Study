    import java.io.*;
    import java.util.*;

    public class Main{
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer("");

            String infix= br.readLine(); //중위 표기식

            Map<Character,Integer> priorities = new HashMap<>();
            priorities.put('(',0);
            priorities.put(')',0);  //얘는 우선순위 필요없긴 한데..
            priorities.put('+',1);
            priorities.put('-',1);
            priorities.put('<',2);
            priorities.put('>',2);

            Set<Character> opeartors = new HashSet<>();
            opeartors.add('(');
            opeartors.add('+');
            opeartors.add('-');
            opeartors.add('<');
            opeartors.add('>');
            opeartors.add(')');

            Stack<Character> stack = new Stack<>();
            List<String> tokens = new ArrayList<>();
            String now="";

            for(int i=0;i<infix.length();i++){
                char here=infix.charAt(i);
                if(here=='+' || here=='-' || here=='(' || here==')'){
                    if(now.equals("")==false){
                        tokens.add(now);
                    }
                    tokens.add(""+here);
                    now="";
                }else if( here=='<' || here=='>' ){
                    if(now.equals("")==false){
                        tokens.add(now);
                    }
                    tokens.add(""+here+infix.charAt(i+1));
                    i++;
                    now="";
                }else{
                    now+=here;
                }
            }
            if(now.equals("")==false) tokens.add(now);

//            System.out.println(tokens);
            String postfix="";

            for(int i=0;i<tokens.size();i++){
                String token = tokens.get(i);
                if(opeartors.contains(token.charAt(0))){    //연산자,괄호
                    char operator=token.charAt(0);
                    int priorityHere=priorities.get(operator);

                    if(operator=='('){
                        stack.add(operator);
                        continue;
                    }else if(operator==')'){
                        while(stack.isEmpty()==false){
                            char stackTop = stack.pop();
                            if(stackTop=='(') break;
                            postfix+=stackTop;
                            if(stackTop=='<' || stackTop=='>') postfix+='?';
                            postfix+=" ";
                        }
                    }else { //+,-,<?,>?
                        while(stack.isEmpty()==false){
                            char stackTop = stack.pop();
                            if(priorities.get(stackTop) <priorityHere){
                                stack.add(stackTop);
                                break;
                            }else{
                                postfix+=stackTop;
                                if(stackTop=='<' || stackTop=='>') postfix+='?';
                            }
                            postfix+=" ";
                        }
                        stack.add(operator);
                    }
                }else{  //피연산자
                    postfix+=token;
                }
                postfix+=" ";
            }

            while(stack.isEmpty()==false) {
                char stackTop = stack.pop();
                postfix+=stackTop;
                if(stackTop=='<' || stackTop=='>') postfix+='?';
                postfix+=" ";
            }

//            System.out.println(postfix);

            st = new StringTokenizer(postfix," ");
            List<String> postfixTokens = new ArrayList<>();
            while(st.hasMoreTokens()) postfixTokens.add(st.nextToken());

//            System.out.println(postfixTokens);


            //후위표기식 계산
            Stack<String> stack2 = new Stack<>();   //to evaluate postfix expression

            for(int i=0;i<postfixTokens.size();i++){
                String token = postfixTokens.get(i);
                char firstChar = token.charAt(0);
                if(opeartors.contains(firstChar)){
                    long topNum1 = Long.parseLong(stack2.pop());
                    long topNum2 = Long.parseLong(stack2.pop());

                    if(token.equals("+")){
                        stack2.add(String.valueOf(topNum1+topNum2));
                    }else if(token.equals("-")){
                        stack2.add(String.valueOf(-topNum1+topNum2));
                    }else if(token.equals("<?")){
                        stack2.add(String.valueOf(Math.min(topNum1,topNum2)));
                    }else{
                        stack2.add(String.valueOf(Math.max(topNum1,topNum2)));
                    }
                }else{
                    stack2.add(token);
                }

//                System.out.println(token+" "+stack2);
            }
//            System.out.println(stack2);
            System.out.println(stack2.pop());

        }
    }
