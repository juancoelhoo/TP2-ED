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

    Edge edges[100];
    edges->edgeAssign(edges, verticesNumber);

    Node vertices[verticesNumber];
    vertices->verticesColoring(vertices, verticesNumber);

    Graph graph(edges, edges->edgeCount, verticesNumber, vertices);


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