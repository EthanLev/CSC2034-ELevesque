#pragma once
#include <vector>
#include <algorithm>
#include "Vertex.h"
#include "Edge.h"

template <typename K, typename E> // K = vertex object
                                  // E = edge object

class Graph  {
    std::vector<Vertex<K, E>> verticies;

public:
    Graph();

    bool add(K key);
    bool add(K src, K dst, E edgeData);

    Vertex<K, E>* find(K key);
    Edge<K, E>* find(K src, K dst, E data);

    void print();
};

#include "Graph.tpp"