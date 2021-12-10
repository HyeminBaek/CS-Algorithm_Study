import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val pos = Array(br.readLine().toInt()) { br.readLine().split(' ').map { it.toInt() } }.run {
        sortedWith { a: List<Int>, b: List<Int> ->
            when {
                a[0] > b[0] -> 1
                a[0] < b[0] -> -1
                else -> 0
            }
        }
    }
    var (L,P) = br.readLine().split(' ').map { it.toInt() }
    val pq = PriorityQueue { a: Int, b: Int ->
        when {
            a < b -> 1
            a > b -> -1
            else -> 0
        }
    }

    var now=0
    var ans=0
    for(next in pos){
        if(next[0]>=L) break
        while(pq.isNotEmpty() && P<next[0]-now){
            P+=pq.poll()
            ans++
        }
        if(P<next[0]-now) break
        P-=(next[0]-now)
        now=next[0]
        pq.add(next[1])
    }

    while(pq.isNotEmpty() && P<L-now){
        P+=pq.poll()
        ans++
    }
    if(P<L-now){
        ans=-1
    }

    bw.write(ans.toString()+"\n")
    bw.flush()
}