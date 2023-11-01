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

    int N;    // total number of nodes in the graph
    
public:
    int* degrees;
    // An array of pointers to Node to represent the
    // adjacency list
    Node** head;

    // Constructor
    Graph(Edge edges[], unsigned int n, int N);


    bool edgeExists(int src, int dest);

    // Destructor
    ~Graph();

    // Function to print all neighboring vertices of a given vertex
    void printList(Node* ptr);

};

#endif