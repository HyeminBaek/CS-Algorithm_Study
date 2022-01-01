import java.util.*
import kotlin.collections.ArrayList

fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    data class Node(val n:Int, var par:Int=-1, var d:Int=-1, val adjList:ArrayList<Int> = ArrayList(), var k:Int=0)

    val N=br.readLine().toInt()
    val nodes=Array(N){Node(it)}

    repeat(N-1){
        br.readLine().split(' ').map{it.toInt()-1}.run{
            nodes[get(0)].adjList.add(get(1))
            nodes[get(1)].adjList.add(get(0))
        }
    }


    fun dfs(node:Node){
        node.adjList.forEach{
            if(nodes[it].d!=-1) return@forEach
            nodes[it].d=node.d+1
            nodes[it].par=node.n
            dfs(nodes[it])
        }
    }

    fun delivery(s:Int, e:Int){
        val st = Stack<Int>()
        var k=0
        var ns=s
        var ne=e
        while(ns!=ne){
            if(nodes[ns].d<nodes[ne].d){
                st.add(ne)
                ne=nodes[ne].par
            }else{
                nodes[ns].k+=k++
                ns=nodes[ns].par
            }
        }
        st.add(ns)
        while(st.isNotEmpty()) nodes[st.pop()].k+=k++
    }

    dfs(nodes[0].apply{d=0})

    val Q=br.readLine().toInt()
    repeat(Q){
        br.readLine().split(' ').map{it.toInt()}.run{
            if(get(0)==1) delivery(get(1)-1,get(2)-1)
            else bw.write("${nodes[get(1)-1].k}\n")
        }
    }
    bw.close()
}
