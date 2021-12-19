import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    val sArr = Array(N) { br.readLine() }
    val (s, e) = br.readLine().split(' ').map { it.toInt() - 1 }

    val getDist = { s1: String, s2: String ->
        var ret = 0
        for (idx in s1.indices) {
            ret += (s1[idx].code - s2[idx].code)*(s1[idx].code-s2[idx].code)
        }
        ret
    }
    val pq = PriorityQueue<Pair<Int, Int>> { a, b ->
        when {
            a.second > b.second -> 1
            a.second < b.second -> -1
            else -> 0
        }
    }
    val distArr=Array(N){1 shl 30}
    distArr[s]=0
    pq.add(Pair(s,0))
    while(pq.isNotEmpty()){
        val now=pq.poll()
        if(now.second>distArr[now.first]) continue
        for(next in 0 until N){
            val nDist=distArr[now.first]+getDist(sArr[next],sArr[now.first])
            if(distArr[next]>nDist){
                distArr[next]=nDist
                pq.add(Pair(next,nDist))
            }
        }
    }
    bw.write(distArr[e].toString()+"\n")
    bw.close()
}