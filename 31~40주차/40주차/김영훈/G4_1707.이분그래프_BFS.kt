import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val K = br.readLine().toInt()
    val q: Queue<Int> = LinkedList()
    for (tc in 1..K) {
        val (V, E) = br.readLine().split(' ').map { it.toInt() }
        val check = Array(20001) { 0 }
        val adjList = Array(20001) { ArrayList<Int>() }
        for (e in 1..E) {
            val (u, v) = br.readLine().split(' ').map { it.toInt() }
            adjList[u].add(v)
            adjList[v].add(u)
        }

        var flag = true
        for (v in 1..V) {
            if (check[v] != 0) continue
            check[v] = 1
            q.add(v)
            while (q.isNotEmpty()) {
                val t = q.poll()
                adjList[t].forEach {
                    if (check[it] == 0) {
                        check[it] = -check[t]
                        q.add(it)
                    } else if (check[it] == check[t]) flag = false
                }
            }
        }
        bw.write((if (flag) "YES" else "NO") + "\n")

    }
    bw.flush()


}