#include <iostream>

#include "nonlin.hpp"

using namespace std;

int main(int args, char * argv[]) {
    cout << "Hello Square Root." << endl;

    if (args != 2) {
        cout << "Usage: bin/root [NUMBER]\nNUMBER: 0, 1 or 2" << endl;
        return 1;
    }

    double result;
    double prec = 1e-8;
    int method = atoi(argv[1]);

    switch (method) {
    case 0:
        result = bisection(square_fn, 2, 1.0, 2.0, prec);
        cout << "Square root of 2 (bisection): ";
        break;
    case 1:
        result = newton_raphson(square_fn, square_dfn, 2, 1.0, 2.0, prec);
        cout << "Square root of 2 (Newton-Raphson): ";
        break;
    default:
        result = square_root(2.0, prec);
        cout << "Square root of 2 (by iteration): ";
    }
    
    cout << result << endl;

    return 0;
}