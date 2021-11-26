import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val writeSet = HashSet<String>()
    val readSet = HashSet<String>()
    val addWait = {
        bw.write("WAIT\n")
        readSet.clear()
        writeSet.clear()
    }
    var oper = br.readLine()
    while (oper != "EXIT") {
        val operSplit = oper.split(' ')
        if (writeSet.contains(operSplit[1])) {
            addWait()
        }
        if (operSplit[0][0] == 'W') {
            if (writeSet.contains(operSplit[3])) {
                addWait()
            }
            if (readSet.contains(operSplit[3])) {
                addWait()
            }
            writeSet.add(operSplit[3])
        }
        readSet.add(operSplit[1])
        bw.write(oper + "\n")
        oper = br.readLine()
    }
    bw.write(oper + "\n")
    bw.flush()
}