#include "Graph.hpp"
#include <iostream>
#include <queue>

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
        std::cout << "insertEdge: incorrect vertices" << std::endl;
    }

    for (int neighbor : adjacency_list[i_v1]) {
        if (neighbor == i_v2) {
            return;
        }
    }

    //Insert in the adjacency list  
    adjacency_list[i_v1].push_back(i_v2);
    adjacency_list[i_v2].push_back(i_v1);
}

template <typename T>
void Graph<T>::print() const {
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i] << ": ";
        for (int j : adjacency_list[i]) {
            std::cout << vertices[j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
int Graph<T>::getDegree(const T& vertex) const {
    // Find the vertex (return -1 if not found)
    int i_v = searchVertexIndex(vertex);
    if (!i_v) {
        return -1;
    } 
    else {
    // return the adjaceny_list size   
    return adjacency_list[i_v].size();
    }
    
}

template <typename T>
bool Graph<T>::hasEdge(const T& v1, const T& v2) const {
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);
    for (int neighbor : adjacency_list[i_v1]) {
        if (neighbor == i_v2) {
            return true;
        }
    }
    // Find indicies of both vertices ( return false if not found)
    // search adjacency_list for first (second) index
    return false;
}

template <typename T>
void Graph<T>::BFS(const T& start) const {
    int start_index = searchVertexIndex(start);

    if (start_index == -1) {
        std::cout << "BFS: incorrect start vertex\n";
    }
    std::cout << "BSF: ";
    //Create a queue and the vector of discovered vertices
    std::queue<int> q;
    std::vector<bool> discovered(vertices.size(), false);

    // Add the start vertex into the queue
    q.push(start_index);
    // Mark start index discovered
    discovered[start_index] = true;

    while (!q.empty()) {
        //get the front value from the queue
        int current_index = q.front();
        q.pop();

        std::cout << vertices[current_index] << " ";

        //discover neighbors and add not discovered in the queue
        for (int neighbor : adjacency_list[current_index]) {
            if (!discovered[neighbor]) {
                discovered[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << std::endl;
}

template <typename T>
void Graph<T>::DFS(const T& start) const {
    int start_index = searchVertexIndex(start);

    if (start_index == -1) {
        std::cout << "DFS: incorrect start vertex\n";
    }

    std::vector<bool> visited(vertices.size(), false);
    DSFExplore(index, visited);
}

template <typename T>
void Graph<T>::DFSExplore(int index, std::vector<bool>& visited) const {
    // Mark current index as visited
    visited[index] = true;
    std::cout << vertices[index] << " ";

    //Go through neighbors
    // If not visited call DFSExplore for that vertex

}