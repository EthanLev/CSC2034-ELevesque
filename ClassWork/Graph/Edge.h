#pragma once
#include <vector>

template <typename K, typename E>
class Vertex;

template <typename K, typename E>
class Edge {
    E data;
    Vertex<K, E>* src; // source vertex
    Vertex<K, E>* dst; // destination vertex

public:
    Edge(Vertex<K, E>* source, Vertex<K, E>* destination, E data)
        : src(source)
        , dst(destination)
        , data(data)
    {

    }
    
    Vertex<K, E>* getSource() { return src; }
    Vertex<K, E>* getDestination() { return dst; }
    E& getData() { return data; } // return reference because it will be on the heap

    bool operator==(const Edge<K, E>& other);

    template <typename U, typename V>
    friend std::ostream& operator<<(std::ostream& out, Edge<U, V>& e);
};