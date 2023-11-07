#include <iostream>
#include <exception> // Include the exception header
#include "../include/Graph.hpp"
#include "../include/GreedyAlgorithm.hpp"
#include "../include/Sort.hpp"

int main()
{
    try {
        char method;
        int verticesNumber;

        std::cin >> method;
        std::cin >> verticesNumber;

        if (verticesNumber <= 0) 
        {
            throw std::invalid_argument("Number of vertices must be greater than zero.");
        }

        Graph graph = graphBuilding(verticesNumber);

        sortMethodSelection(method, graph.head, graph.getSize());

        bool result = greedyAlgorithm_check(graph.head, graph.getSize());

        if (result == 0) {
            std::cout << result << std::endl;
        } else {
            std::cout << result << " ";
            graph.printGraph();
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Return a non-zero exit code to indicate an error
    }

    return 0;
}
