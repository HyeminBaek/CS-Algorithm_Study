import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.min
import java.util.*

private const val INF = (1 shl 30)
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, M, T) = br.readLine().split(' ').map { it.toInt() }
    val map = Array(N) { br.readLine().split(' ').map { it.toInt() }.toTypedArray() }
    val timeArray = Array(N) { Array(M) { INF } }

    val queue: Queue<Pair<Int, Int>> = LinkedList()
    var ans = INF
    val isValidPos = { r: Int, c: Int -> (r in 0 until N && c in 0 until M) }
    val dir = arrayOf(Pair(1, 0), Pair(-1, 0), Pair(0, 1), Pair(0, -1))
    timeArray[0][0] = 0
    queue.add(Pair(0, 0))
    while (queue.isNotEmpty()) {
        val nowPos = queue.poll()

        if (nowPos.first == N - 1 && nowPos.second == M - 1) {
            ans = ans.coerceAtMost(timeArray[nowPos.first][nowPos.second])
            continue
        }
        if (map[nowPos.first][nowPos.second] == 2) {
            ans= ans.coerceAtMost(timeArray[nowPos.first][nowPos.second]+(N-1-nowPos.first)+(M-1-nowPos.second))
            continue
        }

        for (d in 0..3) {
            val nr = nowPos.first + dir[d].first
            val nc = nowPos.second + dir[d].second
            if (!isValidPos(nr, nc)) continue
            if (timeArray[nr][nc] <= timeArray[nowPos.first][nowPos.second] + 1) continue
            if (map[nr][nc] == 1) continue
            timeArray[nr][nc] = timeArray[nowPos.first][nowPos.second] + 1
            queue.add(Pair(nr, nc))
        }
    }

    bw.write(if(ans>T) "Fail" else ans.toString())
    bw.flush()

}