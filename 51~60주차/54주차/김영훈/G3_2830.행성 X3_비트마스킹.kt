fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val bit=Array(30){0}
    val N=br.readLine().toInt()
    repeat(N){
        var k=br.readLine().toInt()
        var idx=0
        while(k>0){
            bit[idx++]+=k%2
            k/=2
        }
    }
    var ans=0L
    for(i in 0..23)  ans+=(1L shl i)*(bit[i].toLong()*(N-bit[i]))
    println(ans)
}