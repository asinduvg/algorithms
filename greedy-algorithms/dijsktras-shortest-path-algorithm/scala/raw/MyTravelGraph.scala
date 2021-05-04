trait MyGraph[V] {
  def vertices: List[V]

  def edges: List[(V, V)]

  def addEdge(a: V, b: V): MyGraph[V]

  def neighbors(x: V): List[V]

}

//object MyGraph {
//  def apply[V](adjacencyList: Map[V, List[V]]): MyGraph[V] =
//    new MyDirectedGraph[V](adjacencyList)
//
//  def apply[V](): MyGraph[V] = new MyDirectedGraph[V](Map[V, List[V]]())
//}

//class MyDirectedGraph[V](adjacencyList: Map[V, List[V]]) extends MyGraph[V] {
//  override def vertices: List[V] = adjacencyList.keys.toList
//
//  override def edges: List[(V, V)] =
//    adjacencyList.map(i => i._2.map(j => (i._1, j))).flatten.toList
//
//  override def addEdge(a: V, b: V): MyGraph[V] =
//    new MyDirectedGraph[V](adjacencyList + (a -> (b :: neighbors(a))))
//
//  override def neighbors(x: V): List[V] =
//    adjacencyList.getOrElse(x, Nil)
//}

//class MyUndirectedGraph[V](adjacencyList: Map[V, List[V]]) extends MyDirectedGraph[V](adjacencyList) {
//  override def addEdge(a: V, b: V): MyGraph[V] =
//    new MyUndirectedGraph[V](adjacencyList + (a -> (b :: neighbors(a)), b -> (a :: neighbors(b))))
//}

class MyWeightedGraph[V](adjacencyList: Map[V, List[MyWeightedEdge[V]]]) extends MyGraph[V] {
  override def vertices: List[V] = adjacencyList.keys.toList

  override def edges: List[(V, V)] =
    adjacencyList.flatMap {
      case (k, v) => v.map(i => (k, i.destVertex))
    }.toList

  def addEdge(a: V, myWeightedEdge: MyWeightedEdge[V]): MyWeightedGraph[V] = {
    new MyWeightedGraph[V](adjacencyList + (a -> (myWeightedEdge :: neighborsWithWeight(a))))
  }

  override def addEdge(a: V, b: V): MyWeightedGraph[V] =
    addEdge(a, new MyWeightedEdge[V](b, weight = 0))

  override def neighbors(x: V): List[V] =
    adjacencyList.getOrElse(x, Nil).map(_.destVertex)

  def neighborsWithWeight(x: V): List[MyWeightedEdge[V]] =
    adjacencyList.getOrElse(x, Nil)
}

case class MyWeightedEdge[V](destVertex: V, weight: Int)

object MyTravelGraph {
  val travelGraph: MyWeightedGraph[String] = new MyWeightedGraph(Map("Home"
    -> Nil))
    .addEdge("Home", MyWeightedEdge("C", 1))
    .addEdge("Home", MyWeightedEdge("D", 0))
    .addEdge("Home", MyWeightedEdge("E", 7))
    .addEdge("C", MyWeightedEdge("G", 11))
    .addEdge("D", MyWeightedEdge("G", 5))
    .addEdge("E", MyWeightedEdge("G", 3))
    .addEdge("E", MyWeightedEdge("F", 5))
    .addEdge("F", MyWeightedEdge("H", 7))
    .addEdge("F", MyWeightedEdge("I", 10))
    .addEdge("G", MyWeightedEdge("J", 1))
    .addEdge("H", MyWeightedEdge("J", 0))
    .addEdge("I", MyWeightedEdge("K", 2))
    .addEdge("J", MyWeightedEdge("Work", 25))
    .addEdge("K", MyWeightedEdge("Work", 25))
    .addEdge("Work", MyWeightedEdge("K", 25))
  //    .addEdge("Guangzhou", MyWeightedEdge("Kathmandu", 214))
  //    .addEdge("Hong Kong", MyWeightedEdge("Kathmandu", 400))
  //    .addEdge("Kunming", MyWeightedEdge("Kathmandu", 105))
  //    .addEdge("Doha", MyWeightedEdge("Kathmandu", 1287))
  //    .addEdge("Istanbul", MyWeightedEdge("Kathmandu", 300))
  //    .addEdge("Delhi", MyWeightedEdge("Kathmandu", 300))
  //    .addEdge("Kathmandu", MyWeightedEdge("Delhi", 300))
}
