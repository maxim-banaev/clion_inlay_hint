#include <iostream>

#include <functional>
#include <iostream>

int add(int x, int y) { return x + y; }

void bind_to_lambda(int num) {
    int x = 2;
    auto clj = std::bind(add, x, num);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
