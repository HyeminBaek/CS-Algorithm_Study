import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList



fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val adjList = Array(3001) { ArrayList<Int>() }
    val isCircleLine = Array(3001) { false}
    val visit=Array(3001){false}
    val isInStack=Array(3001){false}
    val ans=Array(3001){0}
    val st=ArrayList<Int>()

    val N = br.readLine().toInt()


    (1..N).forEach {
        val (a, b) = br.readLine().split(' ').map { it.toInt() - 1 }
        adjList[a].add(b)
        adjList[b].add(a)
    }

    fun initCircle(n:Int,pre:Int){
        if(isInStack[n]){
            var idx=st.size-1
            isCircleLine[n]=true
            while(st[idx]!=n){
                isCircleLine[st[idx]]=true
                idx--
            }
            return
        }
        if(visit[n]) return

        visit[n]=true
        st.add(n)
        isInStack[n]=true

        adjList[n].forEach{
            if(it!=pre){
                initCircle(it,n)
            }
        }
        st.removeLast()
        isInStack[n]=false
    }

    initCircle(0,-1)


    fun DFS(n :Int, dist:Int){
        visit[n]=true
        ans[n]=dist
        adjList[n].forEach{
            if(!visit[it]){
                DFS(it,if(!isCircleLine[it])dist+1 else dist)
            }
        }

    }
    for(i in 0..N-1){
        visit[i]=false
    }
    for(i in 0..N-1){
        if(isCircleLine[i]){
            DFS(i,0)
            break
        }
    }

    for(i in 0..N-1){
        bw.write(ans[i].toString()+" ")
    }
   bw.flush()




}

