import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        //네트워크 주소 : 시작 주소 , 앞의 32-m자리가 임의의 형태이고 뒤의 m자리가 0000000형태
        //네트워크 마스크 : 앞의 32-m자리가 1111... 뒤에 m자리가 000형태
        //20억가지 경우의수 다 해 볼수가 없으니까 이분탐색해야겠다

        //그래서 최소의 네트워크 주소, 최소의 네트워크 마스크를 구하면 되는것?
        //최소범위를 구해야하는건데
        //네트워크 주소랑 마스크는 한 세트. 어차피 m에 의해 결정되니까
        // 가장 작은 네트워크 주소를 구하면 끝인듯?
        //그럼 브루트포스로 모든 비트::32개에 대해 해보면 된다?

        ////////////////////////////////////////////////
        //그게 아니라 모든 아이피들의 상위 비트들의 최대 공통적인 부분구하면 그냥 끝이네

        int n=Integer.parseInt(br.readLine());

        int maxNetworkAddress = Integer.MAX_VALUE;

//        System.out.println(networkAddress);
//        System.out.println(networkAddress>>1);
//        System.out.println((1<<31)-1);
//        System.out.println(Integer.toBinaryString((1<<31)-1));

        List<String> binaryIps = new ArrayList<>();

        //입력받고 바이너리로로 변환
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine(),".");
            List<Integer> ipList = new ArrayList<>();
            for(int j=0;j<4;j++) ipList.add(Integer.parseInt(st.nextToken()));

            StringBuilder binary = new StringBuilder();

            for(int j=0;j<4;j++){
                int here=ipList.get(j);
                StringBuilder hereBinary = new StringBuilder();

                for(int k=0;k<8;k++){
                    hereBinary.append(here%2);
                    here/=2;
                }
                hereBinary.reverse();
                binary.append(hereBinary);
            }

            binaryIps.add(binary.toString());
        }
        binaryIps.sort(String::compareTo);

        //System.out.println(binaryIps);
        int addressLen=0;

        for(int i=0;i<32;i++){
            int here=binaryIps.get(0).charAt(i);
            boolean stop =false;

            for(int j=1;j<n;j++){
                int other = binaryIps.get(j).charAt(i);
                if(here!=other){
                    stop=true;
                    break;
                }
            }
            if(stop) break;
            addressLen=i+1;
        }

//        System.out.println(addressLen);


        StringBuilder address = new StringBuilder();

        for(int i=0;i<addressLen;i++){
            address.append(binaryIps.get(0).charAt(i));
        }
        for(int i=0;i<32-addressLen;i++) address.append(0);

//        System.out.println(address+" "+address.length());

        List<Integer> answerList= new ArrayList<>();

        for(int i=0;i<4;i++){
            int part=0;
            for(int j=i*8;j<i*8+8;j++){
                part*=2;
                part+=(address.charAt(j)-'0')%2;
            }
            answerList.add(part);
        }

        List<Integer> answerList2= new ArrayList<>();
        StringBuilder address2 = new StringBuilder();

        for(int i=0;i<addressLen;i++){
            address2.append(1);
        }
        for(int i=0;i<32-addressLen;i++) address2.append(0);

        for(int i=0;i<4;i++){
            int part=0;
            for(int j=i*8;j<i*8+8;j++){
                part*=2;
                part+=(address2.charAt(j)-'0')%2;
            }
            answerList2.add(part);
        }

        String networkAddress = answerList.stream().map(x->x.toString()).collect(Collectors.joining("."));

        String newworkMask = answerList2.stream().map(x->x.toString()).collect(Collectors.joining("."));

        System.out.println(networkAddress);
        System.out.println(newworkMask);


    }

}
