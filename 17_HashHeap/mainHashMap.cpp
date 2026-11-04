// Create a hash table
// Insert 5 records

// print the content

#include "HashMap.hpp"
#include <string>

/*
int main(void) {
    HashMap<std::string> map;

    map.insert(2134123, "burger king");
    map.insert(1233455, "mc'donalds");
    map.insert(9834234, "wendys");
    map.insert(3243252, "papa jones");
    map.insert(21, "chipotle");
    map.insert(83, "foxtail coffee");

    std::cout   << map.search(83)[0]
                << map.search(83)[2]
                << map.search(2134123)[0]
                << map.search(9834234)[3]
                << map.search(2134123)[0]
                << std::endl;

    return 0;
}
*/

int main(void) {
    HashMap<std::string> map(7);

    map.insert(8, "a");
    map.insert(15, "b");
    map.insert(22, "c");

    map.print();
    std::cout << "---------------\n";
    map.remove(15);
    map.print();

    std::cout << "---------------\n";
    map.insert(15, "abc");
    map.print();

    return 0;
    
}