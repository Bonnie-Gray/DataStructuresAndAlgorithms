#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

template <typename T>
class Graph {
public:
    void insertVertex(const T& v);
    void insertEdge(const T& v1, const T& v2);
    int getDegree(const T& vertex) const;
    bool hasEdge(const T& v1, const T& v2) const;
    bool isConnected() const;

    void print() const; //Prints vertices and adjacency list a : b, c ; b : c; c : ;

    void BFS(const T& start) const;
    void DFS(const T& start) const;

    int shortestPath(const T& start, const T& end) const;

private:
    std::vector<T> vertices;
    std::vector<std::vector<int>> adjacency_list;

    int searchVertexIndex(const T& value) const;
    void DFSExplore(int index, std::vector<bool>& visited, bool print) const;
};

#include "Graph.tpp"

#endif