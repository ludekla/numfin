#include "eurocall.hpp"
#include "polynomial.hpp"
#include "nonlin.hpp"

#include <cmath>

double EuroCall::d_plus(double spot, double sig, double rate) {
    return (log(spot/K) + (rate + 0.5*sig*sig)*T) / (sig*sqrt(T));
}

double EuroCall::d_minus(double spot, double sig, double rate) {
    return d_plus(spot, sig, rate) - sig*sqrt(T);
}

double EuroCall::price_by_BS(double spot, double sig, double rate) {
    double first = spot * N(d_plus(spot, sig, rate)); 
    return first - K*exp(-rate*T) * N(d_minus(spot, sig, rate)); 
}

double EuroCall::vega_by_BS(double spot, double sig, double rate) {
    double pi = 4.0 * atan(1.0);
    double dp = d_plus(spot, sig, rate);
    return spot * exp(-dp*dp/2) * sqrt(T) / sqrt(2.0*pi);
}

double EuroCallPricer::value(double sigma) {
    return ecall.price_by_BS(spot, sigma, rate) - mvalue;
}

double EuroCallPricer::deriv(double sigma) {
    return ecall.vega_by_BS(spot, sigma, rate);
}

double EuroCallPricer::newtonraph_sigma(double value, double eps) {
    mvalue = value;
    return newton_raphson_t(*this, 0.0, 1.0, eps);
}

double EuroCallPricer::bisection_sigma(double value, double eps) {
    mvalue = value;
    return bisection_t(*this, 0.0, 1.0, eps);
}
