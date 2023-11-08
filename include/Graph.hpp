#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <string>
using namespace std;

// Data structure to store adjacency list nodes
struct Node
{
    int val, color;
    Node* next;

    // Constructor for Node
    Node(int vertex, int clr) : val(vertex), color(clr), next(nullptr) {}
    Node() : val(-1), color(-1), next(nullptr) {}

    void verticesColoring(Node* vertices, int verticesNumber)
    {
        for (int i = 0; i < verticesNumber; i++) {
            cin >> vertices[i].color;
        }
    }   
};


// Data structure to store a graph edge
struct Edge {
    int src, dest;
    unsigned int edgeCount = 0;

    void edgeAssign(Edge* edges, int n)
    {
        for (int i = 0; i < n; i++) {
        int neighborNumber;
        cin >> neighborNumber;

        for (int j = 0; j < neighborNumber; j++) {
                int neighbor;
                cin >> neighbor;

                // Add an edge from vertex i to neighbor
                edges[edgeCount].src = i;
                edges[edgeCount].dest = neighbor;
                edgeCount++;
            }   
        }  
    }
};


class Graph
{
    // Function to allocate a new node for the adjacency list
    Node* getAdjListNode(int dest, Node* head);

    int N;
    
public:
    int* degrees;
    Node** head;

    // Constructor
    Graph(Edge edges[], unsigned int n, int N, Node* vertices);

    // Returns the graph size
    int getSize();

    // Checks if the edge exists 
    bool edgeExists(int src, int dest);

    // Sorts the Graph vertices by its color
    void sortVertices(char method);

    // Checks if it's possible to determine whether
    // the graph is properly colored using a greedy algorithm
    bool greedyAlgorithm_check();

    // Function to print all neighboring vertices of a given vertex
    void printList(Node* ptr);

    // Prints the vertices neighbours of a vertex
    void printGraph();

    // Destructor
    ~Graph();

};

// Asks inputs from the user and builds the graph
Graph graphBuilding(int verticesNumber);

#endif