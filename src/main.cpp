#include <iostream>
#include "../include/Graph.hpp"
#include "../include/GreedyAlgorithm.hpp"

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
    Edge edges[100];
    edges->edgeAssign(edges, verticesNumber);

    // Catches the color of all vertices
    Node verticesColor[verticesNumber];
    verticesColor->verticesColoring(verticesColor, verticesNumber);

    // Builds the graph and colour its vertices
    Graph graph(edges, edges->edgeCount, verticesNumber, verticesColor);


    // Print adjacency list representation of a graph
    for (int i = 0; i < verticesNumber; i++) {
        cout << i;

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