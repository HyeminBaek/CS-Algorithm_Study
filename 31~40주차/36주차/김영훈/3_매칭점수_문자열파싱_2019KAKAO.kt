class Solution {
    lateinit var _word:String
    var _pages=ArrayList<String>()
    lateinit var Score1:Array<Int>
    val URIMap=HashMap<String,Int>()
    lateinit var LinkScore:Array<Double>
    fun isAlp(c:Char):Boolean{
        return c>='a' && c<='z'
    }

    fun getScore1(){
        _pages.forEachIndexed{idx,html->
            var str=""
            html.forEach{c->
                when(isAlp(c)){
                    true->str+=c
                    else->{
                        if(str==_word) Score1[idx]++
                        str=""
                    }
                }

            }

        }
    }
    fun getURI(){
        _pages.forEachIndexed{idx,html->
            URIMap[html.substringAfter("meta property=\"og:url\" content=\"").substringBefore("\"/>")]=idx
        }
    }
    fun getLinkScore(){
        _pages.forEachIndexed{idx,html->
            val nstr=html.split("<a href=\"")

            for(i in 1..nstr.size-1){
                val uri=nstr[i].substringBefore("\">")
                if(URIMap[uri]!=null){
                    LinkScore[URIMap[uri]!!]=LinkScore[URIMap[uri]!!]+(Score1[idx].toDouble())/(nstr.size-1)
                }

            }


        }
    }
    fun solution(word: String, pages: Array<String>): Int {
        var answer = 0

        _word=word.toLowerCase()
        Score1=Array<Int>(pages.size){0}
        pages.forEach{_pages.add(it.toLowerCase())}
        getScore1()

        getURI()

        LinkScore=Array<Double>(pages.size){0.0}
        getLinkScore()

        var ansScore=0.0
        (0..pages.size-1).forEach{
            val nscore=Score1[it].toDouble()+LinkScore[it]
            if(nscore>ansScore){
                ansScore=nscore
                answer=it
            }
        }

        return answer
    }
}