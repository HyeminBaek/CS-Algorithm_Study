import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val board = Array(N + 1) { IntArray(M + 1) }
    val visit = Array(N + 1) { IntArray(M + 1) { -1 } }
    val dir = arrayOf(Pair(1, 0), Pair(-1, 0), Pair(0, 1), Pair(0, -1))
    for (i in 1..N) {
        board[i][0] = 0
        val str = br.readLine().split(' ')
        for (j in 1..M) {
            board[i][j] = str[j - 1].toInt()
        }
    }
    val input = br.readLine().split(' ').map { it.toInt() }
    val H = input[0]
    val W = input[1]
    val sr = input[2]
    val sc = input[3]
    val fr = input[4]
    val fc = input[5]

    for (r in 1..N) {
        for (c in 1..M) {
            board[r][c] = board[r][c] + board[r - 1][c] + board[r][c - 1] - board[r - 1][c - 1]
        }
    }

    val possible = { r: Int, c: Int ->
        if (r + H - 1 > N || c + W - 1 > M || r < 1 || c < 1) false
        else {
            (board[r + H - 1][c + W - 1] - board[r - 1][c + W - 1] - board[r + H - 1][c - 1]
                    + board[r - 1][c - 1] == 0)
        }
    }
    possible(3, 2)
    val q: Queue<Pair<Int, Int>> = LinkedList()
    var ans = -1
    visit[sr][sc] = 0
    q.add(Pair(sr, sc))
    while (q.isNotEmpty()) {
        val t = q.poll()
        if (t.first == fr && t.second == fc) {
            ans = visit[t.first][t.second]
            break
        }
        for (d in 0..3) {
            val nr = t.first + dir[d].first
            val nc = t.second + dir[d].second
            if (!possible(nr, nc) || visit[nr][nc] != -1) continue
            visit[nr][nc] = visit[t.first][t.second] + 1
            q.add(Pair(nr, nc))
        }
    }
    bw.write(ans.toString())
    bw.flush()

}