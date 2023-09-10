//Code contributed by Krishna Pradeep Reddy S
#include "Dijkstra.h" // Include the Dijkstra's algorithm header file from our repository
#include "Graph.h"    // Include the graph data structure header file from our repository

int main() {
    // Initialize our graph and other necessary data structures
    Graph graph;
    if (!loadGraphFromFile("graph_data.txt", graph)) {
        std::cerr << "Failed to load graph data from the file." << std::endl;
        return 1; // Exit with an error code
    }

    // Create an instance of Dijkstra's algorithm
    Dijkstra<Graph> dijkstra(graph);

    const int num_pairs = 200; // Number of random source-destination pairs
    double total_runtime = 0.0;

    srand(time(nullptr));

    for (int i = 0; i < num_pairs; ++i) {
        int source = rand() % graph.numVertices(); // Select a random source node
        int target = rand() % graph.numVertices(); // Select a random target node

        clock_t start_time = clock(); // Start measuring time

        // Run Dijkstra's algorithm to find the shortest path from 'source' to 'target'
        dijkstra.run(source, target);

        clock_t end_time = clock(); // Stop measuring time after Dijkstra's algorithm finishes
        double runtime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        total_runtime += runtime;

        // We can access the shortest path and its length here if needed
        // std::vector<int> shortestPath = dijkstra.getPath(target);
        // int shortestPathLength = dijkstra.getDistance(target);
    }

    // Print the total runtime for the 200 random Dijkstra runs
    std::cout << "Total runtime in seconds for " << num_pairs << " random Dijkstra: " << total_runtime << std::endl;

    return 0;
}
