import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    data class Fruit(var a:Int, var b:Int)
    val (R, C) = br.readLine().split(' ').map { it.toInt() }
    val dir=arrayOf(Pair(1,0),Pair(1,1),Pair(0,1))
    val treeArr = Array(R) {
        br.readLine().split(' ').map {
            if (it[0] == 'A') Fruit(it.substring(1).toInt(), 0)
            else Fruit(0, it.substring(1).toInt())
        }.toTypedArray()
    }

    for(r in 0 until R) for(c in 0 until C){
        if(r>0) treeArr[r][c].a+=treeArr[r-1][c].a
        if(c>0) treeArr[r][c].b+=treeArr[r][c-1].b
    }
    val isValidPos={r:Int,c:Int -> r in 0 until R && c in 0 until C}
    val dp=Array(R){Array(C){0} }
    val visit=Array(R){Array(C){false}}
    visit[0][0]=true
    val queue: Queue<Pair<Int, Int>> = LinkedList()
    queue.add(Pair(0,0))
    while(queue.isNotEmpty()){
        val now=queue.poll()
        for(d in dir){
            val nr=now.first+d.first
            val nc=now.second+d.second
            if(!isValidPos(nr,nc)) continue
            if(!visit[nr][nc] && d.first*d.second==0){
                visit[nr][nc]=true
                queue.add(Pair(nr,nc))
            }
            var sum=dp[now.first][now.second]
            sum+=d.second*(treeArr[R-1][now.second].a-treeArr[now.first][now.second].a)
            sum+=d.first*(treeArr[now.first][C-1].b-treeArr[now.first][now.second].b)
            dp[nr][nc]=dp[nr][nc].coerceAtLeast(sum)
        }
    }
    bw.write(dp[R-1][C-1].toString())
    bw.close()
}