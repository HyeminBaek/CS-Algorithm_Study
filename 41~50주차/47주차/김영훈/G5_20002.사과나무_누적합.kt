import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val N = br.readLine().toInt()
    val arr = Array(N) { br.readLine().split(' ').map { it.toInt() }.toTypedArray() }
    for (r in 0 until N) for (c in 0 until N) {
        if (r > 0) arr[r][c] += arr[r - 1][c]
        if (c > 0) arr[r][c] += arr[r][c - 1]
        if (r > 0 && c > 0) arr[r][c] -= arr[r - 1][c - 1]
    }

    val getSubTotal = { sr: Int, sc: Int, er: Int, ec: Int ->
        var ret = arr[er][ec]
        if (sr > 0) ret -= arr[sr - 1][ec]
        if (sc > 0) ret -= arr[er][sc - 1]
        if (sr > 0 && sc > 0) ret += arr[sr - 1][sc - 1]
        ret
    }
    var ans=arr[0][0]
    for (r in 0 until N) for (c in 0 until N) {
        var er=r
        var ec=c
        while(er<N && ec<N){
            ans=ans.coerceAtLeast(getSubTotal(r,c,er,ec))
            er++
            ec++
        }
    }
    bw.write("$ans\n")
    bw.flush()
}