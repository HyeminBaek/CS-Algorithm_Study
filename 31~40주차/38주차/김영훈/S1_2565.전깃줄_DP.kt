import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Integer.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    val pairArray = ArrayList<IntArray>()
    (0 until N).forEach { _ -> pairArray.add(br.readLine().split(' ').map { it.toInt() }.toIntArray()) }
    pairArray.sortWith { a: IntArray, b: IntArray ->
        when {
            a[0] > b[0] -> 1
            a[0] < b[0] -> -1
            else -> 0
        }
    }
    val dp=Array(501){0}

    pairArray.forEach{b->
        dp[b[1]]=max(1,dp[b[1]])
        (1 until b[1]).forEach{
            dp[b[1]]=max(dp[it]+1,dp[b[1]])
        }
        (b[1]+1..500).forEach{
            dp[it]=max(dp[it],dp[b[1]])
        }
    }

    bw.write((N-dp[500]).toString())
    bw.flush()

}