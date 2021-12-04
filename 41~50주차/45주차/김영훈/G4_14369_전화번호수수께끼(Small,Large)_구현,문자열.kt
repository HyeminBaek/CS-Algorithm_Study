import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val alpArr = arrayOf("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")
    val alpSeq = listOf(
        Pair(8, 'G'),
        Pair(4, 'U'),
        Pair(2, 'W'),
        Pair(6, 'X'),
        Pair(0, 'Z'),
        Pair(1, 'O'),
        Pair(5, 'F'),
        Pair(3, 'H'),
        Pair(7, 'V'),
        Pair(9, 'I')
    )
    val alpMap = HashMap<Char, Int>()
    val ans = Array(10) { 0 }
    for (tc in 1..br.readLine().toInt()) {
        alpMap.clear()
        br.readLine().forEach {
            alpMap[it] = (alpMap[it] ?: 0) + 1
        }
        alpSeq.forEach { pair ->
            val n = alpMap[pair.second] ?: 0
            ans[pair.first] = n
            alpArr[pair.first].forEach { c ->
                alpMap[c] = (alpMap[c] ?: 0) - n
            }
        }
        bw.write("Case #$tc: " + StringBuilder("").apply {
            ans.forEachIndexed { idx, i -> append(idx.toString().repeat(i)) }
        }.toString() + "\n")
    }
    bw.flush()
}