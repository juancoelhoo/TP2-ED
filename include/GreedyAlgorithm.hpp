#ifndef GREEDYALGORITHM_HPP
#define GREEDYALGORITHM_HPP
#include "../include/Graph.hpp"

bool greedyAlgorithm_check(Graph graph, int verticesNumber)
{
    for (int i = 0; i < verticesNumber; i++) {
        Node* currentVertex = graph.head[i];
        int vertex_color = currentVertex->color;
        bool hasSmallerColorNeighbor = false;

        Node* neighbor = currentVertex->next;

        while (neighbor != nullptr) {
            int neighbor_color = neighbor->color;
            if (neighbor_color < vertex_color) {
                hasSmallerColorNeighbor = true;
                break; // We found a neighbor with a smaller color
            }
            neighbor = neighbor->next;
        }

        if (!hasSmallerColorNeighbor) {
            // The current vertex does not have a neighbor with a smaller color
            return false;
        }
    }

    // If the loop completes, it means the greedy coloring is valid
    return true;
}

#endif