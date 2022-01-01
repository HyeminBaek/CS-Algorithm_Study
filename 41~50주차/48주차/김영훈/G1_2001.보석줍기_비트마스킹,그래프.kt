import java.util.*
import kotlin.collections.ArrayList
import kotlin.collections.HashMap

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class Data(val dest: Int, val bit: Int, val num: Int)
    data class Edge(val dest: Int, val cap: Int)
    val (N, M, K) = br.readLine().split(' ').map { it.toInt() }
    val jMap = HashMap<Int, Int>()
    val visit = Array(N) { Array(1 shl K) { -1 } }
    val adjList = Array(N) { ArrayList<Edge>() }
    repeat(K) { idx -> jMap[br.readLine().toInt() - 1] = idx }
    repeat(M) {
        val (a, b, c) = br.readLine().split(' ').map { it.toInt() }
        adjList[a - 1].add(Edge(b - 1, c))
        adjList[b - 1].add(Edge(a - 1, c))
    }

    val queue: Queue<Data> = LinkedList()
    visit[0][0] = 0
    queue.add(Data(0, 0, 0))
    while (queue.isNotEmpty()) {
        val nowData = queue.poll()
        for (next in adjList[nowData.dest]) {
            var nbit = nowData.bit
            var nnum = nowData.num
            if (visit[next.dest][nbit] == -1 && next.cap >= nnum) {
                visit[next.dest][nbit] = nnum
                queue.add(Data(next.dest, nbit, nnum))
            }

            if (!jMap.containsKey(next.dest)) continue
            nbit = nbit or (1 shl jMap[next.dest]!!)
            if (visit[next.dest][nbit] == -1 && next.cap >= nnum) {
                visit[next.dest][nbit] = nnum + 1
                queue.add(Data(next.dest, nbit, nnum + 1))
            }
        }
    }
    bw.write(visit[0].maxOf { it }.toString() + "\n")
    bw.close()
}