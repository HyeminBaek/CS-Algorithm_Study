import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val st = Stack<String>()
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var str = br.readLine()
    while (str != "#") {
        val ret = isHTML(str)
        bw.write((if (ret) "legal" else "illegal") + "\n")
        str = br.readLine()
    }
    bw.flush()
}

fun isHTML(str: String?): Boolean {
    str ?: return false
    st.clear()
    val tagList = str.split("<").map { if (it.indexOf(">") != -1) it.substringBefore(">") else "" }.toList()

    tagList.forEach {
        if (it.isNotEmpty()) {
            val splitStr = it.split(' ')
            if (splitStr.size == 1 || splitStr[1] != "/") {
                if (splitStr[0][0] == '/') {
                    if (st.isEmpty() || st.pop() != splitStr[0].substringAfter('/')) return false
                } else {
                    st.add(splitStr[0])
                }

            }
        }
    }
    return st.isEmpty()
}