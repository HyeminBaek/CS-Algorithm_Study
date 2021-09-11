import java.util.*

class Solution {

    data class Node(val info:Triple<Int,Int,Int>, var left:Node?=null, var right:Node?=null)
    val pre=ArrayList<Int>()
    val post=ArrayList<Int>()
    lateinit var root:Node
    fun initTree(nodeInfo:Triple<Int,Int,Int>){
        initTree(nodeInfo,root)
    }
    private fun initTree(nodeInfo:Triple<Int,Int,Int>, now:Node){

        if(now.info.second>nodeInfo.second){
            when(now.left){
                null->now.left=Node(nodeInfo)
                else->initTree(nodeInfo,now.left!!)
            }

        }else{
            when(now.right){
                null->now.right=Node(nodeInfo)
                else->initTree(nodeInfo,now.right!!)
            }
        }

    }

    fun preOrder(now:Node){
        pre.add(now.info.first)
        if(now.left!=null){
            preOrder(now.left!!)
        }
        if(now.right!=null){
            preOrder(now.right!!)
        }

    }
    fun postOrder(now:Node){
        if(now.left!=null){
            postOrder(now.left!!)
        }
        if(now.right!=null){
            postOrder(now.right!!)
        }


        post.add(now.info.first)
    }

    fun solution(nodeinfo: Array<IntArray>): Array<IntArray> {
        var answer = arrayOf<IntArray>()
        val NodeInfo=ArrayList<Triple<Int,Int,Int>>()
        nodeinfo.forEachIndexed{index,it->
            NodeInfo.add(Triple<Int,Int,Int>(index+1,it[0],it[1]))
        }
        NodeInfo.sortWith(Comparator{a:Triple<Int,Int,Int>,b:Triple<Int,Int,Int>->
            when{
                a.third<b.third->1
                a.third>b.third->-1
                else->0
            }

        })

        root=Node(NodeInfo[0])
        (1..NodeInfo.size-1).forEach{
            initTree(NodeInfo[it])
        }
        preOrder(root)
        postOrder(root)

        answer=arrayOf(pre.toIntArray(),post.toIntArray())
        return answer
    }
}