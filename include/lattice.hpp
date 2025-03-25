/**
 * @file lattice.hpp
 * @brief Lattice for holding simulated values.
 * 
 * @author Lutz
*/

#ifndef _LATTICE_HPP_
#define _LATTICE_HPP_

#include <vector>
#include <iostream>
#include <iomanip>

template <typename T>
using Prices = std::vector<T>;

/**
 * @class Lattice
 * @brief Template class for holding simulated price data.
 * 
 * Prices may also be integers or floats, whatever works with
 * this template.
*/
template <typename T>
class Lattice {
private:
    std::vector<Prices<T>> values;  /* !< Container for holding prices. */
public:
    /**
     * Constructor
     * @param n Size parameter for the triangular lattice.
    */
    Lattice(int n) {
        values.resize(n + 1);
        for (int i = 0; i <= n; i++) values[i].resize(i + 1);
    }
    /**
     * @fn set
     * @brief Setter method to set a value at a grid point.
     * 
     * @param n Row parameter
     * @param i Column parameter
     * @param val Value to be set
    */
    void set(int n, int i, T val) { values[n][i] = val; }
    /**
     * @fn get
     * @brief Getter method to read a grid value.
     * 
     * @param n Row parameter
     * @param i Column parameter
     * 
     * @return Value at the grid point as double.
    */
    T get(int n, int i) const { return values[n][i]; }
    /**
     * @fn display
     * @brief Method to display the lattice.
     * 
     * @param message Message to be displayed on top.
    */
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