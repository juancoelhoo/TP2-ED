#include "../include/Graph.hpp"

Node* Graph::getAdjListNode(int dest, Node* head)
{
        Node* newNode = new Node;
        newNode->val = dest;

        // point new node to the current head
        newNode->next = head;

        return newNode;
}

Graph::Graph(Edge edges[], unsigned int n, int N)
{
        // Allocate memory
    head = new Node*[N]();
    degrees = new int[N](); // Initialize degrees array to all zeros
    this->N = N;

    // Initialize head pointer for all vertices
    for (int i = 0; i < N; i++) {
        head[i] = nullptr;
    }

    for (unsigned i = 0; i < n; i++)
{
    int src = edges[i].src;
    int dest = edges[i].dest;

    // Insert the edge only if it doesn't already exist
    if (!edgeExists(src, dest))
    {
        Node* newNode = getAdjListNode(dest, head[src]);
        head[src] = newNode;

        // Uncomment the following code for an undirected graph
        // newNode = getAdjListNode(src, head[dest]);
        // head[dest] = newNode;

        // Update the degrees array for both vertices
        degrees[src]++;
        // degrees[dest]++;
    }
}
}

bool Graph::edgeExists(int src, int dest)
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

Graph::~Graph(){
    for (int i = 0; i < N; i++) {
        Node* current = head[i];
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] head;
    delete[] degrees;
}

void Graph::printList(Node* ptr)
{
    while (ptr != nullptr)
    {
        cout << " —> " << ptr->val;
        ptr = ptr->next;
    }
    cout << endl;
}
