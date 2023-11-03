#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <string>
#include <sstream>
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
        string colorLine;
        getline(cin, colorLine);
        istringstream colorIss(colorLine);

        for (int i = 0; i < verticesNumber; i++) {
            colorIss >> vertices[i].color;
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
            string input;
            getline(cin, input);

            int neighborNumber;
            istringstream iss(input);
            iss >> neighborNumber;

                for (int j = 0; j < neighborNumber; j++) {
                    int neighbor;
                    iss >> neighbor;

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

    // Function to print all neighboring vertices of a given vertex
    void printList(Node* ptr);

    // Prints the vertices neighbours of a vertex
    void printNeighboringVertices(int vertex);

    // Destructor
    ~Graph();

};

#endif