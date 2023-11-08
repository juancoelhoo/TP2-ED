#include "../include/Graph.hpp"
#include "../include/Sort.hpp"

Node* Graph::getAdjListNode(int dest, Node* head)
{
        Node* newNode = new Node(-1, -1);
        newNode->val = dest;  // Set the value of the new node
        newNode->next = head;  // Set the next pointer to the current head

    return newNode;
}

Graph::Graph(Edge edges[], unsigned int n, int N, Node* verticesColor)
{
    this->head = new Node*[N]();
    this->degrees = new int[N]();
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
    unsigned int graphSize = this->N;
    return graphSize;
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

void Graph::printGraph()
{
    for (int i = 0; i < this->N; i++) {
        cout << (this->head[i]->val) << " ";
    }
}

void Graph::sortVertices(char method)
{
    sortMethodSelection(method, this->head, this->N);
}

bool Graph::greedyAlgorithm_check()
{
    for (int i = 0; i < this->N; i++) {
        Node* currentVertex = this->head[i];
        int vertex_color = currentVertex->color;
        if (vertex_color == 1) {
            continue;
        }

        Node* neighbourVertex = currentVertex->next;

        bool verification[vertex_color - 1] = {false};

        int j = 0;

        for (auto it = neighbourVertex; it != nullptr; it = it->next) {
            if (it->color < vertex_color) {
                int index = it->color - 1;
                if (index >= 0 && index < vertex_color - 1) {
                    verification[index] = true;
                }
            }
            j++;
        }

        for (int i = 0; i < vertex_color - 1; i++) {
            if (!verification[i]) {
                return false;
            }
        }
    }

    return true;
}


Graph graphBuilding(int verticesNumber)
{
    const int vertices = verticesNumber;
    // Builds the edges
    Edge edges [verticesNumber * 1000];
    edges->edgeAssign(edges, verticesNumber);

    // Assigns the color of all vertices
    Node verticesColor[vertices];
    
    verticesColor->verticesColoring(verticesColor, vertices);

    // Builds the graph and colour its vertices
    Graph graph(edges, edges[0].edgeCount, vertices, verticesColor);

    return graph;
}


