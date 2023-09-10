#include "Dijkstra.h" // Include the Dijkstra's algorithm header file from our repository
#include "Graph.h"    // Include the graph data structure header file from our repository

// Define your heuristic function here (e.g., Euclidean distance)
double heuristic(const Vertex& current, const Vertex& target) {
    // Replace this with your actual heuristic calculation
    return 0.0; // Placeholder value; update with your heuristic calculation
}

int main() {
    // Initialize our graph and other necessary data structures
    Graph graph; // Replace 'Graph' with the actual graph data structure class from our repository

    // Load our graph data from a file in the specified format
    // (Make sure to replace "graph_data.txt" with the actual file path)
    if (!loadGraphFromFile("graph_data.txt", graph)) {
        std::cerr << "Failed to load graph data from the file." << std::endl;
        return 1; // Exit with an error code
    }

    // Create an instance of Dijkstra's algorithm with A* Search modification
    Dijkstra<Graph> astar(graph);

    const int num_pairs = 200; // Number of random source-destination pairs
    double total_runtime = 0.0;

    srand(time(nullptr));

    for (int i = 0; i < num_pairs; ++i) {
        int source = rand() % graph.numVertices(); // Select a random source node
        int target = rand() % graph.numVertices(); // Select a random target node

        clock_t start_time = clock(); // Start measuring time

        // Run A* Search algorithm to find the shortest path from 'source' to 'target'
        astar.run(source, target, heuristic);

        clock_t end_time = clock(); // Stop measuring time after A* Search algorithm finishes
        double runtime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        total_runtime += runtime;

        // You can access the shortest path and its length here if needed
        // std::vector<int> shortestPath = astar.getPath(target);
        // int shortestPathLength = astar.getDistance(target);
    }

    // Print the total runtime for the 200 random A* Search runs
    std::cout << "Total runtime in seconds for " << num_pairs << " random modified Dijkstra (A* Search): " << total_runtime << std::endl;

    return 0;
}
