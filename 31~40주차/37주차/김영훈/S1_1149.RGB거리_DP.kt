import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.min

const val INF = 1 shl 30
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    val dp = Array(N) { Triple(INF, INF, INF) }
    val first = br.readLine().split(' ').map { it.toInt() }
    dp[0] = Triple(first[0], first[1], first[2])
    (1 until N).forEach {
        val (r, g, b) = br.readLine().split(' ').map { it.toInt() }
        val dpr = dp[it - 1].second.coerceAtMost(dp[it - 1].third) + r
        val dpg = dp[it - 1].first.coerceAtMost(dp[it - 1].third) + g
        val dpb = dp[it - 1].first.coerceAtMost(dp[it - 1].second) + b
        dp[it] = Triple(dpr, dpg, dpb)
    }
    bw.write(dp[N - 1].first.coerceAtMost(dp[N - 1].second).coerceAtMost(dp[N - 1].third).toString())
    bw.flush()

}