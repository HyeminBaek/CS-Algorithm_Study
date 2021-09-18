import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList

data class Node(
    var indeg: Int = 0,
    var score: Int = 0,
    var pre: Int = -1,
    val adjlist: ArrayList<Pair<Int, Int>> = ArrayList()
)

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val N = br.readLine().toInt()
    val M = br.readLine().toInt()
    val nodes = Array(N) { Node() }
    (1..M).forEach { _ ->
        val info = br.readLine().split(' ').map { it.toInt() }
        nodes[info[0] - 1].adjlist.add(Pair(info[1] - 1, info[2]))
        nodes[info[1] - 1].indeg++
    }

    val q: Queue<Int> = LinkedList()
    q.add(0)
    while (q.isNotEmpty()) {
        val t = q.poll()
        nodes[t].adjlist.forEach {
            if (nodes[it.first].indeg == 0) return@forEach
            val nextNode = nodes[it.first]
            val nextScore = nodes[t].score + it.second
            nextNode.indeg--
            if (nextScore > nextNode.score) {
                nextNode.score = nextScore
                nextNode.pre = t
            }
            if (nextNode.indeg == 0) {
                q.add(it.first)
            }
        }
    }
    bw.write(nodes[0].score.toString() + "\n")
    val st = Stack<Int>()
    var pos = 0
    do {
        st.add(pos + 1)
        pos = nodes[pos].pre
    } while (pos != 0)
    st.add(1)
    while (st.isNotEmpty()) bw.write(st.pop().toString() + " ")
    bw.flush()
}