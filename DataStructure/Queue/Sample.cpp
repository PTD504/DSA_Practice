#include "Queue.h"
#include <iostream>

int main() {
    Queue<std::string> q;

    q.push("Phan Thanh Dang");
    q.push("University of Information Technology - UIT");
    q.push("I am looking for an internship opportunity to demonstrate my abilities");
    std::cout << q.size() << '\n';
    
    while (!q.isEmpty()) {
        std::cout << q.front() << '\n';
        q.pop(); 
    }


    return 0;
}
