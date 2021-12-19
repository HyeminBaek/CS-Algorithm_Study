import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val dir = arrayOf(
        Pair(1, -1),
        Pair(1, 0),
        Pair(1, 1),
        Pair(0, -1),
        Pair(0, 0),
        Pair(0, 1),
        Pair(-1, -1),
        Pair(-1, 0),
        Pair(-1, 1)
    )

    var playerPos = Pair(-1, -1)
    var enemySet = HashSet<Pair<Int, Int>>()

    val (R, C) = br.readLine().split(' ').map { it.toInt() }
    repeat(R) { r ->
        br.readLine().forEachIndexed { c, ch ->
            if (ch == 'R') enemySet.add(Pair(r, c))
            if (ch == 'I') playerPos = Pair(r, c)
        }
    }
    val getAbs = { a: Int -> if (a > 0) a else -a }
    val getDist = { r1: Int, c1: Int, r2: Int, c2: Int ->
        getAbs(r2 - r1) + getAbs(c2 - c1)
    }

    val movePlayer = { d: Int -> playerPos = playerPos.run { Pair(first + dir[d].first, second + dir[d].second) } }
    val isValidPos = { r: Int, c: Int -> r in 0 until R && c in 0 until C }
    val moveEnemy = {
        val retMap = HashMap<Pair<Int, Int>, Int>()
        enemySet.forEach {
            var dist = Int.MAX_VALUE
            var target = Pair(-1, -1)
            for (d in dir) {
                val nr = it.first + d.first
                val nc = it.second + d.second
                if (!isValidPos(nr, nc)) continue
                val nDist = getDist(playerPos.first, playerPos.second, nr, nc)
                if (nDist >= dist) continue
                dist = nDist
                target = Pair(nr, nc)
            }
            retMap[target] = (retMap[target] ?: 0) + 1
        }

        enemySet.clear()
        val ret = !retMap.containsKey(playerPos)
        retMap.forEach {
            if (it.value == 1) {
                enemySet.add(it.key)
            }
        }
        ret
    }

    val move = br.readLine()
    var flag = true
    for (turn in move.indices) {
        movePlayer(move[turn].code - '0'.code - 1)
        if (!moveEnemy()) {
            flag = false
            bw.write("kraj ${turn + 1}")
            break
        }

//        val temp=Array(R){Array(C){'.'}}
//        temp[playerPos.first][playerPos.second]='I'
//        enemySet.forEach{
//            temp[it.first][it.second]='R'
//        }
//        println(turn+1)
//        repeat(R) {r->
//            repeat(C) {c->
//                print(temp[r][c])
//            }
//            println()
//        }
//

    }
    if (flag) {
        val ans = Array(R) { Array(C) { '.' } }
        ans[playerPos.first][playerPos.second] = 'I'
        enemySet.forEach {
            ans[it.first][it.second] = 'R'
        }
        repeat(R) { r ->
            repeat(C) { c ->
                bw.write("${ans[r][c]}")
            }
            bw.write("\n")
        }
    }
    bw.flush()
}