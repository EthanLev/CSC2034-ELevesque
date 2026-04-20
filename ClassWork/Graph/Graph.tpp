#include <iostream>

// Vertex ostream
template <typename K, typename E>
std::ostream& operator<<(std::ostream& out, Vertex<K, E>& v) {
    out << v.key;
    return out;
}

// Edge ostream
template <typename K, typename E>
std::ostream& operator<<(std::ostream& out, Edge<K, E>& e) {
    out << "(" << *(e.src) << ", " << *(e.dst) << ", " << e.data << ")";
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

// Add edge
template <typename K, typename E>
bool Graph<K, E>::add(K src, K dst, E edgeData) {
    if (find(src, dst, edgeData)) {
        return false;
    }

    Edge<K, E>* newEdge = new Edge<K, E>(find(src), find(dst), edgeData);

    auto neighbors = newEdge->getSource()->getNeighbors();

    neighbors->push_back(*newEdge);

    return true;
}

// Find vertex
template <typename K, typename E>
Vertex<K, E>* Graph<K, E>::find(K key) {
    Vertex<K, E> vert(key);
    auto it = std::find(verticies.begin(), verticies.end(), vert);

    if (it != verticies.end()) {
        // int vIndex = std::distance(verticies.begin(), it);
        return &(*it);
    }

    return nullptr;
}

// Find edge
template <typename K, typename E>
Edge<K, E>* Graph<K, E>::find(K src, K dst, E data) {
    Vertex<K, E>* srcV = find(src);
    Vertex<K, E>* dstV = find(dst);

    if (!srcV || !dstV) {
        return nullptr; // both verticies must be in edge
    }

    Edge<K, E> edge{srcV, dstV, data};
    auto it = std::find(srcV->getNeighbors()->begin(), srcV->getNeighbors()->end(), edge);

    if (it != srcV->getNeighbors()->end()) {
        // int eIndex = std::distance(srcV->getNeighbors()->begin(), it);
        return &(*it);
    }

    return nullptr;
}


// Overload equals operator Vertex
template <typename K, typename E>
bool Vertex<K, E>::operator==(const Vertex<K, E>& other) {
    if (key == other.key) {
        return true;
    }

    return false;
}

// Overload equal operator Edge
template <typename K, typename E>
bool Edge<K, E>::operator==(const Edge<K, E>& other) {
    if (src == other.src && dst == other.dst) {
        return true;
    }

    return false;
}

template <typename K, typename E>
void Graph<K, E>::print() {
    for (int i = 0; i < verticies.size(); i++) {
        Vertex<K, E> current =verticies.at(i);
        std::cout << current;
        std::vector<Edge<K, E>>* neighbors = current.getNeighbors();

        for (Edge<K, E>& edge : *neighbors) {
            std::cout << edge;
        }

        std::cout << std::endl;
    }
}
