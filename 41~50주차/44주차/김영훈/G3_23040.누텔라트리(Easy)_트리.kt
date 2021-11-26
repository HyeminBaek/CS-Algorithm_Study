import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList

fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    val adjList=Array(N){ArrayList<Int>()}
    repeat(N-1){
        br.readLine().split(' ').map{it.toInt()-1}.let{
            adjList.run{
                get(it[0]).add(it[1])
                get(it[1]).add(it[0])
            }
        }
    }
    val color=br.readLine()
    val visit=Array(N){false}
    var ans=0L

    val queue= LinkedList<Int>()
    for(i in 0 until N) {
        if(visit[i] || color[i]=='B') continue
        queue.add(i)
        visit[i]=true
        var redCnt=1L
        var blackCnt=0L
        while(queue.isNotEmpty()) {
            val now=queue.poll()
            for(next in adjList[now]){
                if(visit[next]) continue
                if(color[next]=='B') blackCnt++
                else{
                    redCnt++
                    visit[next]=true
                    queue.add(next)
                }
            }
        }
        ans+=redCnt*blackCnt
    }
    bw.write("$ans\n")
    bw.flush()
}