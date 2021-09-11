import java.util.*
class Solution {
    fun solution(N: Int, stages: IntArray): IntArray {
        var answer = intArrayOf(N)
        stages.sort()

        val temp=ArrayList<Pair<Int,Double>>()
        var idx=0
        for(i in 0..N-1){
            var num=0
            var num2=stages.size-idx
            while(idx<stages.size && stages[idx]==i+1){
                num++
                idx++
            }
            if(num2==0){
                temp.add(Pair(i+1,0.0))
            }else{
                temp.add(Pair(i+1,(num.toDouble())/num2))
            }
        }

        temp.sortWith(Comparator{a:Pair<Int,Double>,b:Pair<Int,Double> ->
            when{
                a.second>b.second -> -1
                a.second<b.second -> 1
                else->{
                    when{
                        a.first<b.first -> -1
                        a.first>b.first -> 1
                        else -> 0
                    }
                }

            }
        })
        answer=IntArray(N)
        for(i in 0..N-1){
            answer[i]=temp[i].first
        }
        return answer
    }
}