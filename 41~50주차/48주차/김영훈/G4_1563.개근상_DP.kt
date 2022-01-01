fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val N = br.readLine().toInt()
    val mod = 1000000
    val dp = Array(2) { Array(2) { Array(3) { 0 } } }
    dp[0][0][0]=1
    for (day in 1..N) {
        val now = day % 2
        val pre = 1 - now
        dp[now][0][0] = (dp[pre][0].sumOf { it }) % mod
        dp[now][0][1] = dp[pre][0][0]
        dp[now][0][2] = dp[pre][0][1]
        dp[now][1][0] = (dp[pre][0].sumOf { it } + dp[pre][1].sumOf { it }) % mod
        dp[now][1][1] =dp[pre][1][0]
        dp[now][1][2] =dp[pre][1][1]
    }
    bw.write((dp[N%2].sumOf{ i -> i.sumOf{j->j}}%mod).toString()+"\n")
    bw.close()
}