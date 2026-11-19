#include "Graph.hpp"
#include <string>

/*
int main(void) {
    Graph<std::string> friends;

    friends.insertVertex("Ross");
    friends.insertVertex("Monica");
    friends.insertVertex("Rachel");
    friends.insertVertex("Chandler");
    friends.insertVertex("Joey");
    friends.insertVertex("Pheobe");

    //Create friendship
    friends.insertEdge("Ross", "Monica");
    friends.insertEdge("Rachel", "Joey");
    friends.insertEdge("Pheobe", "Rachel");
    friends.insertEdge("Monica", "Joey");
    friends.insertEdge("Joey", "Rachel");

    friends.print();
    friends.BFS("Monica");
    friends.DFS("Monica");

    std::cout << "isConnected: " << friends.isConnected() << std::endl;

    friends.insertEdge ("Rachel", "Chandler");
    std::cout << "isConnected: " << friends.isConnected() << std::endl;

    friends.BFS("Monica");
    friends.DFS("Monica");

    std::cout << "Ross to Chandler " << friends.shortestPath("Ross", "Chandler") << std::endl;

    //std::cout << friends.getDegree("Monica") << std::endl;

    return 0;
}
#include <iostream>
#include <string>
#include "Graph.hpp"
int main() {
    Graph<char> secret;
    // Vertices and edges are intentionally not in code order.
    for (char symbol : std::string("YAG@KU#ZCRBDT")) {
    secret.insertVertex(symbol);
    }
        secret.insertEdge('R', '@');
        secret.insertEdge('#', 'Y');
        secret.insertEdge('U', 'A');
        secret.insertEdge('Z', 'C');
        secret.insertEdge('G', '@');
        secret.insertEdge('Y', 'D');
        secret.insertEdge('#', 'R');
        secret.insertEdge('Z', 'A');
        secret.insertEdge('G', 'B');
        secret.insertEdge('U', '#');
        secret.insertEdge('Y', 'A');
        secret.insertEdge('Z', '#');
        secret.insertEdge('G', '#');
        secret.insertEdge('Y', 'B');
        secret.insertEdge('@', 'U');
        secret.insertEdge('Z', 'B');
        secret.insertEdge('Y', 'C');
        secret.insertEdge('G', 'A');
        secret.insertEdge('Y', '@');
        secret.insertEdge('@', 'Z');
        secret.insertEdge('#', 'K');
        secret.insertEdge('@', 'T');
    // Arrange the printed letters by INCREASING degree.
    std::cout << "\nCandidate letters and their degrees:\n";
    for (char c = 'A'; c <= 'Z'; ++c) {
    if (secret.hasEdge('@', c) && secret.hasEdge('#', c)) {
    std::cout << c << ": " << secret.getDegree(c) << '\n';
    }
    }
    return 0;
} */

int main(void) {
    Graph<std::string> cities;

    cities.insertVertex("Lakeland");
    cities.insertVertex("Orlando");
    cities.insertVertex("Tampa");
    cities.insertVertex("Miami");
    cities.insertVertex("Naples");
    cities.insertVertex("KeyWest");

    cities.insertEdge("Lakeland", "Orlando", 50);
    cities.insertEdge("Lakeland", "Miami", 350);
    cities.insertEdge("Lakeland", "Tampa", 40);
    cities.insertEdge("Orlando", "Miami", 200);
    cities.insertEdge("Naples", "Miami", 150);
    cities.insertEdge("Tampa", "Miami", 500);
    cities.insertEdge("Tampa", "Naples", 185);

    // Check connectivity and unreachable paths
    bool disconnected = !cities.isConnected() &&
        cities.shortestPathByEdges("Lakeland", "KeyWest") == -1;

    cities.insertEdge("Naples", "KeyWest", 170);

    bool connected = cities.isConnected();

    if (!disconnected || !connected) {
        std::cout << "Check your graph implementation.\n";
        return 0;
    }
    // Generate the attendance code
    std::string code;

    code += static_cast<char>('0' + cities.getDegree("Miami"));

    code += static_cast<char>(
        '0' + cities.shortestPathByEdges("Lakeland", "KeyWest")
            + cities.shortestPathByEdges("Lakeland", "Naples")
    );

    code += static_cast<char>(
        'A' + cities.getDegree("Tampa")
            + cities.shortestPathByEdges("Orlando", "Naples")
    );

    code += static_cast<char>(
        'A' + cities.getDegree("Miami")
            + cities.shortestPathByEdges("Lakeland", "Naples")
    );

    code += static_cast<char>(
        '0' + cities.shortestPathByEdges("Lakeland", "KeyWest")
            + connected
    );
    
    std::cout << "Attendance code: " << code << '\n';
    
    return 0;

}