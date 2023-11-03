#include <iostream>
#include "../include/Graph.hpp"
#include "../include/GreedyAlgorithm.hpp"
#include "../include/Sort.hpp"

Graph graphBuilding(int verticesNumber)
{
    // Builds the edges
    Edge edges [verticesNumber * 2];
    edges->edgeAssign(edges, verticesNumber);

    // Assigns the color of all vertices
    Node verticesColor[verticesNumber];

    for (int i = 0; i < verticesNumber; i++) {
        int color; // You can read the color from input
        verticesColor[i].val = i; // Set the vertex ID
        verticesColor[i].color = color; // Set the color
    }
    
    verticesColor->verticesColoring(verticesColor, verticesNumber);

    // Builds the graph and colour its vertices
    Graph graph(edges, edges->edgeCount, verticesNumber, verticesColor);

    return graph;
}

int main()
{   
    string input;
    getline(cin, input);

    char method;
    int verticesNumber;
    istringstream iss(input);
    if (iss >> method >> verticesNumber) {
        cout << "Character: " << method << "; ";
        cout << "Integer: " << verticesNumber << endl;
    } else {
        cout << "Invalid input format." << endl;
    }

    Graph graph = graphBuilding (verticesNumber);
    
    sortMethodSelection(method, graph.head, graph.getSize());

    bool result = greedyAlgorithm_check(graph.head, graph.getSize());

    if (result == 0) cout << result;
    else
    {    
        cout << result << " ";
        graph.printGraph();
    }
    cout << endl;

    return 0;
}