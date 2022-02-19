fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val N=br.readLine().toInt()
    val s=br.readLine()
    val e=br.readLine()
    val charToInt = {c:Char -> c.code-'0'.code}
    val dp=Array(2){Array(10){1 shl 30} }
    dp[0][0]=0
    for(i in 0 until N){
        val now=i%2
        val next=1-now
        for(j in 0 until 10) dp[next][j]= 1 shl 30
        for(j in 0 until 10){
            val sNum=(charToInt(s[i])+j)%10
            val eNum=charToInt(e[i])
            val leftNum=(10+eNum-sNum)%10
            val rightNum = (10+sNum-eNum)%10
            dp[next][(j+leftNum)%10] = dp[next][(j+leftNum)%10].coerceAtMost(dp[now][j]+leftNum)
            dp[next][j]=dp[next][j].coerceAtMost(dp[now][j]+rightNum)
        }
    }
    println(dp[N%2].minOf{it})
}