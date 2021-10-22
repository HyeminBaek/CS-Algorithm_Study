import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val N=50
    val M=49
    bw.write("$N $M\n")
    for(i in 1..M){
        bw.write("${i+1} $i -1"+if(i!=M)"\n" else "")
    }
    bw.flush()
}