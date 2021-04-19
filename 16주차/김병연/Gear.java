package AL_CS_STUDY.Weekly16;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Gear {
    static int gear[][];
    static int valid[];
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        gear=new int[4][8];
        StringTokenizer st;
        for (int i = 0; i < 4; i++) {
            String str[]=br.readLine().split("");
            for (int j = 0; j < 8; j++) {
                gear[i][j]=Integer.parseInt(str[j]);
            }
        }
        // [i][idx]  ==  idx=2 6
        //1 시계 , -1 반시계
        int rotate=Integer.parseInt(br.readLine());
        while (rotate-->0)
        {
            valid=new int[4];
            st=new StringTokenizer(br.readLine());
            int gearNumber=Integer.parseInt(st.nextToken());
            int dir=Integer.parseInt(st.nextToken());
            check(gearNumber-1,dir);
            rotate(valid);

        }
        int sum=0;
        for (int i = 0; i < 4; i++) {
            if(gear[i][0]!=0)
                sum+=Math.pow(2,i);
        }
        System.out.println(sum);

    }
    static void check(int gearNumber, int direction)
    {
        valid[gearNumber]=direction;
        int l=gearNumber-1;
        int r=gearNumber+1;
        if(l>=0 && valid[l]==0)
        {
            if(gear[l][2]!=gear[gearNumber][6])
            {
                check(l,direction*-1);
            }
        }
        if(r<=3 && valid[r]==0)
        {
            if(gear[r][6]!=gear[gearNumber][2])
                check(r,direction*-1);
        }
    }
    static void rotate(int[] valid)
    {
        for (int i = 0; i < 4; i++) {
            if(valid[i]!=0)
            {
                int [] temp=new int[8];
                int idx;
                for (int j = 0; j < 8; j++) {
                    idx=j+valid[i];
                    if(idx==-1)
                        idx=7;
                    else if(idx==8)
                        idx=0;

                    temp[idx]=gear[i][j];
                }
                gear[i]=temp;
            }
        }
    }

}
/*
0 = {int[8]@814} [0, 1, 0, 1, 1, 1, 1, 1]
        1 = {int[8]@815} [1, 0, 1, 1, 1, 1, 1, 0]
        2 = {int[8]@816} [0, 1, 1, 0, 0, 1, 1, 1]
        3 = {int[8]@817} [0, 0, 0, 0, 0, 1, 0, 0]*/
/*
0 = {int[8]@978} [1, 1, 0, 1, 0, 1, 1, 1]
1 = {int[8]@979} [1, 1, 1, 1, 1, 0, 1, 0]
2 = {int[8]@980} [1, 1, 0, 0, 1, 1, 1, 0]
3 = {int[8]@981} [0, 0, 0, 0, 0, 0, 0, 1]
* */
