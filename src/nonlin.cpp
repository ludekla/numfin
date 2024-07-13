#include <iostream>

#include "nonlin.hpp"

using namespace std;

double square_fn(double x, double a) {
    return x*x - a;
}

double square_dfn(double x) {
    return 2.0*x;
}

double bisection(Func fn, double target, double left, double right, double eps) {
    double l = left, r = right;
    double m = (l + r) / 2;
    double lval = fn(l, target);
    double mval = fn(m, target);

    int c = 0;

    while (r - l > eps) {
        if ((lval > 0 && mval < 0) || (lval < 0 && mval > 0)) r = m;
        else l = m;
        m = (l + r) / 2;
        lval = fn(l, target);
        mval = fn(m, target);
        c++;
    }

    cout << "Bisection Count: " << c << endl;

    return m;
}

double newton_raphson(Func fn, DFunc dfn, double target, double l, double r, double eps) {
    double guess = (l + r) / 2.0;
    double value = fn(guess, target);
    int count = 0;

    while (value > eps) {
        guess -= value / dfn(guess);
        value = fn(guess, target);
        count++;
    }

    cout << "Newton-Raphson Loop Count: " << count << endl;

    return guess;
}

double absval(double val) {
    return (val > 0) ? val : -val;
}

double square_root(double value, double eps) {
    double guess = value / 2.0;
    double delta = absval(guess * guess - value);
    int count = 0;

    while (delta > eps) {
        guess = (guess + value / guess) / 2.0;
        delta = absval(guess * guess - value);
        count++;
    }

    cout << "Square Root Loop Count: " << count << endl;

    return guess;
}

double SquareRoot::value(double x) {
    return x*x - val;
}

double SquareRoot::deriv(double x) {
    return 2*x;
}

double bisection(Function * fn, double left, double right, double eps) {
    double l = left, r = right;
    double m = (l + r) / 2;
    double lval = fn->value(l);
    double mval = fn->value(m);

    int c = 0;

    while (r - l > eps) {
        if ((lval > 0 && mval < 0) || (lval < 0 && mval > 0)) r = m;
        else l = m;
        m = (l + r) / 2;
        lval = fn->value(l);
        mval = fn->value(m);
        c++;
    }

    cout << "Bisection Count: " << c << endl;

    return m;
}

double newton_raphson(Function * fn, double l, double r, double eps) {
    double guess = (l + r) / 2.0;
    double value = fn->value(guess);
    int count = 0;

    while (value > eps) {
        guess -= value / fn->deriv(guess);
        value = fn->value(guess);
        count++;
    }

    cout << "Newton-Raphson Loop Count: " << count << endl;

    return guess;
}