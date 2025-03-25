/**
 * @file nonlin.hpp
 * @brief Collection of classes and functions for nonlinear methods.
 * 
 * @author Lutz
*/
#ifndef __NONLIN_HPP__
#define __NONLIN_HPP__ 

#include <vector>
#include <cmath>
#include <iostream>

typedef double (*Func)(double, double);
typedef double (*DFunc)(double);

double square_fn(double x, double a);

double square_dfn(double x);

double bisection(Func fn, double target, double left, double right, double eps);

double newton_raphson(Func fn, DFunc dfn, double target, double l, double r, double eps);

double absval(double val);

double square_root(double value, double eps);

/**
 * @class Function
 * @brief Abstract class for implicit solutions.
*/
class Function {
public:
    virtual double value(double x) = 0;
    virtual double deriv(double x) = 0;
};

/**
 * @class SquareRoot
 * @brief Class for computing square roots.
 * 
 * This class implements the two methods for
 * computing the square root of a number.
*/
class SquareRoot : public Function {
private:
    double val;  /*!< Value whose square root is of interest. */
public:
    /**
     * Constructor
     * @param a Value the private member takes.
    */
    SquareRoot(double a) { val = a; }
    /**
     * @fn value
     * @brief 
     * 
     * @param x 
    */
    virtual double value(double x);
    /**
     * @fn value
     * @brief 
     * 
     * @param x 
    */
    virtual double deriv(double x);
};

class SqrRoot {
private:
    double val;
public:
    SqrRoot(double a) { val = a; }
    double value(double x) { return x*x - val; }
    double deriv(double x) { return 2*x; }
};

double bisection(Function * fn, double left, double right, double eps);

double newton_raphson(Function * fn, double l, double r, double eps);

struct Coupon {
    double time;
    double amount;
};

using PayVec = std::vector<Coupon>;

class Bond {
private:
    PayVec coupons;
    double principal;
    double mvalue;
public:
    Bond(PayVec payvec, double princ): coupons(payvec), principal(princ), mvalue(0.0) {}
    double evaluate(double yield) const;
    double value(double yield) const;
    double deriv(double yield) const;
    double newtonraph_yield(double value, double eps);
    double bisection_yield(double value, double eps);
};

template <typename F>
double newton_raphson_t(F& fn, double l, double r, double eps) {
    double guess = (l + r) / 2.0;
    double value = fn.value(guess);
    int count = 0;

    while (absval(value) > eps) {
        guess -= value / fn.deriv(guess);
        value = fn.value(guess);
        count++;
    }

    std::cout << "Newton-Raphson Loop Template Count: " << count << std::endl;

    return guess;
}

template <typename F>
double bisection_t(F& fn, double left, double right, double eps) {
    double l = left, r = right;
    double m = (l + r) / 2;
    double lval = fn.value(l);
    double mval = fn.value(m);

    int c = 0;

    while (r - l > eps) {
        if ((lval > 0 && mval < 0) || (lval < 0 && mval > 0)) r = m;
        else l = m;
        m = (l + r) / 2;
        lval = fn.value(l);
        mval = fn.value(m);
        c++;
    }

    std::cout << "Bisection Template Function Count: " << c << std::endl;

    return m;
}

#endif // _NONLIN_HPP__