#include <iostream>

void recursiveFunction(int n) {
    std::cout << "Depth: " << n << std::endl;
    recursiveFunction(n + 1);
}

int main() {
    recursiveFunction(0);
    return 0;
}
