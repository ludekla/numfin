#ifndef _LATTICE_HPP_
#define _LATTICE_HPP_

#include <vector>
#include <iostream>
#include <iomanip>

template <typename T>
using Prices = std::vector<T>;

template <typename T>
class Lattice {
private:
    int size;
    std::vector<Prices<T>> values;
public:
    Lattice(int n) {
        values.resize(n + 1);
        for (int i = 0; i <= n; i++) values[i].resize(i + 1);
    }
    void set(int n, int i, T val) { values[n][i] = val; }
    T get(int n, int i) const { return values[n][i]; }
    void display(std::string message) {
        std::cout << std::endl;
        std::cout << message << std::endl;
        std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3);
        for (auto row : values) {
            for (double val : row) std::cout << std::setw(10) << val;
            std::cout << std::endl;
        }
    }
};

#endif /*  _LATTICE_HPP_ */