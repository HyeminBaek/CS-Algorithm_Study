import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, m) = br.readLine().split(' ').map { it.toInt() }
    val childList = Array(n) { ArrayList<Int>() }
    val num = Array(n) { 0 }
    val str = br.readLine().split(' ').map { it.toInt() }
    str.forEachIndexed { idx, it -> if (it > -1) childList[it - 1].add(idx) }
    for (i in 0 until m) {
        val input = br.readLine().split(' ').map { it.toInt() }
        num[input[0] - 1] += input[1]
    }

    fun DFS(n: Int) {
        childList[n].forEach {
            num[it] += num[n]
            DFS(it)
        }
    }
    DFS(0)
    num.forEach { bw.write("$it ") }
    bw.flush()
}