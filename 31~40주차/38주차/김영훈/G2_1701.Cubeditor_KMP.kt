import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Integer.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val input = br.readLine()
    var ans = 0
    var str = "."
    val f=Array(5001){0}
    val checkBit=Array(5001){false}
    (input.length - 1 downTo 0).forEach { sidx ->
        (0 until input.length).forEach{checkBit[it]=false}
        str = input[sidx] + str
        initFailed(str,f)
        var j = 0
        input.forEach {
            while (j != 0 && str[j] != it) {
                j = f[j - 1]
            }
            if (str[j] == it) {
                j++
                if (checkBit[j]) ans = max(ans, j)
                checkBit[j]=true
            }
        }

    }
    bw.write(ans.toString())
    bw.flush()
}

fun initFailed(str: String,f:Array<Int>) {
    var j = 0
    f[0]=0
    (1 until str.length).forEach { idx ->
        f[idx]=0
        while (j != 0 && str[idx] != str[j]) {
            j = f[j - 1]
        }
        if (str[idx] == str[j]) {
            f[idx] = ++j
        }
    }

}