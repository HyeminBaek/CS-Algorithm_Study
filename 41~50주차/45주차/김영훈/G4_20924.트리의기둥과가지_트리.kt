import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, R) = br.readLine().split(' ').map { it.toInt() }
    val adjList = Array(N) { ArrayList<Pair<Int, Int>>() }

    repeat(N - 1) {
        br.readLine().split(' ').map { it.toInt() }.run {
            adjList[get(0)-1].add(Pair(get(1)-1, get(2)))
            adjList[get(1)-1].add(Pair(get(0)-1, get(2)))
        }
    }

    var flag = false
    val dist = Array(N) { -1 }
    val queue = LinkedList<Int>()

    dist[R - 1] = 0
    queue.add(R - 1)
    var l1 = 0
    while (queue.isNotEmpty()) {
        val now = queue.poll()
        if (!flag) l1 = dist[now]
        if (adjList[now].size > 2 || (now==R-1 && adjList[now].size>1)) flag = true

        adjList[now].forEach { edge ->
            if (dist[edge.first]==-1) {
                dist[edge.first] = edge.second + dist[now]
                queue.add(edge.first)
            }
        }

    }

    bw.write("$l1 ${dist.maxOf { it } - l1}\n")
    bw.flush()
}