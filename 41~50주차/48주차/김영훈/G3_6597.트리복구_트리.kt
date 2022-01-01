fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class Node(val alp: Char, var left: Node? = null, var right: Node? = null)

    fun search(node: Node, preStr: String, inStr: String) {
        val leftInStr = inStr.substringBefore(node.alp)
        val rightInStr = inStr.substringAfter(node.alp)
        val leftPreStr = preStr.substring(1, 1 + leftInStr.length)
        val rightPreStr = preStr.substring(1 + leftPreStr.length)
        if (leftPreStr.isNotEmpty()) {
            node.left = Node(leftPreStr[0])
            search(node.left!!,leftPreStr,leftInStr)
        }
        if (rightPreStr.isNotEmpty()) {
            node.right = Node(rightPreStr[0])
            search(node.right!!,rightPreStr,rightInStr)
        }
        bw.write("${node.alp}")
    }

    var s = br.readLine()
    while (s != null) {
        val (preorder, inorder) = s.split(' ')
        val root = Node(preorder[0])
        search(root, preorder, inorder)
        bw.write("\n")
        s = br.readLine()
    }
    bw.close()
}