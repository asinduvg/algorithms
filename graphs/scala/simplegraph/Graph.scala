import scala.annotation.tailrec

object Graph extends App {

  val myGraph = List(("a", "b"), ("a", "c"), ("b", "d"),
    ("b", "e"), ("b", "c"), ("c", "e"), ("d", "f"))

  def calcSuccessorSet(vertex: String, graph: List[(String, String)]): List[String] = {
    graph match {
      case Nil => Nil
      case x :: rest if vertex == x._1 =>
        x._2 :: calcSuccessorSet(vertex, rest)
      case _ :: rest => calcSuccessorSet(vertex, rest)
    }
  }

  

  def traverseDepthFirst(start: String, graph: List[(String, String)]): List[String] = {
    def depthFirst(vertices: List[String], visited: List[String]): List[String] = vertices match {
      case Nil => visited
      case s :: rest => depthFirst(rest,
        if (visited.contains(s)) visited
        else depthFirst(calcSuccessorSet(s, graph), s :: visited)
      )
    }

    val result = depthFirst(List(start), List())
    result.reverse

  }

  println(traverseDepthFirst("a", myGraph))

  def traverseBreadthFirst(start: String, graph: List[(String, String)]): List[String] = {
    @tailrec
    def breadthFirst(vertices: List[String], visited: List[String]): List[String] = vertices match {
      case Nil => visited
      case s :: rest if visited.contains(s) => breadthFirst(rest, visited)
      case s :: rest => breadthFirst(rest ++ calcSuccessorSet(s, graph), s :: visited)

    }

    breadthFirst(List(start), List()).reverse
  }

  println(traverseBreadthFirst("a", myGraph))

}
