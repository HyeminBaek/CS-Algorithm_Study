import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Long.max
import java.lang.Long.min
import java.util.LinkedList

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, M, K) = br.readLine().split(' ').map { it.toInt() }
    val timeArr = br.readLine().split(' ').map { it.toLong() }.toTypedArray()
    val inDeg = Array(N) { 0 }
    val outEdge = Array(N) { ArrayList<Int>() }
    val visit = Array(N) { 0 }
    val dist = Array(N) { -1L }
    val q = LinkedList<Int>()
    val comb = Array(K) { it + 1 }

    repeat(M) {
        br.readLine().split(' ').map { it.toInt() - 1 }.run {
            outEdge[get(0)].add(get(1))
            inDeg[get(1)]++
        }
    }

    var last=1
    for(i in 2 until N){
        if(outEdge[i].size==0){
            last=i
            break
        }
    }


    val reset = {
        visit.fill(0, 0, N)
        dist.fill(-1, 0, N)
    }


    val search = {
        dist[0] = timeArr[0]
        q.add(0)
        while (q.isNotEmpty()) {
            val now = q.poll()
            outEdge[now].forEach { next ->
                dist[next] = max(dist[next], dist[now] + if(next in comb) 0 else timeArr[next])
                visit[next]++
                if (visit[next] == inDeg[next]) q.add(next)
            }
        }
    }

    var ans = Long.MAX_VALUE

    while (true) {

        if(!comb.contains(last)) {
            reset()
            search()
            ans = min(ans, dist[last])
        }

        var idx = K - 1
        while (idx >= 0 && comb[idx] == N - 1 - K + 1 + idx) {
            idx--
        }

        if (idx == -1) break
        comb[idx]++
        for (j in idx + 1 until K) {
            comb[j] = comb[j - 1] + 1
        }
    }
    bw.write(ans.toString() + "\n")
    bw.flush()
}