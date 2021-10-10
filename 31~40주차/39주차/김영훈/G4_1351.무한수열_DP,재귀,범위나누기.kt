import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Long.min

val saveData = Array(1000001) { 0L }
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (N, P, Q) = br.readLine().split(' ').map { it.toLong() }
    saveData[0] = 1
    (1..min(N, 1000000)).forEach {
        saveData[it.toInt()] = saveData[it.toInt() / P.toInt()] + saveData[it.toInt() / Q.toInt()]
    }
    bw.write(search(N, P, Q).toString())
    bw.flush()
}

fun search(N: Long, P: Long, Q: Long): Long {
    return if (N <= 1000000) saveData[N.toInt()]
    else search(N / P, P, Q) + search(N / Q, P, Q)
}