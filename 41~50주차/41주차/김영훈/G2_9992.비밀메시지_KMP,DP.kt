import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

private const val MOD_NUM = 2014

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val str = br.readLine()
    val dp = Array(101) { Array(101) { 1 } }

    for (length in 2 until str.length) for (s in 0..str.length - length) {
        kmp(str, s, s + length - 1, dp)
    }

    bw.write((dp[0][str.length - 1] - 1).toString())
    bw.flush()
}

private fun kmp(fullStr: String, sIdx: Int, eIdx: Int, dp: Array<Array<Int>>) {
    // 1. 접두사를 접두사로
    val subStr = fullStr.substring(sIdx until eIdx)
    val fail = Array(subStr.length) { 0 }
    var j = 0
    for (idx in 1 until subStr.length) {
        while (j > 0 && subStr[idx] != subStr[j]) j = fail[j - 1]
        if (subStr[idx] == subStr[j]) fail[idx] = ++j
    }
    j = 0
    for (idx in 0 until sIdx) {
        while (j >= subStr.length || (j > 0 && fullStr[idx] != subStr[j])) j = fail[j - 1]
        if (fullStr[idx] == subStr[j]) ++j
    }
    while (j > 0) {
        dp[sIdx - j][eIdx] += dp[sIdx][eIdx]
        dp[sIdx - j][eIdx] %= MOD_NUM
        j = fail[j - 1]
    }

    //2. 접미사를 접두사로
    for (i in 1..subStr.length) {
        if (sIdx - i < 0) break
        if (fullStr[eIdx + 1 - i] != fullStr[sIdx - i]) break
        dp[sIdx - i][eIdx] += dp[sIdx][eIdx]
        dp[sIdx - i][eIdx] %= MOD_NUM
    }

    // 3. 접미사를 접미사로
    val subStrReversed = fullStr.substring(sIdx + 1..eIdx).reversed()
    val failReversed = Array(subStrReversed.length) { 0 }

    j = 0
    for (idx in 1 until subStrReversed.length) {
        while (j > 0 && subStrReversed[idx] != subStrReversed[j]) j = failReversed[j - 1]
        if (subStrReversed[idx] == subStrReversed[j]) failReversed[idx] = ++j
    }
    j = 0
    for (idx in fullStr.length - 1 downTo eIdx + 1) {
        while (j >= subStrReversed.length || (j > 0 && subStrReversed[j] != fullStr[idx])) j = failReversed[j - 1]
        if (fullStr[idx] == subStrReversed[j]) ++j
    }
    while (j > 0) {
        dp[sIdx][eIdx + j] += dp[sIdx][eIdx]
        dp[sIdx][eIdx + j] %= MOD_NUM
        j = failReversed[j - 1]
    }

    // 4. 접두사를 접미사로
    for (i in 1..subStrReversed.length) {
        if (eIdx + i >= fullStr.length) break
        if (fullStr[sIdx + i - 1] != fullStr[eIdx + i]) break
        dp[sIdx][eIdx + i] += dp[sIdx][eIdx]
        dp[sIdx][eIdx + i] %= MOD_NUM
    }

}