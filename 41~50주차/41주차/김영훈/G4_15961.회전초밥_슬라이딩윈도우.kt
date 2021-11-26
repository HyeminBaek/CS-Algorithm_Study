import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.OutputStreamWriter
import java.io.InputStreamReader
import java.lang.Integer.max

fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))

    val (N,d,k,c)=br.readLine().split(' ').map{it.toInt()}
    val belt=Array(3000000){0}
    val num = Array(3001){0}
    var t=0
    var ans=0
    for(i in 0 until N) belt[i]= br.readLine().toInt()

    for(i in 0 until k){
        num[belt[i]]++
        if(num[belt[i]]==1) t++
    }
    for(i in 0 until N){
        ans=max(ans,t+(if(num[c]==0)1 else 0))

        num[belt[i]]--
        if(num[belt[i]]==0) t--
        num[belt[(i+k)%N]]++
        if(num[belt[(i+k)%N]]==1) t++

    }

    bw.write(ans.toString())
    bw.flush()
}