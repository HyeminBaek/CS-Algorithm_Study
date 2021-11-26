import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toLong()
    val K = br.readLine().toLong()

    var s = 1L
    var e = N * N
    var ans = 0L

    val getLessNum = { num: Long ->
        (1..N).sumOf { N.coerceAtMost(num / it) }
    }

    while (s <= e) {
        val m = (s + e) / 2
        val lessNum = getLessNum(m)

        if (lessNum < K) {
            s = m + 1
        } else {
            ans = m
            e = m - 1
        }
    }
    bw.write(ans.toString())
    bw.flush()
}