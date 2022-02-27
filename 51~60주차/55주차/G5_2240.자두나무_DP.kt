fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val (T, W) = br.readLine().split(' ').map { it.toInt() }
    val dp = Array(2) { Array(2) { Array(W + 1) { -1 } } }
    dp[0][0][0] = 0
    repeat(T) {
        val now = it % 2
        val next = 1 - now
        val n = br.readLine().toInt()

        for (i in 0..W) {
            if (dp[now][0][i] != -1) {
                val nw = i + (n + 1) % 2
                if (nw <= W) dp[next][n - 1][nw] = dp[next][n - 1][nw].coerceAtLeast(dp[now][0][i] + 1)
                dp[next][0][i] = dp[next][0][i].coerceAtLeast(dp[now][0][i])
            }
            if (dp[now][1][i] != -1) {
                val nw = i + n % 2
                if (nw <= W) dp[next][n - 1][nw] = dp[next][n - 1][nw].coerceAtLeast(dp[now][1][i] + 1)
                dp[next][1][i] = dp[next][1][i].coerceAtLeast(dp[now][1][i])
            }
        }
    }
    println(dp[T % 2].maxOf { a -> a.maxOf { it } })
}