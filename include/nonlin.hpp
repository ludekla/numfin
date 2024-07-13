#ifndef __NONLIN_HPP__
#define __NONLIN_HPP__ 

typedef double (*Func)(double, double);
typedef double (*DFunc)(double);

double square_fn(double x, double a);

double square_dfn(double x);

double bisection(Func fn, double target, double left, double right, double eps);

double newton_raphson(Func fn, DFunc dfn, double target, double l, double r, double eps);

double absval(double val);

double square_root(double value, double eps);

class Function {
public:
    virtual double value(double x) = 0;
    virtual double deriv(double x) = 0;
};

class SquareRoot : public Function {
private:
    double val;
public:
    SquareRoot(double a) { val = a; }
    virtual double value(double x);
    virtual double deriv(double x);
};

double bisection(Function * fn, double left, double right, double eps);

double newton_raphson(Function * fn, double l, double r, double eps);


#endif // _NONLIN_HPP__