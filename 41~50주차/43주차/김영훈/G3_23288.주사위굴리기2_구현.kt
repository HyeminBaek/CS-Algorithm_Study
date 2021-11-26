import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val dirArr = arrayOf(Pair(-1, 0), Pair(0, 1), Pair(1, 0), Pair(0, -1)) // 북 동 남 서
    /*
        동 남 서 북 상 하
            3
          2 4 0
            1
            5
     */
    val dice = arrayOf(3, 5, 4, 2, 1, 6)
    var pos = Pair(0, 0)
    var dir = 1
    var score = 0

    val (N, M, K) = br.readLine().split(' ').map { it.toInt() }
    val map = Array(N) { br.readLine().split(' ').map { it.toInt() }.toTypedArray() }

    val scoreMap = Array(N) { Array(M) { 0 } }
    val visit = Array(N) { Array(M) { false } }
    val adj = ArrayList<Pair<Int, Int>>()
    val q = LinkedList<Pair<Int, Int>>()
    val isValidPos = { r: Int, c: Int -> r in 0 until N && c in 0 until M }

    //score 그룹 형성 O(N*M)
    for (r in 0 until N) for (c in 0 until M) {
        if (visit[r][c]) continue
        adj.clear()
        q.clear()
        val mapScore = map[r][c]
        visit[r][c] = true
        q.add(Pair(r, c))

        while (q.isNotEmpty()) {
            val now = q.poll()
            adj.add(now)
            dirArr.forEach {
                val nr = it.first + now.first
                val nc = it.second + now.second
                if (isValidPos(nr, nc) && !visit[nr][nc] && map[nr][nc] == mapScore) {
                    visit[nr][nc] = true
                    q.add(Pair(nr, nc))
                }
            }
        }

        adj.forEach {
            scoreMap[it.first][it.second] = adj.size * mapScore
        }
    }

    //repeat O(K)
    repeat(K) {

        //rotate O(1)
        val nDice = arrayOf(0, 0, 0, 0, 0, 0)
        if (!isValidPos(pos.first + dirArr[dir].first, pos.second + dirArr[dir].second)) dir = (2 + dir) % 4
        pos = Pair(pos.first + dirArr[dir].first, pos.second + dirArr[dir].second)
        when (dir) {
            1 -> {
                nDice[1] = dice[1]
                nDice[3] = dice[3]
                nDice[0] = dice[4]
                nDice[4] = dice[2]
                nDice[2] = dice[5]
                nDice[5] = dice[0]
            }
            2 -> {
                nDice[0] = dice[0]
                nDice[2] = dice[2]
                nDice[1] = dice[4]
                nDice[5] = dice[1]
                nDice[4] = dice[3]
                nDice[3] = dice[5]
            }
            3 -> {
                nDice[1] = dice[1]
                nDice[3] = dice[3]
                nDice[4] = dice[0]
                nDice[2] = dice[4]
                nDice[5] = dice[2]
                nDice[0] = dice[5]
            }
            else -> {
                nDice[0] = dice[0]
                nDice[2] = dice[2]
                nDice[4] = dice[1]
                nDice[1] = dice[5]
                nDice[3] = dice[4]
                nDice[5] = dice[3]
            }
        }
        for(i in 0 until 6) dice[i]=nDice[i]

        //move O(1)
        score += scoreMap[pos.first][pos.second]

        val mapScore = map[pos.first][pos.second]
        when {
            dice[5] > mapScore -> {
                dir = (dir + 1) % 4
            }
            dice[5] < mapScore -> {
                dir = (3 + dir) % 4
            }
        }

    }
    bw.write(score.toString())
    bw.flush()
}

//O(K*1*1)+O(N*M) = O(K+N*M)