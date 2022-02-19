fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val arrList = ArrayList<Pair<Long, Long>>().apply {
        repeat(N) {
            br.readLine().split(' ').map { it.toLong() }.let { point ->
                if (point[0] > point[1]) add(point[1] to point[0])
            }
        }
        sortBy { it.first }
    }
    var ans = M.toLong()
    var s = 0L
    var e = 0L
    arrList.forEach {
        if (e <= it.first) {
            ans += (e - s) * 2
            s = it.first
            e = it.second
        }
        e=e.coerceAtLeast(it.second)
    }
    ans += (e - s) * 2
    println("$ans\n")

}