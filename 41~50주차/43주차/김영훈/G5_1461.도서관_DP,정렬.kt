import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.max

private const val INF = 1 shl 30
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val sortArr = { arr: Array<Int> ->
        arr.sortedWith { a: Int, b: Int ->
            when {
                a > b -> 1
                a < b -> -1
                else -> 0
            }
        }.toTypedArray()
    }

    val pos = br.readLine().split(' ').map { it.toInt() }
    val negativePos = sortArr(pos.filter { it < 0 }.map { -it }.toTypedArray())
    val positivePos = sortArr(pos.filter { it > 0 }.toTypedArray())

    val positiveDp = Array(positivePos.size + 1) { INF }
    val negativeDp = Array(negativePos.size + 1) { INF }

    positiveDp[0] = 0

    for (idx in positiveDp.indices) {
        for (j in 1..M) {
            if (idx + j >= positiveDp.size) break
            positiveDp[idx + j] = positiveDp[idx + j].coerceAtMost(positiveDp[idx] + positivePos[idx + j - 1] * 2)
        }
    }


    negativeDp[0] = 0
    for (idx in negativeDp.indices) {
        for (j in 1..M) {
            if (idx + j >= negativeDp.size) break
            negativeDp[idx + j] = negativeDp[idx + j].coerceAtMost(negativeDp[idx] + negativePos[idx + j - 1] * 2)
        }
    }

    bw.write(
        ((positiveDp.lastOrNull() ?: 0) + (negativeDp.lastOrNull() ?: 0) - (positivePos.lastOrNull() ?: 0).coerceAtLeast(negativePos.lastOrNull() ?: 0)).toString()
    )
    bw.flush()
}