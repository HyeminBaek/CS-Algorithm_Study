import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList

private const val INF = 1 shl 30
fun main() {

    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (N, K, M) = br.readLine().split(' ').map { it.toInt() }

    val dist = Array(N + 1) { -1 }
    val connectedTube = Array(N + 1) { ArrayList<Int>() }
    val visit = Array(M) { false }

    val hyperTube = Array(M) { idx ->
        br.readLine().split(' ').map { str ->
            str.toInt().also { n ->
                connectedTube[n].add(idx)
            }
        }
    }


    val queue = LinkedList<Int>()
    dist[1] = 1
    queue.add(1)
    while (queue.isNotEmpty()) {
        val now = queue.poll()

        for (tubeNum in connectedTube[now]) {
            if (visit[tubeNum]) continue
            visit[tubeNum] = true
            for (dest in hyperTube[tubeNum]) {
                if (dist[dest] != -1) continue
                dist[dest] = dist[now] + 1
                queue.add(dest)
            }
        }

    }

    bw.write("${dist[N]}\n")
    bw.flush()

}