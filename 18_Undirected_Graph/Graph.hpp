#ifndef GRAPH_HPP
#define GRAPH_HPP

template <typename T>
class Graph {
public:
    void insertVertex(const T& v);
    void insertEdge(const T& v1, const T& v2);

    void print() const; //Prints vertices and adjacency list a : b, c ; b : c; c : ;
private:
    std::vector<T> vertices;
    std::vector<std::vector<int>> adjacency_list;

    int searchVertexIndex(const T& value) const;
};

#endif