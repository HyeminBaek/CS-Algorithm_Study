import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val dp = Array(10) { Array(2001) { 0L } }

    val reset = { repeat(10) { i -> dp[i].fill(0, 0, 2001) } }

    repeat(br.readLine().toInt()) {

        val (n, m) = br.readLine().split(' ').map { it.toInt() }
        for (i in 1..m) {
            dp[0][i] = 1
        }

        for (i in 0 until n - 1) {
            for (j in 1..m) {
                if (j * 2 > m) break
                dp[i + 1][j * 2] += dp[i][j]
            }
            for (j in 2..m) {
                dp[i + 1][j] += dp[i + 1][j - 1]
            }
        }

        bw.write("${dp[n - 1].sumOf { it }}\n")
        bw.flush()
        reset()
    }

}