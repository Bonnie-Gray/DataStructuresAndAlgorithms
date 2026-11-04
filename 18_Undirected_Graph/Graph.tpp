#include "Graph.hpp"

template <typename T>
int Graph<T>::searchVertexIndex(const T& value) const {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i] == value) {
            return i;
        }
    }
    return -1; 
}

template <typename T>
void Graph<T>::insertVertex(const T& v) {
    //Check for duplicates
    if (searchVertexIndex(v) != -1) {
        std::cout << "InsertVertex: Vertex alread exists" << std::endl;
        return;
    }

    vertices.push_back(v);
    std::vector<int> temp;
    adjacency_list.push_back(temp); // creates empty list of neightours for the vertex
}

template <typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2) {
    // search if vertices exist
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);
    
    if (i_v1 == -1 || i_v2 == -1){
        std::cout << "insertEdge: incorrect vertices" << std::cout;
    }

    //Insert in the adjacency list  
    
}