import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (L, K, C) = br.readLine().split(' ').map { it.toInt() }
    val lengthArray = ArrayList<Int>().apply {
        val pos =
            br.readLine().split(' ').map { it.toInt() }.toMutableList().apply { add(L) }.toTypedArray().apply { sort() }
        for (idx in pos.indices) {
            if (idx == 0) add(pos[idx])
            else add(pos[idx] - pos[idx - 1])
        }
    }.filter { it != 0 }.reversed()
    var s = lengthArray.maxOrNull()!!
    var e = L
    var ans = Pair(L, -1)
    while (s <= e) {
        val m = (s + e) / 2
        var num = 0
        var first = L
        var acc = 0
        var nowPos = L
        lengthArray.forEach{
            if (acc + it > m) {
                num++
                first = nowPos
                acc = 0
            }
            acc += it
            nowPos-=it
        }
        if (num <= C) {
            if(num<C){
                first=lengthArray.last()
            }
            ans = Pair(m, first)
            e = m - 1
        } else {
            s = m + 1
        }
    }
    bw.write("${ans.first} ${ans.second}\n")
    bw.flush()
}