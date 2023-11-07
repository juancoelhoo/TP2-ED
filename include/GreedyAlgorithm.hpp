#ifndef GREEDYALGORITHM_HPP
#define GREEDYALGORITHM_HPP
#include "../include/Graph.hpp"

bool greedyAlgorithm_check(Node** adjacencyList, int verticesNumber)
{
    for (int i = 0; i < verticesNumber; i++) {
        Node* currentVertex = adjacencyList[i];
        int vertex_color = currentVertex->color;
        if (vertex_color == 1) {
            continue;
        }

        Node* neighbourVertex = currentVertex->next;

        bool verification[vertex_color - 1] = {false};

        int j = 0; // Initialize j to keep track of the index in verification

        for (auto it = neighbourVertex; it != nullptr; it = it->next) {
            if (it->color < vertex_color) {
                int index = it->color - 1;
                if (index >= 0 && index < vertex_color - 1) {
                    verification[index] = true;
                }
            }
            j++;
        }

        for (int i = 0; i < vertex_color - 1; i++) {
            if (!verification[i]) {
                return false;
            }
        }
    }

    return true; // Return true if all vertices pass the check
}


#endif
