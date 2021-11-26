import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val minHeap = PriorityQueue<Pair<Int, Int>> { a, b ->
        when {
            a.second > b.second -> 1
            a.second < b.second -> -1
            else -> when {
                a.first > b.first -> 1
                a.first < b.first -> -1
                else -> 0
            }
        }
    }
    val maxHeap = PriorityQueue<Pair<Int, Int>> { a, b ->
        when {
            a.second < b.second -> 1
            a.second > b.second -> -1
            else -> when {
                a.first < b.first -> 1
                a.first > b.first -> -1
                else -> 0
            }
        }
    }

    val problemMap = HashMap<Int, Int>()
    val opRecommend = { x: Int ->
        if (x == 1) {
            while (problemMap[maxHeap.peek().first] != maxHeap.peek().second) maxHeap.poll()
            bw.write("${maxHeap.peek().first}\n")
        } else {
            while (problemMap[minHeap.peek().first] != minHeap.peek().second) minHeap.poll()
            bw.write("${minHeap.peek().first}\n")
        }
    }
    val opAdd = { P: Int, L: Int ->
        problemMap[P] = L
        minHeap.add(Pair(P, L))
        maxHeap.add(Pair(P, L))
    }
    val opSolved = { P: Int ->
        problemMap.remove(P)
    }
    val N = br.readLine().toInt()
    for (i in 1..N) {
        val (P, L) = br.readLine().split(' ').map { it.toInt() }
        opAdd(P, L)
    }
    val M = br.readLine().toInt()


    for (i in 1..M) {
        val query = br.readLine().split(' ')
        when (query[0][0]) {
            'r' -> opRecommend(query[1].toInt())
            'a' -> opAdd(query[1].toInt(), query[2].toInt())
            else -> opSolved(query[1].toInt())
        }
    }

    bw.flush()
}