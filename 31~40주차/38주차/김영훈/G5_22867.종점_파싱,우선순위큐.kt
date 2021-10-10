import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    val timeTable = ArrayList<Pair<Long, Long>>()
    (1..N).forEach { _ ->
        val t = br.readLine().split(' ').toTypedArray()
        val t1 = t[0].replace(":", "").replace(".", "").toLong()
        val t2 = t[1].replace(":", "").replace(".", "").toLong()
        timeTable.add(Pair(t1, t2))
    }

    timeTable.sortWith { a: Pair<Long, Long>, b: Pair<Long, Long> ->
        when {
            a.first > b.first -> 1
            a.first < b.first -> -1
            else -> 0
        }
    }

    val pq = PriorityQueue { a: Long, b: Long ->
        when {
            a > b -> 1
            a < b -> -1
            else -> 0
        }
    }
    var ans = 0
    timeTable.forEach {
        while (pq.isNotEmpty() && pq.peek() <= it.first) {
          pq.poll()
        }

        pq.add(it.second)
        ans = max(ans, pq.size)
    }
    bw.write(ans.toString())
    bw.flush()
}