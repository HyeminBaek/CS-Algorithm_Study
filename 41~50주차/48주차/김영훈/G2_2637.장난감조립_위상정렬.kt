import java.util.*
import kotlin.collections.ArrayList

fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    data class Edge(val d:Int, val n:Int)
    data class Node(val n:Int, var inDeg:Int = 0,var k:Int=0,val adjList:ArrayList<Edge> = ArrayList())
    val N=br.readLine().toInt()
    val M=br.readLine().toInt()
    val nodes=Array(N){Node(it)}

    repeat(M){
        br.readLine().split(' ').map{it.toInt()}.run{
            nodes[get(0)-1].adjList.add(Edge(get(1)-1,get(2)))
            nodes[get(1)-1].inDeg++
        }
    }

    val ans=Array(N){-1}
    val queue: Queue<Int> = LinkedList()
    nodes[N-1].k=1
    queue.add(N-1)
    while(queue.isNotEmpty()){
        val now=queue.poll()
        if(nodes[now].adjList.size==0){
            ans[now]=nodes[now].k
        }
        for(edge in nodes[now].adjList){
            nodes[edge.d].inDeg--
            nodes[edge.d].k+=nodes[now].k*edge.n
            if(nodes[edge.d].inDeg==0) queue.add(edge.d)
        }
    }
    for(i in 0 until N){
        if(ans[i]!=-1) bw.write("${i+1} ${ans[i]}\n")
    }
    bw.close()
}