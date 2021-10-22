import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    var str = br.readLine()
    while (str != "end") {
        val board = Array(3) { r -> Array(3) { c -> str[r * 3 + c] } }
        val firstNum = str.count { it == 'X' }
        val secondNum = str.count { it == 'O' }
        val emptyNum = str.count { it == '.' }
        var firstWin = false
        var secondWin = false

        val isValidPos = { r: Int, c: Int -> (r>=0 && c>=0 && r <= 2 && c <= 2) }
        for (r in 0..2) {
            for (c in 0..2) {
                if (board[r][c] == '.') continue
                else {
                    val t = board[r][c]
                    var flag = false
                    if (isValidPos(r + 1, c) && board[r + 1][c] == board[r][c] &&
                        isValidPos(r + 2, c) && board[r + 2][c] == board[r][c]
                    ) flag = true
                    if (isValidPos(r, c + 1) && board[r][c + 1] == board[r][c] &&
                        isValidPos(r, c + 2) && board[r][c + 2] == board[r][c]
                    ) flag = true
                    if (isValidPos(r + 1, c + 1) && board[r + 1][c + 1] == board[r][c] &&
                        isValidPos(r + 2, c + 2) && board[r + 2][c + 2] == board[r][c]
                    ) flag = true

                    if (isValidPos(r + 1, c - 1) && board[r + 1][c - 1] == board[r][c] &&
                        isValidPos(r + 2, c - 2) && board[r + 2][c - 2] == board[r][c]
                    ) flag = true
                    when (board[r][c]) {
                        'X' -> firstWin = firstWin or flag
                        else -> secondWin = secondWin or flag
                    }


                }

            }
        }
        if (emptyNum == 0 && firstNum == secondNum + 1 && !secondWin) bw.write("valid\n")
        else if (firstWin != secondWin) {
            if ((firstWin && firstNum == secondNum + 1) || (secondWin && firstNum == secondNum)) {
                bw.write("valid\n")
            } else {
                bw.write("invalid\n")
            }
        } else {
            bw.write("invalid\n")
        }

        str = br.readLine()
    }
    bw.flush()
}