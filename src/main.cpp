#include <iostream>
#include <exception>
#include "../include/Graph.hpp"
#include "../include/Sort.hpp"

int main()
{
    try {
        char method;
        int verticesNumber;

        std::cin >> method >> verticesNumber;

        if (verticesNumber <= 0) 
        {
            throw std::invalid_argument("Number of vertices must be greater than zero.");
        }

        Graph graph = graphBuilding(verticesNumber);

        graph.sortVertices(method);

        bool result = graph.greedyAlgorithm_check();

        if (!result) {
            std::cout << result << std::endl;
        } else {
            std::cout << result << " ";
            graph.printGraph();
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
