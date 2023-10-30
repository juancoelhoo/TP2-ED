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
    Node* getAdjListNode(int dest, Node* head)
    {
        Node* newNode = new Node;
        newNode->val = dest;

        // point new node to the current head
        newNode->next = head;

        return newNode;
    }

    int N;    // total number of nodes in the graph

public:

    // An array of pointers to Node to represent the
    // adjacency list
    Node **head;

    // Constructor
    Graph(Edge edges[], unsigned int n, int N)
    {
        // allocate memory
        head = new Node*[N]();
        this->N = N;

        // initialize head pointer for all vertices
        for (int i = 0; i < N; i++) {
            head[i] = nullptr;
        }

        // add edges to the directed graph
        for (unsigned i = 0; i < n; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            // Insert the edge only if it doesn't already exist
            if (!edgeExists(src, dest))
            {
                Node* newNode = getAdjListNode(dest, head[src]);
                head[src] = newNode;

                // Uncomment the following code for undirected graph
                newNode = getAdjListNode(src, head[dest]);
                head[dest] = newNode;
            }
        }
    }

    bool edgeExists(int src, int dest)
    {
        // Check if the edge already exists in the adjacency list
        Node* current = head[src];
        while (current)
        {
            if (current->val == dest)
                return true;
            current = current->next;
        }
        return false;
    }

    // Destructor
    ~Graph() {
        for (int i = 0; i < N; i++) {
            Node* current = head[i];
            while (current) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] head;
    }
};

// Function to print all neighboring vertices of a given vertex
void printList(Node* ptr)
{
    while (ptr != nullptr)
    {
        cout << " —> " << ptr->val;
        ptr = ptr->next;
    }
    cout << endl;
}