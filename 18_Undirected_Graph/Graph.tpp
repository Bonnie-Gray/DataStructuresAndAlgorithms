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
    //Add new vertex
    vertices.push_back(v);
    std::vector<Edge> temp;
    adjacency_list.push_back(temp); // creates empty list of neightours for the vertex
}

template <typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2, int weight) {
    //Ignore negative weights
    if (weight < 0) {
        std::cout << "insertEdge: negative weights\n";
        return;
    }

    // search if vertices exist
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);
    
    if (i_v1 == -1 || i_v2 == -1){
        std::cout << "insertEdge: incorrect vertices" << std::endl;
        return;
    }

    //Avoid duplicate edges
    for (const Edge& edge : adjacency_list[i_v1]) {
        if (edge.neighbor == i_v2) {
            return;
        }
    }

    //Insert in the adjacency list  
    adjacency_list[i_v1].push_back(Edge(i_v2, weight));
    adjacency_list[i_v2].push_back(Edge(i_v1, weight));
}

template <typename T>
void Graph<T>::print() const {
    //Print the vertices
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i] << ": ";
        // Print all the neighbors
        for (const Edge& edge : adjacency_list[i]) {
            std::cout << vertices[edge.neighbor] << "(";
            std::cout << edge.weight << ") ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
int Graph<T>::getDegree(const T& vertex) const {
    // Find the vertex (return -1 if not found)
    int index = searchVertexIndex(vertex);
    if (index == -1) {
        return -1;
    } 
    // return the adjaceny_list size   
    return static_cast<int>(adjacency_list[index].size());
}

template <typename T>
bool Graph<T>::hasEdge(const T& v1, const T& v2) const {
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);

    if(i_v1 == -1 || i_v2 == -1) {
        return false;
    }

    for (const Edge& edge : adjacency_list[i_v1]) {
        if (edge.neighbor == i_v2) {
            return true;
        }
    }
    // Find indicies of both vertices ( return false if not found)
    // search adjacency_list for first (second) index
    return false;
}

template <typename T>
int Graph<T>::getEdgeWeight(const T& v1, const T& v2) const {
    if (!hasEdge(v1,v2)) {
        return -1;
    }

    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);

    for(const Edge& edge : adjacency_list[i_v1]) {
        if (edge.neighbor == i_v2) {
            return edge.weight;
        }
    }
    return -1;
}

template <typename T>
void Graph<T>::BFS(const T& start) const {
    int start_index = searchVertexIndex(start);

    if (start_index == -1) {
        std::cout << "BFS: incorrect start vertex\n";
        return;
    }
    std::cout << "BFS: ";
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
        for (const Edge& edge : adjacency_list[current_index]) {
            if (!discovered[edge.neighbor]) {
                discovered[edge.neighbor] = true;
                q.push(edge.neighbor);
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
        return;
    }

    std::cout << "DFS: ";
    std::vector<bool> visited(vertices.size(), false);
    DFSExplore(start_index, visited);
    std::cout << std::endl;
}

template <typename T>
void Graph<T>::DFSExplore(int index, std::vector<bool>& visited, bool print) const {
    // Mark current index as visited
    visited[index] = true;

    if(print) {
    std::cout << vertices[index] << " ";
    }

    //Go through neighbors
    // If not visited call DFSExplore for that vertex
    for (const Edge& edge : adjacency_list[index]) {
        if (!visited[edge.neighbor]) {
            DFSExplore(edge.neighbor, visited, print);
        }
    }
}

template <typename T>
bool Graph<T>::isConnected() const {
    //Empty graph
    if (vertices.empty()) {
        return true;
    }

    std::vector<bool> visited(vertices.size(), false);

    // Perform DSF
    DFSExplore(0, visited, false);

    for (bool v : visited) {
        if(!v) {
            return false;
        }
    }
    return true;
}

template <typename T>
int Graph<T>::shortestPathByEdges(const T& start, const T& end) const {
    int start_index = searchVertexIndex(start);
    int end_index = searchVertexIndex(end);

    if (start_index == -1 || end_index == -1) {
        std::cout << "shortestPathByEdges: incorrect vertices\n";
        return -1;
    }

    if(start == end) {
        return 0;
    }
    //Create a queue and the vector of discovered vertices
    std::queue<int> q;
    std::vector<int> distances(vertices.size(), -1);

    // Add the start vertex into the queue
    q.push(start_index);
    // Mark start index discovered
    distances[start_index] = 0;

    while (!q.empty()) {
        //get the front value from the queue
        int current_index = q.front();
        q.pop();

        //discover neighbors and add not discovered in the queue
        for (const Edge& edge : adjacency_list[current_index]) {
            if (distances[edge.neighbor] == -1) {
                distances[edge.neighbor] = distances[current_index] + 1;
                q.push(edge.neighbor);

                if (edge.neighbor == end_index) {
                    return distances[edge.neighbor];
                }
            }
        }
    }

    return -1;
}