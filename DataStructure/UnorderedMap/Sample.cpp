#include "UnorderedMap.h"
#include <iostream>

int main() {
    UnorderedMap<std::string, int> mp;
    mp.insert("apple", 5);
    mp.insert("banana", 10);
    mp.insert("cherry", 15);

    // Iterating through the unordered_map-like structure
    for (auto it = mp.begin(); it != mp.end(); ++it) 
        std::cout << (*it).first << " -> " << (*it).second << '\n';
    
    mp["asdsa"] = 1;
    mp["asd"] = 2;
    mp["asdw"] = 4;
    mp["asdasd"] = 10;
    
    for (auto& entry : mp) {
        std::cout << entry.first << ' ' << entry.second << '\n';
    }

    return 0;
}