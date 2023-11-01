#ifndef GREEDYALGORITHM_HPP
#define GREEDYALGORITHM_HPP
#include <sstream>
#include "../include/Graph.hpp"


// Read colors for each vertex and assign to the corresponding node

void verticesColoring(Node* vertices, int verticesNumber)
{
    string colorLine;
    getline(cin, colorLine);
    istringstream colorIss(colorLine);

    for (int i = 0; i < verticesNumber; i++) {
        colorIss >> vertices[i].color;
    }
}

#endif