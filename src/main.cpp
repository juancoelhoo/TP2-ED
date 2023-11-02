#include <iostream>
#include "../include/Graph.hpp"
#include "../include/GreedyAlgorithm.hpp"
#include "../include/Sort.hpp"

void parseArgs()
{
    string input;
    getline(cin, input);

    char method;
    int verticesNumber;
    istringstream iss(input); 
    if (iss >> method >> verticesNumber) {
        cout << "Character: " << method << endl;
        cout << "Integer: " << verticesNumber << endl;
    } else {
        cout << "Invalid input format." << endl;
    }

    // Builds the edges
    Edge edges[verticesNumber * 2];
    edges->edgeAssign(edges, verticesNumber);

    // Assigns the color of all vertices
    Node verticesColor[verticesNumber];
    verticesColor->verticesColoring(verticesColor, verticesNumber);

    // Builds the graph and colour its vertices
    Graph graph(edges, edges->edgeCount, verticesNumber, verticesColor);

    bubbleSort(graph.head, verticesNumber);

    // Print adjacency list representation of a graph
    for (int i = 0; i < verticesNumber; i++) {
        cout << graph.head[i]->val;

        graph.printList(graph.head[i]);
        cout << "Color: " << graph.head[i]->color << endl;
    }

}


int main()
{
    //Reads the input from the user
    parseArgs();

    return 0;
}