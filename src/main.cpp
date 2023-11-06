#include <iostream>
#include "../include/Graph.hpp"
#include "../include/GreedyAlgorithm.hpp"
#include "../include/Sort.hpp"



int main()
{   
    char method;
    int verticesNumber;

    cin >> method;
    cin >> verticesNumber;

    Graph graph = graphBuilding(verticesNumber);
    
    sortMethodSelection(method, graph.head, graph.getSize());

    bool result = greedyAlgorithm_check(graph.head, graph.getSize());

    if (result == 0) cout << result;
    else
    {    
        cout << result << " ";
        graph.printGraph();
    }
    cout << endl;

    return 0;
}