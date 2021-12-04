import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val N = br.readLine().toInt()
    val maxLength=Array(N+1){0}
    br.readLine().split(' ').map { it.toInt() }.forEach {
       maxLength[it]=maxLength[it-1]+1
    }
    bw.write((N-maxLength.maxOf{it}).toString()+"\n")
    bw.flush()
}