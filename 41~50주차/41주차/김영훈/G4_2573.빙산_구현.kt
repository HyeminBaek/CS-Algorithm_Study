import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

private val dir = arrayOf(Pair(1, 0), Pair(-1, 0), Pair(0, 1), Pair(0, -1))
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val map = Array(301) { Array(301) { 0 } }
    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    for (r in 0 until N) map[r]=br.readLine().split(' ').map{it.toInt()}.toTypedArray()
    var y=0
    while(true){
        val p=getPiece(map,N,M)
        if(p!=1){
            bw.write((y*if(p==0)0 else 1).toString())
            break
        }
        melt(map,N,M)
        y++
    }
    bw.flush()
}

fun melt(map: Array<Array<Int>>, N: Int, M: Int) {
    val temp = Array(N) {r-> Array(M) {c-> map[r][c] } }
    for (r in 0 until N) for (c in 0 until M) for (d in 0..3) {
        val nr = r + dir[d].first
        val nc = c + dir[d].second
        if (isValidPos(nr, nc, N, M) && map[nr][nc] <=0) temp[r][c]--
    }

    for (r in 0 until N) for (c in 0 until M) map[r][c] = temp[r][c]
}

fun getPiece(map: Array<Array<Int>>, N: Int, M: Int): Int {
    val check = Array(N) { Array(M) { false } }
    var ret = 0
    val q: Queue<Pair<Int, Int>> = LinkedList()
    for (r in 0 until N) for (c in 0 until M) {
        if (map[r][c]<=0 || check[r][c]) continue
        ret++
        check[r][c] = true
        q.add(Pair(r, c))
        while (q.isNotEmpty()) {
            val t = q.poll()
            for (d in 0..3) {
                val nr = t.first + dir[d].first
                val nc = t.second + dir[d].second
                if (isValidPos(nr, nc, N, M) && map[nr][nc] > 0 && !check[nr][nc]) {
                    check[nr][nc] = true
                    q.add(Pair(nr, nc))
                }
            }
        }
    }
    return ret
}

fun isValidPos(r: Int, c: Int, N: Int, M: Int) = (r in 0 until N && c in 0 until M)