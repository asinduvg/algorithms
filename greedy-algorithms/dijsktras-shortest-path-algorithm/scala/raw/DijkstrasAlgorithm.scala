import scala.util.Try
import MyTravelGraph.travelGraph

case class ShortStep(parents: Map[String, String], unVisited: Set[String], distances: Map[String, Int]) {
  def findMin(): Option[(String, Int)] = {
    Try(unVisited.minBy(distances)).toOption.map(x => (x, distances(x)))
  }
}

object DijkstrasAlgorithm {

  def main(args: Array[String]): Unit = {

    val spResult = findShortestPath(ShortStep(Map(), travelGraph.vertices.toSet, distancesMap))

    println(shortestPath("Work", spResult.parents).reverse)

  }

  val distancesMap: Map[String, Int] = travelGraph.vertices.map(_ -> Int.MaxValue).toMap + ("Home" -> 0)

  def findShortestPath(step: ShortStep): ShortStep = {

    step.findMin().map {
      case (x, currentDist) =>
        val newDists = travelGraph neighborsWithWeight x collect {
          case MyWeightedEdge(y, w) if step.distances.get(y).exists(_ > currentDist + w) => y -> (currentDist + w)
        }
        val newParents = newDists map {
          case (y, _) => y -> x
        }
        findShortestPath(ShortStep(step.parents ++ newParents, step.unVisited - x, step.distances ++ newDists))
    }.getOrElse(step)
  }

  def shortestPath(vertex: String, parents: Map[String, String]): List[String] =
    parents.get(vertex).map(x => vertex +: shortestPath(x, parents)).getOrElse(List(vertex))

}
