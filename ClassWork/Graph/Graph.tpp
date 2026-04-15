#include <iostream>

// Vertex ostream
template <typename K, typename E>
std::ostream& operator<<(std::ostream& out, Vertex<K, E>& v) {
    out << v.key << std::endl;
    return out;
}

// Edge ostream
template <typename K, typename E>
std::ostream& operator<<(std::ostream& out, Edge<K, E>& e) {
    out << "(" << *(e.src) << ", " << *(e.dst) << ", " << *(e.data) << ")" << std::endl;
    return out;
}

template <typename K, typename E>
Graph<K, E>::Graph() { 
}

// Add vertex
template <typename K, typename E>
bool Graph<K, E>::add(K key) {
    if (find(key)) {
        return false;
    }

    Vertex<K, E>* newVertex = new Vertex<K, E>(key);
    verticies.push_back(*newVertex);
    return true;
}