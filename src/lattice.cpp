#include "lattice.hpp"

#include <iostream>
#include <iomanip>

Lattice::Lattice(int n) {
    values.resize(n + 1);
    for (int i = 0; i <= n; i++) values[i].resize(i + 1);
}

void Lattice::display() {
    std::cout << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3);
    for (auto row : values) {
        for (double val : row) std::cout << std::setw(10) << val;
        std::cout << std::endl;
    }
}