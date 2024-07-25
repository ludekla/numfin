#include <iostream>

#include "nonlin.hpp"

using namespace std;

int main(int args, char * argv[]) {
    cout << "Hello Square Root." << endl;

    if (args != 2) {
        cout << "Usage: bin/root [NUMBER]\nNUMBER: 0-6" << endl;
        return 1;
    }

    double result;
    double prec = 1e-8;
    int method = atoi(argv[1]);

    SquareRoot sq_fn(2.0);
    SqrRoot sf(2.0);
    
    switch (method) {
    case 0:
        result = bisection(square_fn, 2, 1.0, 2.0, prec);
        cout << "Square root of 2 (Bisection): ";
        break;
    case 1:
        result = newton_raphson(square_fn, square_dfn, 2, 1.0, 2.0, prec);
        cout << "Square root of 2 (Newton-Raphson): ";
        break;
    case 2:
        result = bisection(&sq_fn, 1.0, 2.0, prec);
        cout << "Square root of 2 (Bisection OOP): ";
        break;
    case 3:
        result = newton_raphson(&sq_fn, 1.0, 2.0, prec);
        cout << "Square root of 2 (Newton-Raphson OOP): ";
        break;
    case 4:
        result = bisection_t(sf, 1.0, 2.0, prec);
        cout << "Square root of 2 (Bisection OOP Template): ";
        break;
    case 5:
        result = newton_raphson_t(sf, 1.0, 2.0, prec);
        cout << "Square root of 2 (Newton-Raphson OOP Template): ";
        break;
    default:
        result = square_root(2.0, prec);
        cout << "Square root of 2 (by iteration): ";
    }
    
    cout << result << endl;

    return 0;
}