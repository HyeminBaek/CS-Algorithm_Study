class Solution {
    val isCandidate=Array<Boolean>(1 shl 8){false}
    fun Search(bit:Int,relation:Array<Array<String>>){
        val keySet=HashSet<String>()

        relation.forEach{
            var str=""
            for(i in 0..it.size-1){
                if((bit and (1 shl i)) !=0){
                    str+=it[i]+','
                }

            }
            keySet.add(str)
        }
        if(keySet.size==relation.size){
            isCandidate[bit]=true
        }
    }
    fun solution(relation: Array<Array<String>>): Int {
        for(i in 1..(1 shl relation[0].size)){
            Search(i,relation)
        }
        for(i in 1..(1 shl relation[0].size)){
            for(j in 1..i-1){
                if((i or j) == i && isCandidate[j]){

                    isCandidate[i]=false
                    break

                }


            }



        }

        return isCandidate.count{it}
    }
}