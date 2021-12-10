import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val bitArr = Array(br.readLine().toInt()) {
        var bit = 0
        br.readLine().forEach {
            bit = bit or (1 shl (it.code - 'a'.code))
        }
        bit
    }
    var ans = 0

    fun search(idx: Int, bit: Int) {
        if (idx==bitArr.size && bit == (1 shl 26) - 1) ans++
        if (idx == bitArr.size) return
        search(idx + 1, bit)
        search(idx + 1, bit or bitArr[idx])
    }
    search(0,0)
    bw.write("$ans\n")
    bw.flush()
}