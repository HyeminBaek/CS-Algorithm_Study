import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val inf = 1 shl 30
    val (n, k) = br.readLine().split(' ').map { it.toInt() }
    val coin = ArrayList<Int>()

    (0 until n).forEach { _ ->
        coin.add(br.readLine().toInt())
    }
    val dp = Array(10001) { inf }
    dp[0] = 0
    (0 until k).forEach { i ->
        coin.forEach { c ->
            if (i + c <= k) dp[i + c] = dp[i + c].coerceAtMost(dp[i] + 1)
        }
    }

    bw.write((if (dp[k] == inf) -1 else dp[k]).toString())
    bw.flush()
}