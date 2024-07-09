#include "Stack.h"
#include <iostream>

int main() {
    Stack<std::string> st;

    st.push("I am looking for an internship opportunity to demonstrate my abilities");
    st.push("University of Information Technology - UIT");
    st.push("Phan Thanh Dang");
    
    while (!st.isEmpty()) {
        std::cout << st.top() << '\n';
        st.pop();
    }

    return 0;
}
