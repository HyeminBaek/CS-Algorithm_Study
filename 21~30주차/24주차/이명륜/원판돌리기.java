import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main{
    //전략 : 하라는 대로 시뮬레이션 하면 됨.
    // 까다로웠던 점
        // 1. 시계/반시계 회전시키기 약간 헷갈렸음
        // 2. Integer 타입끼리 비교할 때는 "=="로 비교하면 제대로 비교안됨. cache 때문에 ..
        //      따라서 equals로 비교해줘야 함!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // 3. 인접한 것이 없을 때 평균과 비교해서 지우거나 해야 하는데
        //      평균을 구하는 과정에서 전부 0이면 divide by zero 에러가 발생 할 수 있었음 !

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        int t=Integer.parseInt(st.nextToken());

        List<Integer>[] list = new ArrayList[n+1];
        for(int i=0;i<=n;i++) list[i]= new ArrayList<>();

        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                list[i].add(Integer.parseInt(st.nextToken()));
            }
        }

        for(int i=0;i<t;i++){
            st = new StringTokenizer(br.readLine());
            int x= Integer.parseInt(st.nextToken());
            int d= Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            int[][] erase = new int[n+1][m];

            //호가 xi의 배수인 원판을 di방향으로 ki칸 회전시킨다.
            for(int num=x;num<=n;num+=x){
                //di가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.
                List<Integer> tmp = new ArrayList<>();

                //회전시켜서 일단 임시 배열 tmp에 담기
                if(d==0){
                    for(int j=m-k,cnt=0;cnt<m;j++,j%=m,cnt++){
                        tmp.add(list[num].get(j));
                    }
                }else if(d==1){
                    for(int j=k,cnt=0;cnt<m;j++,j%=m,cnt++){
                        tmp.add(list[num].get(j));
                    }
                }

                for(int j=0;j<m;j++) list[num].set(j,tmp.get(j));

//                System.out.println(tmp);
            }

            for(int r=1;r<=n;r++){
                //안쪽 껍질의 인접한 것과 검사
                for(int j=0;j<m;j++){
                    if(r==1) continue;
                    if(list[r].get(j)==0) continue;

                    if(list[r].get(j).equals(list[r-1].get(j))){
                        erase[r-1][j]=1;
                        erase[r][j]=1;
                    }
                }


                //바깥 껍질의 인접한 것과 검사
                for(int j=0;j<m;j++){
                    if(r==n) continue;
                    if(list[r].get(j)==0) continue;
                    if(list[r].get(j).equals(list[r+1].get(j))){
                        erase[r+1][j]=1;
                        erase[r][j]=1;
                    }
                }

                //자신의 껍질에서 인접한 것과 검사
                for(int j=0;j<m;j++){
                    if(list[r].get(j)==0) continue;

                    if(list[r].get(j).equals(list[r].get((j+1)%m))){
                        erase[r][j]=1;
                        erase[r][(j+1)%m]=1;
                    }
                    if(list[r].get(j).equals(list[r].get((j+m-1)%m))){
                        erase[r][j]=1;
                        erase[r][(j+m-1)%m]=1;
                    }
                }
            }

            boolean nearExist=false;

            int tot=0;
            int existNumcnt=0;

        //그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
            for(int r=1;r<=n;r++){
                for(int j=0;j<m;j++){
                    if(list[r].get(j)==0) continue;

                    if(erase[r][j]==1){
                        nearExist=true;
                        list[r].set(j,0);
                        continue;
                    }

                    tot+=list[r].get(j);
                    existNumcnt++;
                }
            }

            //없는 경우에는 원판에 적힌 수의 평균을 구하고,
            // 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
            if(nearExist==false && existNumcnt!=0){
                int meanMok = tot/existNumcnt;
                int rest = tot%existNumcnt;
//                System.out.println("mean = "+mean);
//                System.out.println(tot+" "+existNumcnt);

                for(int r=1;r<=n;r++){
                    for(int j=0;j<m;j++) {
                        if(list[r].get(j)==0) continue;
                        int here= list[r].get(j);

                        if(here>meanMok) list[r].set(j,here-1);
                        else if(here==meanMok){
                            if(rest==0){
                                // do nothing ??
                            }
                            else list[r].set(j,here+1);
                        }
                        else list[r].set(j,here+1);
                    }
                }
            }
        }

        int total=0;
//        for(int i=1;i<=n;i++){
//            for(int j=0;j<m;j++){
//                System.out.print(list[i].get(j)+" ");
//            }
//            System.out.println();
//        }
//        System.out.println();

        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                total+=list[i].get(j);
            }
        }

        System.out.println(total);
    }

}
