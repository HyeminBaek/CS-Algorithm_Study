import java.util.*

class Solution {
    fun solution(food_times: IntArray, k: Long): Int {
        var answer = -1
        val foodtimes=ArrayList<Pair<Int,Long>>()
        food_times.forEachIndexed{index,time->
            foodtimes.add(Pair(index+1,time.toLong()))
        }

        foodtimes.sortWith(Comparator{a:Pair<Int,Long>,b:Pair<Int,Long>->
            when{
                a.second>b.second->1
                a.second<b.second->-1
                else->{
                    when{
                        a.first>b.first->1
                        a.first<b.first->-1
                        else->0
                    }
                }
            }
        })
        var eat:Long=0
        var nk=k+1
        for(i in 0..foodtimes.size-1){
            val foodnum=foodtimes.size-i
            if((foodtimes[i].second-eat) * foodnum>=nk){
                val sarr=foodtimes.subList(i,foodtimes.size)
                sarr.sortWith(Comparator{a:Pair<Int,Long>,b:Pair<Int,Long>->
                    when{
                        a.first>b.first->1
                        a.first<b.first->-1
                        else->0
                    }

                })

                answer=sarr[((foodnum+nk-1)%foodnum).toInt()].first

                break
            }else{
                nk-=(foodtimes[i].second-eat) * foodnum
                eat=foodtimes[i].second

            }


        }



        return answer
    }
}