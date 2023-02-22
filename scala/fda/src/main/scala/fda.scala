import scala.util.parsing.json._
import scala.io.Source
import java.nio.file.{FileSystems, Files}
import scala.collection.JavaConverters._
import scala.collection.immutable.HashMap
import scala.collection.mutable
import scala.collection.mutable.PriorityQueue

case class State(name: String, freq: Int)

object fda {
  /**
   * Returns the text (content) from a URL as a String.
   * Warning: This method does not time out when the service is non-responsive.
   */
  def get(url: String) = scala.io.Source.fromURL(url).mkString

  def getList(parsedJson: Option[Any], key: String): List[Any] = {
    parsedJson match {
      case Some(m: Map[String, Any]) => m(key) match {
        case d: List[Any] => d
      }
    }
  }

  def getString(parsedJson: Option[Any], key: String): String = {
    parsedJson match {
      case Some(m: Map[String, Any]) => m(key) match {
        case d: String => d
      }
    }
  }

  def adjust[A, B](m: Map[A, B], k: A)(f: B => B) = m.updated(k, f(m(k)))

  private def stateOrder(d: State) = -d.freq

  private def yearOrder(d: State) = d.freq

  def main(args: Array[String]) = {
    //var link = "https://download.open.fda.gov/food/enforcement/food-enforcement-0001-of-0001.json.zip"
    val filename = "./food-enforcement-0001-of-0001.json"
    val str = Source.fromFile(filename).getLines().mkString;

    val parsed = JSON.parseFull(str)
    val mapping1 = scala.collection.mutable.Map[String, Int]()
    val mapping2017 = scala.collection.mutable.Map[String, Int]()
    val mappingYear = scala.collection.mutable.Map[String, Int]()

    val list = getList(parsed, "results")
    var cnt = 0
    for (json <- list) {
      val obj = json.asInstanceOf[HashMap[String, String]]
      if (obj("classification").equals("Class III") && obj("state").nonEmpty) {
        if (mapping1.contains(obj("state"))) {
          mapping1(obj("state")) = mapping1(obj("state")) + 1
        } else {
          mapping1 += (obj("state") -> 1)
        }
      }
      if (obj("report_date").startsWith("2017") && obj("state").nonEmpty) {
        if (mapping2017.contains(obj("state"))) {
          mapping2017(obj("state")) += 1
        } else {
          mapping2017 += (obj("state") -> 1)
        }
      }
      if (obj("report_date").startsWith("2016")) {
        cnt += 1
      }
      if (obj("report_date").nonEmpty) {
        val year = obj("report_date").substring(0, 4)
        if (mappingYear.contains(year)) {
          mappingYear(year) += 1
        } else {
          mappingYear += (year -> 1)
        }
      }
    }
    val stateQueue: mutable.PriorityQueue[State] = mutable.PriorityQueue()(Ordering.by(stateOrder))

    for (key <- mapping1.keys) {
      stateQueue.enqueue(State(key, mapping1(key)))
      while (stateQueue.size > 10) {
        stateQueue.dequeue();
      }
    }
    println("1. Top States with Class III Hazard")
    val stateRes: mutable.Stack[State] = mutable.Stack()
    while (stateQueue.nonEmpty) {
      //State CA/Status Terminated: 164
      val key = stateQueue.dequeue()
      stateRes.push(key)
    }
    while (stateRes.nonEmpty) {
      val key = stateRes.pop()
      println("State " + key.name + "/Status Terminated: " + key.freq)
    }
    println("2. Average reports per month in 2016")
    println(cnt + " reports")
    println("---")
    println("3. Top States for 2017")
    val queue2017: mutable.PriorityQueue[State] = mutable.PriorityQueue()(Ordering.by(stateOrder))
    for (key <- mapping2017.keys) {
      queue2017.enqueue(State(key, mapping2017(key)))
      while (queue2017.size > 10) {
        queue2017.dequeue();
      }
    }
    val res2017: mutable.Stack[State] = mutable.Stack()
    while (queue2017.nonEmpty) {
      val key = queue2017.dequeue()
      res2017.push(key)
    }
    while (res2017.nonEmpty) {
      val key = res2017.pop()
      println(key.name + ": " + key.freq)
    }
    println("---")
    println("4. Top Years")
    val top: mutable.PriorityQueue[State] = mutable.PriorityQueue()(Ordering.by(yearOrder))
    for (key <- mappingYear.keys) {
      top.enqueue(State(key, mappingYear(key)))
    }
    var key = top.dequeue()
    println("Highest year is " + key.name + " with " + key.freq + " reports")
    while (top.size > 1) {
      top.dequeue()
    }
    key = top.dequeue()
    println("Lowest year is " + key.name + " with " + key.freq + " reports")
    Source.fromFile(filename).close()
  }
}
