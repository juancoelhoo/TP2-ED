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
};

class Graph
{
    // Function to allocate a new node for the adjacency list
    Node* getAdjListNode(int dest, Node* head);

    int N;    // total number of nodes in the graph

public:

    // An array of pointers to Node to represent the
    // adjacency list
    Node **head;

    // Constructor
    Graph(Edge edges[], unsigned int n, int N);

    bool edgeExists(int src, int dest);

    // Destructor
    ~Graph();

    // Function to print all neighboring vertices of a given vertex
    void printList(Node* ptr);
};


