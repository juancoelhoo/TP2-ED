#include "../include/Graph.hpp"

Node* Graph::getAdjListNode(int dest, Node* head)
{
        Node* newNode = new Node(-1, -1);
        newNode->val = dest;  // Set the value of the new node
        newNode->next = head;  // Set the next pointer to the current head

    return newNode;
}

Graph::Graph(Edge edges[], unsigned int n, int N, Node* verticesColor)
{
    head = new Node*[N]();
    degrees = new int[N]();
    this->N = N;

    for (int i = 0; i < N; i++) {
        head[i] = new Node(i, verticesColor[i].color);
    }

    for (unsigned i = 0; i < n; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;

        if (!edgeExists(src, dest))
        {
            Node* newNode = new Node(dest, verticesColor[dest].color);
            newNode->next = nullptr;

            if (head[src] == nullptr) {
                head[src] = newNode;
            } else {
                Node* current = head[src];
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }

            degrees[src]++;
        }
    }
}

int Graph::getSize(){
    return this->N;
}

bool Graph::edgeExists(int src, int dest)
{
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
        cout <<  ptr->val << " ";
        ptr = ptr->next;
    }
}

void Graph::printNeighboringVertices(int vertex) {
    if (vertex >= 0 && vertex < N) {
        Node* current = head[vertex];

        if (current == nullptr) {
            cout << "No neighboring vertices for node " << vertex << endl;
        } else {
            cout << "Neighboring vertices of node " << vertex << ": ";
            while (current != nullptr) {
                cout << current->next->val << " ";
                current = current->next;
            }
            cout << endl;
        }
    } else {
        cout << "Inneighborsid node index: " << vertex << endl;
    }
}




