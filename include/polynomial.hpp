#ifndef __POLYNOMIAL_HPP__
#define __POLYNOMIAL_HPP__

#include <vector>
#include <cmath>

using Vec = std::vector<double>;

class Polynomial {
private:
    Vec coeffs;
public:
    Polynomial(Vec coefs): coeffs(coefs) {}
    double evaluate(double x);
};

double Polynomial::evaluate(double x) {
    size_t size = coeffs.size();
    double sum = coeffs.at(size - 1);
    for (size_t i = size - 1; i > 0; i--) {
        sum *= x;
        sum += coeffs.at(i-1);    
    }
    return sum;
}

double N(double x) {
    Vec coeffs {0.0, 0.31938153, -0.356563782, 1.781477937, -1.821255978, 1.330274429};
    Polynomial p(coeffs);
    double pi = 4.0 * atan(1.0);
    double gamma = 0.2316419;
    double k = 1.0 / (1.0 + gamma * x);

    if (x >= 0.0) {
        return 1.0 - p.evaluate(k) * exp(-0.5*x*x) / sqrt(2.0*pi);
    } else {
        return 1.0 - N(-x);
    }
}

#endif /* __POLYNOMIAL_HPP__ */