class Solution {
    fun solution(record: Array<String>): Array<String> {
        var answer = arrayOf<String>()
        val nameMap=HashMap<String,String>()
        record.forEach{
            val splitStr=it.split(' ')


            if(splitStr[0]=="Change" || splitStr[0]=="Enter") nameMap[splitStr[1]]=splitStr[2]
            nameMap[splitStr[1]]= nameMap[splitStr[1]]?:splitStr[2]
        }
        val ans=ArrayList<String>()
        record.forEach{it->
            val splitStr=it.split(' ')
            when(splitStr[0]){
                "Enter"->ans.add("${nameMap[splitStr[1]]}님이 들어왔습니다.")
                "Leave"->ans.add("${nameMap[splitStr[1]]}님이 나갔습니다.")
            }
        }



        return ans.toTypedArray()
    }
}