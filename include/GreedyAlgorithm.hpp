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

        int smallerColorCount = 0;

        Node* neighbourVertex = adjacencyList[i]->next;

        while (neighbourVertex != nullptr)
        {
            int neighborColor = neighbourVertex->color;
            if (neighborColor < vertex_color) {
                smallerColorCount++;
            }

            neighbourVertex = neighbourVertex->next;
        }

        if (smallerColorCount < (vertex_color - 1)) {
            return false;
        }
    }

    return true;
}

#endif
