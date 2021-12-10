import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val N = br.readLine().toInt()
    val posArr = Array(3) { Array(N) { Pair(-1, -1L) } }
    repeat(N) { idx ->
        br.readLine().split(' ').forEachIndexed { pidx, n ->
            posArr[pidx][idx] = Pair(idx, n.toLong())
        }
    }
    posArr.forEach {
        it.sortWith { a, b ->
            when {
                a.second > b.second -> 1
                a.second < b.second -> -1
                else -> 0
            }
        }
    }
    val getAbs = { a: Long -> if (a < 0) -a else a }
    val edgeList = ArrayList<Triple<Int, Int, Long>>()
    for (i in 0 until 3) for (j in 0 until N - 1) {
        edgeList.add(
            Triple(
                posArr[i][j].first,
                posArr[i][j + 1].first,
                getAbs(posArr[i][j + 1].second - posArr[i][j].second)
            )
        )
    }
    edgeList.sortWith { a, b ->
        when {
            a.third > b.third -> 1
            a.third < b.third -> -1
            else -> 0
        }
    }

    val par=Array(N){it}
    val d=Array(N){0}
    fun find(a:Int):Int{
        if(a!=par[a]) par[a]=find(par[a])
        return par[a]
    }

    fun union(a:Int,b:Int):Boolean{
        val pa=find(a)
        val pb=find(b)
        if(pa==pb) return false
        if(d[pa]>d[pb]){
            par[pb]=pa
        }else if(d[pa]<d[pb]){
            par[pa]=pb
        }else{
            par[pb]=pa
            d[pa]++
        }
        return true
    }
    var ans=0L
    edgeList.forEach{
        if(union(it.first,it.second)) ans+=it.third
    }
    bw.write(ans.toString()+"\n")
    bw.flush()
}