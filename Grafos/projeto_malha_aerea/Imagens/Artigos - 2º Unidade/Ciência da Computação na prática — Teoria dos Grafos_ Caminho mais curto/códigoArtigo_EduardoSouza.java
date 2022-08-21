//TODOS OS DIREITOS DESTE CÓDIGO RESERVADOS PARA EDUARDO SOUZA, AUTOR DO ARTIGO

import java.util.*

fun main(args: Array<String>) {

// creating vertices
    val r = Vertex("r")
    val s = Vertex("s")
    val t = Vertex("t")
    val u = Vertex("u")
    val v = Vertex("v")
    val w = Vertex("w")
    val x = Vertex("x")
    val y = Vertex("y")
    val listOfVertices = listOf<Vertex>(r, s, t, u, v, w, x, y)

// creating edges
    val listOfEdges = listOf<Edge>(
        Edge(r, v),
        Edge(r, s),
        Edge(s, w),
        Edge(w, t),
        Edge(w, x),
        Edge(t, x),
        Edge(t, u),
        Edge(x, u),
        Edge(x, y),
        Edge(u, y)
    )

// Initializing graph
    val graph = Graph(listOfVertices, listOfEdges)

    val ancestors = mutableMapOf<Vertex, Vertex?>()

    BFS(graph, s, ancestors)

// print shortest path from s to u
    shortestPath(s, u, ancestors)
    println()

// print shortest path from s to y
    shortestPath(s, y, ancestors)
    println()

// print shortest path from s to t
    shortestPath(s, t, ancestors)
    println()
}

data class Vertex(val label: String)
data class Edge(val from: Vertex, val to: Vertex)
data class Graph(val vertices: List<Vertex>, val edges: List<Edge>) {
    /**
     * Given a vertex, return a list with its adjacent vertices
     * @param vertex Vertex
     * @return list of adjacent vertices of vertex
     */
    fun adjacent(vertex: Vertex): List<Vertex> {
        return edges.filter { it.to == vertex || it.from == vertex }
            .map { if (it.from != vertex) it.from else it.to }
    }
}

enum class Visited {
    WHITE, GREY, BLACK
}

/**
 * Breadth-first Search.
 */
fun BFS(g: Graph, s: Vertex, ancestors: MutableMap<Vertex, Vertex?>) {
    val distances = mutableMapOf<Vertex, Int?>()
    val color = mutableMapOf<Vertex, Visited>()

    val nodes = g.vertices.filterNot { it === s } // all vertices but origin (s)

    // "clean" maps of distances, colors and ancestors
    for (n in nodes) {
        distances[n] = Int.MAX_VALUE
        color[n] = Visited.WHITE
        ancestors[n] = null
    }

    // start visiting origin and marking it as visited
    color[s] = Visited.GREY
    distances[s] = 0
    ancestors[s] = null

    val queue: Queue<Vertex> = LinkedList<Vertex>()
    queue.add(s)

    // While has vertices to visit, continue
    while (queue.isNotEmpty()) {
        val u = queue.poll()

        val adj = g.adjacent(u) // get all adjacent vertices of u
        for (v in adj) {

            // if not visited
            if (color[v] == Visited.WHITE) {
                color[v] = Visited.GREY // mark it as visited
                distances[v] = distances[u]?.plus(1) // increment distance from origin
                ancestors[v] = u // mark u as ancestor of v
                queue.add(v) // put v in list of vertices that it's adjacent vertices wasn't visited
            }

        }

        color[u] = Visited.BLACK // was visited and has not adjacent vertices to visit
    }

}

fun shortestPath(s: Vertex, v: Vertex?, ancestors: MutableMap<Vertex, Vertex?>) {
    if (s == v) print(s.label)
    else if (ancestors[v] == null) println("There is no path from ${s.label} to ${v?.label}")
    else {
        shortestPath(s, ancestors[v], ancestors)
        print(" -> ${v?.label}")
    }

}