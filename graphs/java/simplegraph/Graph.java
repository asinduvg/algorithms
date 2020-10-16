package graphs.java.simplegraph;

import java.util.ArrayList;

public class Graph {
    private int vCount; // number of vertices
    private int eCount; // number of edges

    private ArrayList<Integer>[] adjacents; // array of integer lists

    public Graph(int vCount) {
        this.vCount = vCount;
        this.eCount = 0;
        adjacents = new ArrayList [vCount];

        for(int i = 0; i < vCount; i++) {
            adjacents[i] = new ArrayList<Integer>();
        }

    }

    public int getVertexCount() {
        return vCount;
    }

    public int getEdgeCount() {
        return eCount;
    }

    public void addEdge(int srcVertex, int destVertex) {
        adjacents[srcVertex].add(destVertex);
        eCount++;
    }

    public Object[] adj(int src) {
        return adjacents[src].toArray();
    }

}

