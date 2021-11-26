import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    val arr = br.readLine().split(' ').map { it.toInt() }

    val sortedArr = arr.sortedWith { a: Int, b: Int ->
        when {
            a > b -> 1
            a < b -> -1
            else -> 0
        }
    }.toTypedArray()

    val idxMap=sortedArr.mapIndexed{idx,value->Pair(value,idx)}.toMap()
    val check = Array(N){false}
    var minIdx=0
    var ans=0
    for(i in 0 until N){
        val nowIdx=idxMap[arr[i]]!!
        check[nowIdx]=true
        if(minIdx==nowIdx) {
            ans= (i-minIdx).coerceAtLeast(ans)
            while(minIdx<N && check[minIdx]) minIdx++
        }
    }
    bw.write(ans.toString())
    bw.flush()
}