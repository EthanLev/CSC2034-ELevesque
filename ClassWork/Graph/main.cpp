#include <iostream>
#include "Graph.h"

int main(int, char**){
    Graph<int, int> graph;

    graph.add(0);
    graph.add(1);
    graph.add(2);
    graph.add(3);
    graph.add(4);
    graph.add(5);

    int edges[18][3] = {
        {0, 1, 5}, {0, 2, 6},
        {1, 0, 5}, {1, 2, 2}, { 1, 5, 3},
        {2 ,0, 6}, {2, 1, 2}, {2, 5, 4}, {2, 3, 10},
        {3, 2, 10}, {3, 5, 9}, {3, 4, 7},
        {4, 3, 7}, {4, 5, 8},
        {5, 1, 3}, {5, 2, 4}, {5, 3, 9}, {5, 4, 8}
    };

    for (auto& edge : edges) {
        if (edge != nullptr) {
            graph.add(edge[0], edge[1], edge[2]);
        }
    }

    graph.print();
}
