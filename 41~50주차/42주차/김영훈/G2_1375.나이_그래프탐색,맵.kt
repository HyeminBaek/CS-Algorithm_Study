import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList
import kotlin.collections.HashMap

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val nameMap = HashMap<String,Int>()
    var idx = 0

    val (N, M) = br.readLine().split(' ').map { it.toInt() }

    val adjList = Array(N) { ArrayList<Int>() }
    for (i in 1..M) {
        val (a, b) = br.readLine().split(' ')
        if (!nameMap.containsKey(a)) nameMap[a] = idx++
        if (!nameMap.containsKey(b)) nameMap[b] = idx++
        val aIdx = nameMap.getValue(a)
        val bIdx = nameMap.getValue(b)

        adjList[aIdx].add(bIdx)
    }
    val Q = br.readLine().toInt()
    val visit = Array(N) { false }
    val q = LinkedList<Int>()
    val isOlder = { a: Int, b: Int ->
        q.clear()
        for (i in 0 until N) visit[i] = false
        visit[a] = true
        q.add(a)
        while (q.isNotEmpty()) {
            val pos = q.poll()
            if (pos == b) break
            adjList[pos].forEach {
                if (!visit[it]) {
                    visit[it] = true
                    q.add(it)
                }
            }
        }
        visit[b]
    }

    for (i in 1..Q) {
        val (a, b) = br.readLine().split(' ')
        if (!nameMap.containsKey(a) || !nameMap.containsKey(b)) {
            bw.write("gg ")
        } else {
            val aIdx = nameMap.getValue(a)
            val bIdx = nameMap.getValue(b)
            val aIsOlderB = isOlder(aIdx, bIdx)
            val bIsOlderA = isOlder(bIdx, aIdx)

            if (aIsOlderB == bIsOlderA) bw.write("gg ")
            else bw.write(if (aIsOlderB) "$a " else "$b ")
        }
    }
    bw.flush()
}