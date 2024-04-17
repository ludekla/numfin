#ifndef _LATTICE_HPP_
#define _LATTICE_HPP_

#include <vector>

using Prices = std::vector<double>;

class Lattice {
private:
    int size;
    std::vector<Prices> values;
public:
    Lattice(int n); 
    void set(int n, int i, double val) { values[n][i] = val; }
    double get(int n, int i) const { return values[n][i]; }
    void display();
};

#endif /*  _LATTICE_HPP_ */