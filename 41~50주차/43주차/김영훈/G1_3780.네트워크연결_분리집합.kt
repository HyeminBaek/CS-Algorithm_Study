import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.abs

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val par = Array(20001) { 0 }
    val dist = Array(20001) { 0 }
    val reset = { N: Int ->
        (1..N).forEach {
            par[it] = it
            dist[it] = 0
        }
    }

    fun find(now: Int): Int {
        val p = par[now]
        if (p != now) {
            par[now] = find(par[now])
            dist[now] += dist[p]
        }
        return par[now]
    }

    val union = { a: Int, b: Int ->
        par[a]=b
        dist[a] = abs(b - a) % 1000
    }

    repeat(br.readLine().toInt()) {

        val N = br.readLine().toInt()
        var input = br.readLine().split(' ')
        reset(N)
        while (input.size > 1) {
            if (input.size == 2) {
                val target = input[1].toInt()
                find(target)
                bw.write("${dist[target]}\n")
            } else {
                union(input[1].toInt(), input[2].toInt())
            }

            input = br.readLine().split(' ')
        }
        bw.flush()
    }
}