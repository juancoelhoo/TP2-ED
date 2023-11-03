#include <iostream>
#include "../include/Graph.hpp"
#include "../include/GreedyAlgorithm.hpp"
#include "../include/Sort.hpp"
void sortAndprintGraph(char method, Node** AdjacencyList, int verticesNumber)
{
    sortMethodSelection(method, AdjacencyList, verticesNumber);

    bool result = greedyAlgorithm_check(AdjacencyList, verticesNumber);

    if (result == 0) cout << result;
    else
    {    
        cout << result << " ";

        // Print adjacency list representation of a graph
        for (int i = 0; i < verticesNumber; i++) {
            cout << (AdjacencyList[i]->val) << " ";
        }
    }
    cout << endl;
}

void graphBuilding(){
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

    for (int i = 0; i < verticesNumber; i++) {
        int color; // You can read the color from input
        verticesColor[i].val = i; // Set the vertex ID
        verticesColor[i].color = color; // Set the color
    }
    
    verticesColor->verticesColoring(verticesColor, verticesNumber);

    // Builds the graph and colour its vertices
    Graph graph(edges, edges->edgeCount, verticesNumber, verticesColor);

    sortAndprintGraph(method, graph.head, verticesNumber);

}

int main()
{
    //Reads the input from the user
    graphBuilding();

    return 0;
}