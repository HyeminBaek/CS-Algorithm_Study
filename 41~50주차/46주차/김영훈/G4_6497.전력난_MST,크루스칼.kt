import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.collections.ArrayList

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val edgeList = ArrayList<Triple<Int, Int, Int>>()
    val par = Array(200000) { it }
    val d=Array(200000){0}
    val reset = { m: Int ->
        edgeList.clear()
        repeat(m) {
            par[it] = it
            d[it]=0
        }
    }

    fun find(a:Int):Int{
        if(par[a]!=a) {
            par[a]=find(par[a])
        }
        return par[a]
    }

    fun union(a:Int, b:Int):Boolean{
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
    var mn = br.readLine().split(' ').map { it.toInt() }
    while (mn[0] != 0 && mn[1] != 0) {
        reset(mn[0])
        repeat(mn[1]) {
            br.readLine().split(' ').map { it.toInt() }.run { edgeList.add(Triple(get(0), get(1), get(2))) }
        }

        edgeList.sortWith { a: Triple<Int, Int, Int>, b: Triple<Int, Int, Int> ->
            when {
                a.third > b.third -> 1
                a.third < b.third -> -1
                else -> 0
            }
        }
        var ans=edgeList.sumOf{it.third}
        for(i in 0 until mn[1]){
            if(union(edgeList[i].first,edgeList[i].second)) ans-=edgeList[i].third
        }

        bw.write(ans.toString()+"\n")
        mn = br.readLine().split(' ').map { it.toInt() }
    }
    bw.flush()
}