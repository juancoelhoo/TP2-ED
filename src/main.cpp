#include <iostream>
#include "../include/Graph.hpp"

void parseArgs()
{
    string input;
    getline(cin, input);  // Read a line of input as a string

    char method;
    int verticesNumber;
    istringstream iss(input);  // Use a stringstream to parse the input string
    if (iss >> method >> verticesNumber) {
        // Successfully parsed a character followed by an integer
        cout << "Character: " << method << endl;
        cout << "Integer: " << verticesNumber << endl;
    } else {
        cout << "Invalid input format." << endl;
    }

    Edge edges[100];  // Adjust the array size as needed
    unsigned int edgeCount = 0;

    for (int i = 0; i < verticesNumber; i++) {
        string input;
        getline(cin, input);

        int m; // Number of neighbors
        istringstream iss(input);
        iss >> m;

        for (int j = 0; j < m; j++) {
            int neighbor;
            iss >> neighbor;

            // Add an edge from vertex i to neighbor
            edges[edgeCount].src = i;
            edges[edgeCount].dest = neighbor;
            edgeCount++;

            // Add the corresponding edge from neighbor to vertex i
            edges[edgeCount].src = neighbor;
            edges[edgeCount].dest = i;
            edgeCount++;
        }
    }

    // construct graph
    Graph graph(edges, edgeCount, verticesNumber);

    // print adjacency list representation of a graph
    for (int i = 0; i < verticesNumber; i++)
    {
        // print given vertex
        cout << i;

        // print all its neighboring vertices
        printList(graph.head[i]);
    }
}


int main()
{
    //Reads the input from the user
    parseArgs();

    return 0;
}