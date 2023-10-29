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
    Graph(Edge edges[], int n, int N)
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

int main()
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
    int edgeCount = 0;

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

    // calculate the total number of edges
    int edgeNumber = edgeCount;

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

    return 0;
}
